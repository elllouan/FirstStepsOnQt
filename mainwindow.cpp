#include "mainwindow.h"

#include <QSlider>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    mainWidget_ = new QWidget(this);
    width_ = 600;
    height_ = 600;

    setLines_();
    setItemsGrid_();
    setButton_();
    setLayout_();

    setCentralWidget(mainWidget_);
    resize(width_,height_);
}

void MainWindow::keyPressEvent(QKeyEvent *keyEvent)
{
    if(keyEvent->key() == Qt::Key_Enter) { label_->setText(label_->text() + '\n'); }
    else if(keyEvent->key() == Qt::Key_Escape) { descriptionLine_->setText(""); }

}

void MainWindow::addNewItem_(qreal x, qreal y)
{
    myItemList_->addRect(x,y,50,50);
}

void MainWindow::setButton_()
{
    add_btn_ = new QPushButton(mainWidget_); // allows to add Items to the Grid
    add_btn_->setText("Add Item");
    add_btn_->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    set_grid_btn_ = new QPushButton(mainWidget_); // allows to rearange the Grid
    set_grid_btn_->setText("Change Grid");

    QObject::connect(set_grid_btn_, SIGNAL(clicked(bool)), myItemList_, SLOT(rearangeGrid(bool)));
}

void MainWindow::setLayout_()
{
    vLayout_ = new QVBoxLayout(mainWidget_);
//    vLayout_->setSpacing(0);
//    vLayout_->setContentsMargins(0,0,0,0);

    QVBoxLayout* btns_layout = new QVBoxLayout(mainWidget_);
    btns_layout->addWidget(add_btn_);
    btns_layout->addWidget(set_grid_btn_);

    hTopLayout_ = new QHBoxLayout(mainWidget_);

    hTopLayout_->addLayout(btns_layout);
    hTopLayout_->addWidget(nameLine_);
    hTopLayout_->addWidget(descriptionLine_);

    QVBoxLayout* viewLayout = new QVBoxLayout(mainWidget_);
    viewLayout->addWidget(myView_);

    vLayout_->addLayout(hTopLayout_);
    vLayout_->addWidget(myView_);

    mainWidget_->setLayout(vLayout_);
}

void MainWindow::setItemsGrid_()
{
    myView_ = new QGraphicsView(mainWidget_);
    QPointF upperLeftViewPoint = myView_->mapToScene(0,0); // set the origin of the scene at the same location as the scene
    QSize viewSize(this->width_, this->height_);

    myItemList_ = new MyItemList(upperLeftViewPoint, viewSize);
    myView_->setScene(myItemList_);

    /* !!! allow to set all sliders to their minimum value !!! */
    myView_->setAlignment(Qt::AlignLeft & Qt::AlignTop);
    myView_->centerOn(0,0);

}

void MainWindow::setLines_()
{
    nameLine_ = new QLineEdit(mainWidget_);
    descriptionLine_ = new QLineEdit(mainWidget_);

    nameLine_->setPlaceholderText("Enter a name");
    nameLine_->setReadOnly(false);
    nameLine_->setFixedWidth(this->width_/6);

    descriptionLine_->setPlaceholderText("Enter a description ...");
    descriptionLine_->setMinimumWidth(this->width_/2);
    descriptionLine_->setReadOnly(false);
}
