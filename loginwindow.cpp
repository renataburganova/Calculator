#include "loginwindow.h"
#include <QMessageBox>
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
    , authenticated(false)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

bool LoginWindow::isAuthenticated() const
{
    return authenticated;
}

void LoginWindow::on_authLoginButton_clicked()
{
    QString login = ui->loginLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    // Простая проверка логина и пароля
    if (login == "renata" && password == "5377") {
        authenticated = true;
        accept(); // Закрываем окно с результатом успеха
    } else {
        QMessageBox::warning(this, "Ошибка", "Неверный логин или пароль");
    }
}
