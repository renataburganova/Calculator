#ifndef KEYBOARDWINDOW_H
#define KEYBOARDWINDOW_H

#include <QDialog>
#include <QToolButton>
#include <QLineEdit>

namespace Ui {
class KeyboardWindow;
}

class Button : public QToolButton
{
    Q_OBJECT

public:
    explicit Button(const QString &text, QWidget *parent = nullptr);

    QSize sizeHint() const;
};

class KeyboardWindow : public QDialog
{
    Q_OBJECT

public:
    KeyboardWindow(QWidget *parent = nullptr);
    ~KeyboardWindow();

private:    
    Button *createButton(const QString &text, void (KeyboardWindow::*member)());

    Ui::KeyboardWindow *ui;
    QLineEdit *display;
    Button *letterButtons[33];

private slots:
    void buttonClicked();
};

#endif // KEYBOARD_H
