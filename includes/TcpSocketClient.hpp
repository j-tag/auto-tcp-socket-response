#ifndef TCPSOCKETCLIENT_HPP
#define TCPSOCKETCLIENT_HPP

#include <QObject>
#include <QtNetwork>

class TcpSocketClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocketClient(QObject *parent = nullptr);
    void connectToHost(const QString &strAddress, quint16 port);
    void disconnectFromHost();
    void setAutomaticRequestResponse(const QString &strRequest, const QString &strResponse);
    void sendMessage(const char *data);

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
    QTcpSocket m_tcpSocket;
    QString m_strRequest;
    QByteArray m_byteArrayResponse;
};

#endif // TCPSOCKETCLIENT_HPP
