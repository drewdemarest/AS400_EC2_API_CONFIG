#include "invoicequeryinputwidget.h"
#include "ui_invoicequeryinputwidget.h"

InvoiceQueryInputWidget::InvoiceQueryInputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InvoiceQueryInputWidget)
{
    ui->setupUi(this);
    connect(ui->importDailyCheckBox, &QCheckBox::toggled, this, &InvoiceQueryInputWidget::dailyTimeImportCheckChanged);
    connect(ui->importIntervalCheckBox, &QCheckBox::toggled, this, &InvoiceQueryInputWidget::intervalImportCheckChanged);

    if(!ui->importIntervalCheckBox->isChecked() && !ui->importDailyCheckBox->isChecked())
    {
        ui->importIntervalSpinBox->setEnabled(false);
        ui->importTimeEdit->setEnabled(false);
    }
}

InvoiceQueryInputWidget::~InvoiceQueryInputWidget()
{
    delete ui;
}

void InvoiceQueryInputWidget::dailyTimeImportCheckChanged(bool checked)
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

void InvoiceQueryInputWidget::intervalImportCheckChanged(bool checked)
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
