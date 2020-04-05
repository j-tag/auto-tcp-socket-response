#ifndef AUTOSOCKET_HPP
#define AUTOSOCKET_HPP

#include <QObject>
#include <QScopedPointer>

#include "includes/TcpSocketClient.hpp"

class AutoSocket : public QObject
{
    Q_OBJECT
public:
    explicit AutoSocket(QObject *parent = nullptr);
    void log(const char *data);
    void log(const QString &strData);
    TcpSocketClient *getTcpSocketClient() const;

signals:
    void logMessage(const char *data);

private:
    QScopedPointer<TcpSocketClient> m_pTcpSocketClient;
};

// Main app object
extern AutoSocket as;

#endif // AUTOSOCKET_HPP
