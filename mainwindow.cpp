#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->as400SettingsGrid->addWidget(as400Input);
    ui->importScheduleGrid->addWidget(schdeuleInput);
    ui->mySQLSettingsGrid->addWidget(mysqlInput);
}

MainWindow::~MainWindow()
{
    delete ui;
}
