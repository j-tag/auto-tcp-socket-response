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

signals:

private slots:
    void onConnected();
    void onDisconnected();
    void onBytesWritten(qint64 bytes);
    void onReadyRead();

private:
    QTcpSocket m_tcpSocket;
};

#endif // TCPSOCKETCLIENT_HPP
