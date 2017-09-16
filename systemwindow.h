#ifndef SYSTEMWINDOW_H
#define SYSTEMWINDOW_H

#include <QMainWindow>

namespace Ui {
class SystemWindow;
}

class SystemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemWindow(QWidget *parent = 0);
    ~SystemWindow();

private:
    Ui::SystemWindow *ui;
};

#endif // SYSTEMWINDOW_H
