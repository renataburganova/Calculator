#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    bool isAuthenticated() const;

private slots:
    void on_authLoginButton_clicked();

private:
    Ui::LoginWindow *ui;
    bool authenticated;
};

#endif // LOGINWINDOW_H
