#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMessageBox>

#include "myitemlist.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent* keyEvent);

signals:

private:
    qreal width_, height_;
    MyItemList* myItemList_;
    QPushButton* add_btn_;
    QPushButton* set_grid_btn_;
    QWidget* mainWidget_;
    QVBoxLayout* vLayout_;
    QHBoxLayout* hTopLayout_;
    QLineEdit* descriptionLine_;
    QLineEdit* nameLine_;
    QGraphicsView* myView_;
    QLabel* label_;

    void setButton_();

    void setLayout_();

    void setItemsGrid_();

    void setLines_();

    void addNewItem_(qreal x, qreal y);

};

#endif // MAINWINDOW_H
