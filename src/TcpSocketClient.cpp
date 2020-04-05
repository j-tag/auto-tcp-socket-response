#include "includes/AutoSocket.hpp"

TcpSocketClient::TcpSocketClient(QObject *parent) : QObject(parent), m_tcpSocket(QTcpSocket(this))
{
    connect(&this->m_tcpSocket, &QTcpSocket::connected, this, &TcpSocketClient::onConnected);
    connect(&this->m_tcpSocket, &QTcpSocket::disconnected, this, &TcpSocketClient::onDisconnected);
    connect(&this->m_tcpSocket, &QTcpSocket::bytesWritten, this, &TcpSocketClient::onBytesWritten);
    connect(&this->m_tcpSocket, &QTcpSocket::readyRead, this, &TcpSocketClient::onReadyRead);
    connect(&this->m_tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &TcpSocketClient::onError);
}

void TcpSocketClient::connectToHost(const QString &strAddress, quint16 port)
{
    this->m_tcpSocket.connectToHost(strAddress, port);
}

void TcpSocketClient::disconnectFromHost()
{
    this->m_tcpSocket.disconnectFromHost();
}

void TcpSocketClient::onConnected()
{
    emit this->connected();
    as.log("Connected to TCP socket.");
}

void TcpSocketClient::onDisconnected()
{
    emit this->disconnected();
    as.log("Disconnected from TCP socket.");
}

void TcpSocketClient::onBytesWritten(qint64 bytes)
{
    as.log("Written " + QString::number(bytes) + " to TCP socket.");
}

void TcpSocketClient::onReadyRead()
{
    const char *data = this->m_tcpSocket.readAll();
    as.log(data);
}

void TcpSocketClient::onError(QAbstractSocket::SocketError /*error*/)
{
    emit this->disconnected();
    as.log(this->m_tcpSocket.errorString());
}
