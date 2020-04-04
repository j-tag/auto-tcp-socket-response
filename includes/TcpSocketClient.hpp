#ifndef TCPSOCKETCLIENT_HPP
#define TCPSOCKETCLIENT_HPP

#include <QObject>

class TcpSocketClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocketClient(QObject *parent = nullptr);

signals:

};

#endif // TCPSOCKETCLIENT_HPP
