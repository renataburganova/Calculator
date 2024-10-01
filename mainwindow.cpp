#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , loginWindow(new LoginWindow(this))
    , keyboardWindow(new KeyboardWindow(this))
    , isAuthenticated(false)
{
    ui->setupUi(this);

    setFixedSize(225, 120);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete loginWindow;
    delete keyboardWindow;
}

void MainWindow::on_mainLoginButton_clicked()
{
    if (!isAuthenticated) {
        if (loginWindow->exec() == QDialog::Accepted) {
            isAuthenticated = true;
            ui->mainLoginButton->setText("Выход");
        }
    } else {
        isAuthenticated = false;
        ui->mainLoginButton->setText("Вход");
    }
}

void MainWindow::on_startButton_clicked()
{
    if (isAuthenticated) {
        keyboardWindow->show();
    } else {
        QMessageBox::warning(this, "Ошибка", "Необходимо авторизоваться для начала работы.");
    }
}
