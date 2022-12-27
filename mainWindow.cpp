#include "mainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
QMainWindow(parent)
{
    std::cout << "New Window has been created.\n";
    setWindowTitle("BreakOut Game");
    resize(600,400);

    mainWidget_ = new QWidget(this);
    vLayout_ = new QVBoxLayout(this);
    hLayout_ = new QHBoxLayout(this);
    image_ = new QImage("shrek","png");

    for (int var = 0; var < 4; ++var) {
        buttons_.append(new CustomButton(mainWidget_)); // mainWidget_ is now the buttons parent
        if(var%2) { buttons_[var]->setBehavior(1); }
        else { buttons_[var]->setBehavior(2); }
        hLayout_->addWidget(buttons_[var]); // add each button to the Layout (vertical)
    }
    vLayout_->addLayout(hLayout_);
    vLayout_->addWidget(new CustomButton(mainWidget_));
    mainWidget_->setLayout(vLayout_);
    setCentralWidget(mainWidget_); // compulsory to add a Central Widget (JPanel)
}

MainWindow::~MainWindow()
{
    std::cout << "~MainWindow()\n";
}
