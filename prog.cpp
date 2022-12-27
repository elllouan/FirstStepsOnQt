#include <QApplication> // entry point of our app
#include <QLabel>

#include "mainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
//    QLabel* label = new QLabel("HelloWorld !");
//    label->show();

    return app.exec();
}
