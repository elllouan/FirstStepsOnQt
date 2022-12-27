#include "custombutton.h"

CustomButton::CustomButton(QWidget* parent) :
QPushButton(parent)
{
    setText("GO !");
    resize(100,100);
    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
}

void
CustomButton::sayHello()
{
    setText("Hello !");
}

void
CustomButton::openNewMessage()
{
    std::cout << "New Message.\n";
    QMessageBox::information(this, "Information", "You clicked on a button !");
}

void
CustomButton::setBehavior(int i) const
{
    switch (i) {
    case 1:
        connect(this, SIGNAL(clicked(bool)), this, SLOT(openNewMessage()));
        break;
    case 2:
        connect(this, SIGNAL(clicked(bool)), this, SLOT(sayHello()));
    default:
        break;
    }

}

CustomButton::~CustomButton()
{
    std::cout << "~CustomButton()\n";
}
