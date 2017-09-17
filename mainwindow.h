#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStackedWidget>

namespace Ui {
class MainWindow;
class SystemWindow;
}

class MainWindow : public QStackedWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    const Ui::MainWindow* getUi(){
        return ui;
    }

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
