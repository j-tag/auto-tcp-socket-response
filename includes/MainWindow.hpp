#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "TcpSocketClient.hpp"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_connection_clicked();

private:
    Ui::MainWindow *ui;
    TcpSocketClient m_tcpClient;
};
#endif // MAINWINDOW_HPP
