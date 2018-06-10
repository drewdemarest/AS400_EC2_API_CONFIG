#include "customerchainqueryinputwidget.h"
#include "ui_customerchainqueryinputwidget.h"

CustomerChainQueryInputWidget::CustomerChainQueryInputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerChainQueryInputWidget)
{
    ui->setupUi(this);
    connect(ui->importDailyCheckBox, &QCheckBox::toggled, this, &CustomerChainQueryInputWidget::dailyTimeImportCheckChanged);
    connect(ui->importIntervalCheckBox, &QCheckBox::toggled, this, &CustomerChainQueryInputWidget::intervalImportCheckChanged);

    if(!ui->importIntervalCheckBox->isChecked() && !ui->importDailyCheckBox->isChecked())
    {
        ui->importIntervalSpinBox->setEnabled(false);
        ui->importTimeEdit->setEnabled(false);
    }
}

CustomerChainQueryInputWidget::~CustomerChainQueryInputWidget()
{
    delete ui;
}

void CustomerChainQueryInputWidget::dailyTimeImportCheckChanged(bool checked)
{
 if(checked)
 {
     ui->importIntervalCheckBox->setEnabled(false);
     ui->importIntervalSpinBox->setEnabled(false);
     ui->importTimeEdit->setEnabled(true);
 }
 else
 {
     ui->importIntervalCheckBox->setEnabled(true);
     ui->importIntervalSpinBox->setEnabled(true);
 }

 if(!ui->importIntervalCheckBox->isChecked() && !ui->importDailyCheckBox->isChecked())
 {
     ui->importIntervalSpinBox->setEnabled(false);
     ui->importTimeEdit->setEnabled(false);
 }
}

void CustomerChainQueryInputWidget::intervalImportCheckChanged(bool checked)
{
    if(checked)
    {
        ui->importDailyCheckBox->setEnabled(false);
        ui->importTimeEdit->setEnabled(false);
        ui->importIntervalSpinBox->setEnabled(true);
    }
    else
    {
        ui->importDailyCheckBox->setEnabled(true);
        ui->importTimeEdit->setEnabled(true);
    }

    if(!ui->importIntervalCheckBox->isChecked() && !ui->importDailyCheckBox->isChecked())
    {
        ui->importIntervalSpinBox->setEnabled(false);
        ui->importTimeEdit->setEnabled(false);
    }
}

void CustomerChainQueryInputWidget::saveSettings()
{

}

void CustomerChainQueryInputWidget::loadSettings()
{

}

