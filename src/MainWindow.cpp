#include "includes/AutoSocket.hpp"
#include "includes/MainWindow.hpp"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&as, &AutoSocket::logMessage, this, &MainWindow::onLogMessage);

    const auto tcpSocketClient = as.getTcpSocketClient();
    connect(tcpSocketClient, &TcpSocketClient::connected, this, &MainWindow::onConnected);
    connect(tcpSocketClient, &TcpSocketClient::disconnected, this, &MainWindow::onDisconnected);

    this->loadSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLogMessage(const char *data)
{
    this->ui->plainTextEdit_log->appendPlainText(data);
}

void MainWindow::onConnected()
{
    this->ui->pushButton_connection->setText("Disconnect");
    this->ui->pushButton_connection->setEnabled(true);
}

void MainWindow::onDisconnected()
{
    this->ui->pushButton_connection->setText("Connect");
    this->ui->pushButton_connection->setEnabled(true);
}


void MainWindow::on_pushButton_connection_clicked()
{
    const auto buttonText = this->ui->pushButton_connection->text();

    if(buttonText == "Connect") {
        // Connect

        this->ui->pushButton_connection->setText("Connecting ...");
        this->ui->pushButton_connection->setEnabled(false);

        const auto ip = this->ui->lineEdit_ip->text();
        const auto port = this->ui->lineEdit_port->text().toUInt();

        as.getTcpSocketClient()->connectToHost(ip, port);

        // Save settings
        QSettings settings(this);
        settings.setValue("ip", ip);
        settings.setValue("port", port);

    } else if(buttonText == "Disconnect") {
        // Disconnect

        this->ui->pushButton_connection->setText("Disconnecting ...");
        this->ui->pushButton_connection->setEnabled(false);

        as.getTcpSocketClient()->disconnectFromHost();
    }

}

void MainWindow::loadSettings()
{
    QSettings settings(this);
    const auto ip = settings.value("ip").toString();
    const auto port = settings.value("port").toString();

    this->ui->lineEdit_ip->setText(ip);
    this->ui->lineEdit_port->setText(port);
}
