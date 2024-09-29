#include "keyboardwindow.h"
#include "ui_keyboardwindow.h"

#include <QGridLayout>


KeyboardWindow::KeyboardWindow(QWidget *parent):
    QDialog(parent), ui(new Ui::KeyboardWindow)
{
    ui->setupUi(this);

    display = new QLineEdit("");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignLeft);
    display->setMaxLength(30);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    QStringList russianLetters = {"А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я"};

    for (int i = 0; i < 33; ++i)
        letterButtons[i] = createButton(russianLetters[i], &KeyboardWindow::buttonClicked);


    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(display, 0, 0, 1, 11);

    for (int i = 0; i < 33; ++i) {
        int row = (i / 11) + 1;
        int column = i % 11;
        mainLayout->addWidget(letterButtons[i], row, column);
    }

    setLayout(mainLayout);

    setWindowTitle(tr("Keyboard"));
}

KeyboardWindow::~KeyboardWindow()
{
    delete ui;
}

Button *KeyboardWindow::createButton(const QString &text, void (KeyboardWindow::*member)())
{
    Button *button = new Button(text);
    connect(button, &QToolButton::clicked, this, member);
    return button;
}

void KeyboardWindow::buttonClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());

    if (!clickedButton)
        return;

    QString currentText = display->text();
    currentText += clickedButton->text();
    display->setText(currentText);
}


Button::Button(const QString &text, QWidget *parent)
    : QToolButton(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setText(text);
}

QSize Button::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 20;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
