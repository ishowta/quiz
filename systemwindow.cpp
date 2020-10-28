#include "systemwindow.h"
#include "ui_systemwindow.h"

#include "ui_mainwindow.h"

SystemWindow::SystemWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SystemWindow)
{
    ui->setupUi(this);
    main_window = new MainWindow(parent);
    createMW();
    main_window->show();

    // メンバー設定画面生成
    auto createMemberSetting = [this](int team, QGridLayout* layout, int player_number, int row, int column){
        QLabel* name_label = new QLabel("player"+QString::number(player_number+1));
        QSpinBox* point = new QSpinBox();
        point->setMinimum(-999);
        point->setMaximum(999);
        QLineEdit* name = new QLineEdit();
        layout->addWidget(name_label,row, column);
        layout->addWidget(point,row, column + 1);
        layout->addWidget(name,row, column + 2);
        connect(point, SIGNAL(valueChanged(int)), this, SLOT(updateMW()));
        connect(name, SIGNAL(textChanged(QString)), this, SLOT(updateMW()));
        switch(team){
        case 0:
            break;
        case 1:
            team1_names_systen_widget.at(player_number) = name;
            team1_points_systen_widget.at(player_number) = point;
        case 2:
            team2_names_systen_widget.at(player_number) = name;
            team2_points_systen_widget.at(player_number) = point;
        }
    };

    // チームメンバーの設定画面作成
    for(int i=0;i<MAX_TEAM_MEMBER_NUM;++i){
        createMemberSetting(1, ui->team1_area, i, i<4?0:1,(i<4?0:-12) + i*3);
        createMemberSetting(2, ui->team2_area, i, i<4?0:1,(i<4?0:-12) + i*3);
    }

    // チーム情報の更新コネクト
    connect(this->ui->team1_playerCount, SIGNAL(valueChanged(int)), this, SLOT(createMW()));
    connect(this->ui->team2_playerCount, SIGNAL(valueChanged(int)), this, SLOT(createMW()));
    connect(this->ui->team1_point, SIGNAL(valueChanged(int)), this, SLOT(updateMW()));
    connect(this->ui->team2_point, SIGNAL(valueChanged(int)), this, SLOT(updateMW()));
    connect(this->ui->team1_name, SIGNAL(textChanged(QString)), this, SLOT(updateMW()));
    connect(this->ui->team2_name, SIGNAL(textChanged(QString)), this, SLOT(updateMW()));
    connect(this->ui->mode1, SIGNAL(toggled(bool)), this, SLOT(switchPage(bool)));
    connect(this->ui->mode2, SIGNAL(toggled(bool)), this, SLOT(switchPage(bool)));
    connect(this->ui->mode3, SIGNAL(toggled(bool)), this, SLOT(switchPage(bool)));
    connect(this->ui->mode4, SIGNAL(toggled(bool)), this, SLOT(switchPage(bool)));
    connect(this->ui->mode5, SIGNAL(toggled(bool)), this, SLOT(switchPage(bool)));
    connect(this->ui->mode6, SIGNAL(toggled(bool)), this, SLOT(switchPage(bool)));
    connect(this->ui->mode7, SIGNAL(toggled(bool)), this, SLOT(switchPage(bool)));
}

SystemWindow::~SystemWindow()
{
    delete ui;
}

void SystemWindow::switchPage(bool){
    if(this->ui->mode1->isChecked()) main_window->setCurrentIndex(0);
    if(this->ui->mode2->isChecked()) main_window->setCurrentIndex(1);
    if(this->ui->mode3->isChecked()) main_window->setCurrentIndex(2);
    if(this->ui->mode4->isChecked()) main_window->setCurrentIndex(3);
    if(this->ui->mode5->isChecked()) main_window->setCurrentIndex(4);
    if(this->ui->mode6->isChecked()) main_window->setCurrentIndex(5);
    if(this->ui->mode7->isChecked()) main_window->setCurrentIndex(6);
}

void SystemWindow::createMW()
{
    // メンバー表示生成
    auto createMemberSetting = [this](int team, QLayout* layout_point, QLayout* layout_name, int player_number){
        QLabel* name = new QLabel();
        QLabel* point = new QLabel();
        name->setFont(QFont("Noto Sans",50));
        point->setFont(QFont("Noto Sans",100));
        layout_point->addWidget(point);
        layout_name->addWidget(name);
        switch(team){
        case 0:
            break;
        case 1:
            team1_names_display_widget.at(player_number) = name;
            team1_points_display_widget.at(player_number) = point;
        case 2:
            team2_names_display_widget.at(player_number) = name;
            team2_points_display_widget.at(player_number) = point;
        }
    };

    // チームメンバーの表示作成
    QLayoutItem* child;
    while ((child = main_window->getUi()->TeamMembersPointPage_Team1NameArea->takeAt(0)) != 0){
        delete child->widget();
        delete child;
    }
    while ((child = main_window->getUi()->TeamMembersPointPage_Team1PointArea->takeAt(0)) != 0){
        delete child->widget();
        delete child;
    }
    while ((child = main_window->getUi()->TeamMembersPointPage_Team2NameArea->takeAt(0)) != 0){
        delete child->widget();
        delete child;
    }
    while ((child = main_window->getUi()->TeamMembersPointPage_Team2PointArea->takeAt(0)) != 0){
        delete child->widget();
        delete child;
    }
    for(int i=0;i<ui->team1_playerCount->value();++i){
        createMemberSetting(1, main_window->getUi()->TeamMembersPointPage_Team1NameArea, main_window->getUi()->TeamMembersPointPage_Team1PointArea, i);
    }
    for(int i=0;i<ui->team2_playerCount->value();++i){
        createMemberSetting(2, main_window->getUi()->TeamMembersPointPage_Team2NameArea, main_window->getUi()->TeamMembersPointPage_Team2PointArea, i);
    }

    updateMW();
}

void SystemWindow::updateMW()
{
    main_window->getUi()->TeamPointPage_Team1Point->setText(QString::number(ui->team1_point->value()));
    main_window->getUi()->TeamPointPage_Team2Point->setText(QString::number(ui->team2_point->value()));
    main_window->getUi()->TeamPointPage_Team1Name->setText(ui->team1_name->text());
    main_window->getUi()->TeamPointPage_Team2Name->setText(ui->team2_name->text());
    main_window->getUi()->TeamMembersPointPage_Team1Name->setText(ui->team1_name->text());
    main_window->getUi()->TeamMembersPointPage_Team2Name->setText(ui->team2_name->text());
    for(int i=0;i<ui->team1_playerCount->value();++i){
        team1_names_display_widget.at(i)->setText(team1_names_systen_widget.at(i)->text());
        team1_points_display_widget.at(i)->setText(team1_points_systen_widget.at(i)->text());
    }
    for(int i=0;i<ui->team2_playerCount->value();++i){
        team2_names_display_widget.at(i)->setText(team2_names_systen_widget.at(i)->text());
        team2_points_display_widget.at(i)->setText(team2_points_systen_widget.at(i)->text());
    }
}
