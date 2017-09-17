#include "systemwindow.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SystemWindow system_window;
    MainWindow main_window;
    system_window.show();
    main_window.show();

    return a.exec();
}
