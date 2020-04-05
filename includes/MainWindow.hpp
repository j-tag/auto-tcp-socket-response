#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

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
    void onLogMessage(const char* data);
    void onConnected();
    void onDisconnected();
    void on_pushButton_connection_clicked();

    void on_pushButton_response_save_clicked();

private:
    void loadSettings();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
