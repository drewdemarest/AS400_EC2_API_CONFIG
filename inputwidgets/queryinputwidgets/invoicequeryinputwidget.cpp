#include "invoicequeryinputwidget.h"
#include "ui_invoicequeryinputwidget.h"

InvoiceQueryInputWidget::InvoiceQueryInputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InvoiceQueryInputWidget)
{
    ui->setupUi(this);
    connect(ui->importDailyCheckBox, &QCheckBox::toggled, this, &InvoiceQueryInputWidget::dailyTimeImportCheckChanged);
    connect(ui->importIntervalCheckBox, &QCheckBox::toggled, this, &InvoiceQueryInputWidget::intervalImportCheckChanged);
    connect(ui->commitSettingsButton, &QPushButton::pressed, this, &InvoiceQueryInputWidget::saveSettings);
    connect(ui->loadExistingSettingsButton, &QPushButton::pressed, this, &InvoiceQueryInputWidget::loadSettings);

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

void InvoiceQueryInputWidget::saveSettings()
{
    invoiceQuerySettings_["millisecondInterval"] = QString::number(ui->importIntervalSpinBox->value());
    invoiceQuerySettings_["dailyUploadTime"] = ui->importTimeEdit->time().toString(Qt::ISODate);
    invoiceQuerySettings_["invoiceDaysPrior"] = QString::number(ui->daysPrevSpinBox->value());
    invoiceQuerySettings_["chunkSize"] = QString::number(ui->chunkSizeSpinBox->value());
    invoiceQuerySettings_["usingUploadInterval"] = ui->importIntervalCheckBox->isChecked();
    invoiceQuerySettings_["usingUploadDaily"] = ui->importDailyCheckBox->isChecked();

    settings_.saveSettings(QFile(dbPath_), invoiceQuerySettings_);
}

void InvoiceQueryInputWidget::loadSettings()
{
    invoiceQuerySettings_ = settings_.loadSettings(QFile(dbPath_), invoiceQuerySettings_);

    ui->importIntervalSpinBox->setValue(invoiceQuerySettings_["millisecondInterval"].toString().toInt());
    ui->importTimeEdit->setTime(QTime::fromString(invoiceQuerySettings_["dailyUploadTime"].toString(), Qt::ISODate));
    ui->daysPrevSpinBox->setValue(invoiceQuerySettings_["invoiceDaysPrior"].toString().toInt());
    ui->chunkSizeSpinBox->setValue(invoiceQuerySettings_["chunkSize"].toString().toInt());
    ui->importIntervalCheckBox->setChecked(invoiceQuerySettings_["usingUploadInterval"].toString().toInt());
    ui->importDailyCheckBox->setChecked(invoiceQuerySettings_["usingUploadDaily"].toString().toInt());
}
