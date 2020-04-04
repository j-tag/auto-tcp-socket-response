#include "includes/MainWindow.hpp"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_tcpClient(TcpSocketClient(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_connection_clicked()
{
    const auto ip = this->ui->lineEdit_ip->text();
    const auto port = this->ui->lineEdit_port->text().toUInt();

    this->m_tcpClient.connectToHost(ip, port);

    // TODO: Save in settings
}
