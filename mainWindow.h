#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout> // Layout that places Widgets vertically
#include <QHBoxLayout> // Layout that places Widgets vertically
#include <QImage>
#include "custombutton.h"

class MainWindow : public QMainWindow // equivalent to JFrame
{
    Q_OBJECT // for the MOC (Meta Object Compiler) , necessary when inheriting from a QObject

public:
    MainWindow(QWidget* parent=0);
    ~MainWindow();

    inline
    void addButton(CustomButton* btn) { buttons_.append(btn); }

private:
    QList<CustomButton*> buttons_; // equivalent to std::vector
    QVBoxLayout* vLayout_;
    QHBoxLayout* hLayout_;
    QImage* image_;
    QWidget* mainWidget_;
};

#endif // MAINWINDOW_H
