#include "systemwindow.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SystemWindow system_window;
    system_window.show();

    return a.exec();
}
