#include "includes/AutoSocket.hpp"

AutoSocket::AutoSocket(QObject *parent) : QObject(parent), m_pTcpSocketClient(new TcpSocketClient(this)) {

}

void AutoSocket::log(const char *data) {
  emit
  this->logMessage(data);
}

void AutoSocket::log(const QString &strData) {
  emit
  this->logMessage(strData.toUtf8());
}

TcpSocketClient *AutoSocket::getTcpSocketClient() const {
  return this->m_pTcpSocketClient.get();
}

// Main app object
AutoSocket as;
