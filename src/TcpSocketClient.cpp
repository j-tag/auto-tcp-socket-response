#include "includes/AutoSocket.hpp"

TcpSocketClient::TcpSocketClient(QObject *parent) : QObject(parent), m_tcpSocket(QTcpSocket(this)),
                                                    m_bIsHex(false) {
  connect(&this->m_tcpSocket, &QTcpSocket::connected, this, &TcpSocketClient::onConnected);
  connect(&this->m_tcpSocket, &QTcpSocket::disconnected, this, &TcpSocketClient::onDisconnected);
  connect(&this->m_tcpSocket, &QTcpSocket::bytesWritten, this, &TcpSocketClient::onBytesWritten);
  connect(&this->m_tcpSocket, &QTcpSocket::readyRead, this, &TcpSocketClient::onReadyRead);
  connect(&this->m_tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
          this, &TcpSocketClient::onError);
}

void TcpSocketClient::connectToHost(const QString &strAddress, quint16 port) {
  this->m_tcpSocket.connectToHost(strAddress, port);
}

void TcpSocketClient::disconnectFromHost() {
  this->m_tcpSocket.disconnectFromHost();
}

void TcpSocketClient::setAutomaticRequestResponse(const QString &strRequest, const QString &strResponse) {
  this->m_strRequest = strRequest;
  this->m_strResponse = strResponse;
  this->updateResponseByteArray();
}

void TcpSocketClient::sendMessage(const QByteArray &ba) {
  if (this->m_bIsHex) {
    as.log("Sending " + QString(ba.toHex()) + " to TCP socket.");
  } else {
    as.log("Sending " + QString(ba) + " to TCP socket.");
  }
  this->m_tcpSocket.write(ba);
  this->m_tcpSocket.flush();
}

void TcpSocketClient::setHexMode(bool hexMode) {
  this->m_bIsHex = hexMode;
  this->updateResponseByteArray();
}

void TcpSocketClient::onConnected() {
  emit this->connected();
  as.log("Connected to TCP socket.");
}

void TcpSocketClient::onDisconnected() {
  emit this->disconnected();
  as.log("Disconnected from TCP socket.");
}

void TcpSocketClient::onBytesWritten(qint64 bytes) {
  as.log("Written " + QString::number(bytes) + " bytes to TCP socket.");
}

void TcpSocketClient::onReadyRead() {
  const QByteArray data = this->m_tcpSocket.readAll();
  QString strData(this->m_bIsHex ? data.toHex() : data);
  const auto trimmedData = strData.trimmed();
  as.log(trimmedData);

  // Handle automatic response
  if (this->m_strRequest == trimmedData) {
    this->sendMessage(this->m_byteArrayResponse);
  }
}

void TcpSocketClient::onError(QAbstractSocket::SocketError /*error*/) {
  emit this->disconnected();
  as.log(this->m_tcpSocket.errorString());
}

void TcpSocketClient::updateResponseByteArray() {
  if (this->m_bIsHex) {
    this->m_byteArrayResponse = QByteArray::fromHex(this->m_strResponse.toLatin1());
  } else {
    this->m_byteArrayResponse = this->m_strResponse.toUtf8();
  }
}
