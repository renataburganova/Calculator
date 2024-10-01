#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginwindow.h"
#include "keyboardwindow.h"

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
    void on_mainLoginButton_clicked();
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    LoginWindow *loginWindow;
    KeyboardWindow *keyboardWindow;
    bool isAuthenticated;
};

#endif // MAINWINDOW_H
