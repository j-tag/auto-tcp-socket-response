#ifndef TCPSOCKETCLIENT_HPP
#define TCPSOCKETCLIENT_HPP

#include <QObject>
#include <QtNetwork>

class TcpSocketClient : public QObject {
 Q_OBJECT
 public:
  explicit TcpSocketClient(QObject *parent = nullptr);
  void connectToHost(const QString &strAddress, quint16 port);
  void disconnectFromHost();
  void setAutomaticRequestResponse(const QString &strRequest, const QString &strResponse);
  void sendMessage(const QByteArray &ba);
  void setHexMode(bool hexMode);

 signals:
  void connected();
  void disconnected();

 private slots:
  void onConnected();
  void onDisconnected();
  void onBytesWritten(qint64 bytes);
  void onReadyRead();
  void onError(QAbstractSocket::SocketError error);

 private:
  void updateResponseByteArray();

 private:
  QTcpSocket m_tcpSocket;
  QString m_strRequest;
  QString m_strResponse;
  QByteArray m_byteArrayResponse;
  bool m_bIsHex;
};

#endif // TCPSOCKETCLIENT_HPP
