#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>
#include <QObject>
#include <QMessageBox>

#include <cstdio>
#include <iostream>

class CustomButton : public QPushButton
{
    Q_OBJECT

public:
    CustomButton(QWidget* parent=0);
    ~CustomButton();

    void
    setBehavior(int i) const;

public slots:
    void sayHello();
    void openNewMessage();

};

#endif // CUSTOMBUTTON_H
