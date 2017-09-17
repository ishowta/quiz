#include <QtWebKitWidgets/QWebView>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "systemwindow.h"
#include "ui_systemwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add webview to kanji_multi_answers page
    QWebView *kma_webview = new QWebView();
    kma_webview->load(QUrl("http://google.com/"));
    ui->KanjiMultiAnswersPageLayout->addWidget(kma_webview);

    // Set default index
    this->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
