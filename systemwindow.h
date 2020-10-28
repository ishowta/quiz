#ifndef SYSTEMWINDOW_H
#define SYSTEMWINDOW_H

#include <iostream>
#include <vector>
#include <array>
#include <QMainWindow>
#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>

#include "mainwindow.h"

namespace Ui {
class SystemWindow;
}

class SystemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemWindow(QWidget *parent = 0);
    ~SystemWindow();

public slots:
    void createMW();
    void updateMW();
    void switchPage(bool tmp);

private:
    static constexpr int MAX_TEAM_MEMBER_NUM = 8;

    Ui::SystemWindow *ui;
    MainWindow *main_window;
    std::array<QSpinBox*, MAX_TEAM_MEMBER_NUM> team1_points_systen_widget;
    std::array<QLineEdit*, MAX_TEAM_MEMBER_NUM> team1_names_systen_widget;
    std::array<QSpinBox*, MAX_TEAM_MEMBER_NUM> team2_points_systen_widget;
    std::array<QLineEdit*, MAX_TEAM_MEMBER_NUM> team2_names_systen_widget;
    std::array<QLabel*, MAX_TEAM_MEMBER_NUM> team1_points_display_widget;
    std::array<QLabel*, MAX_TEAM_MEMBER_NUM> team1_names_display_widget;
    std::array<QLabel*, MAX_TEAM_MEMBER_NUM> team2_points_display_widget;
    std::array<QLabel*, MAX_TEAM_MEMBER_NUM> team2_names_display_widget;
};

#endif // SYSTEMWINDOW_H
