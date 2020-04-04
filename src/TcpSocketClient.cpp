#include "includes/TcpSocketClient.hpp"

TcpSocketClient::TcpSocketClient(QObject *parent) : QObject(parent), m_tcpSocket(QTcpSocket(this))
{

}

void TcpSocketClient::connectToHost(const QString &strAddress, quint16 port)
{
    connect(&this->m_tcpSocket, &QTcpSocket::connected, this, &TcpSocketClient::onConnected);
    connect(&this->m_tcpSocket, &QTcpSocket::disconnected, this, &TcpSocketClient::onDisconnected);
    connect(&this->m_tcpSocket, &QTcpSocket::bytesWritten, this, &TcpSocketClient::onBytesWritten);
    connect(&this->m_tcpSocket, &QTcpSocket::readyRead, this, &TcpSocketClient::onReadyRead);

    this->m_tcpSocket.connectToHost(strAddress, port);
}

void TcpSocketClient::onConnected()
{
    // TODO
}

void TcpSocketClient::onDisconnected()
{
    // TODO
}

void TcpSocketClient::onBytesWritten(qint64 /*bytes*/)
{
    // TODO
}

void TcpSocketClient::onReadyRead()
{
    // TODO
}
