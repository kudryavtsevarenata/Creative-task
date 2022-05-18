#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Calculator");
    w.setWindowIcon(QIcon("logarithm.png"));
    w.show();
    return a.exec();
}
