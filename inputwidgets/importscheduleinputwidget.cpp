#include "importscheduleinputwidget.h"
#include "ui_importscheduleinputwidget.h"

ImportScheduleInputWidget::ImportScheduleInputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImportScheduleInputWidget)
{
    ui->setupUi(this);
    ui->invoiceSettingsGrid->addWidget(invoiceInput);
    ui->customerChainSettingsGrid->addWidget(customerChainInput);
    ui->openOrderHeaderSettingsGrid->addWidget(openOrderHeaderInput);
    ui->openOrderDetailSettingsGrid->addWidget(openOrderDetailInput);
}

ImportScheduleInputWidget::~ImportScheduleInputWidget()
{
    delete ui;
}
