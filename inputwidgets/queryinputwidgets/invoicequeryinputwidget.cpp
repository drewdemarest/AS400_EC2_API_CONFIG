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
    querySettings_["millisecondInterval"] = QString::number(ui->importIntervalSpinBox->value());
    querySettings_["dailyUploadTime"] = ui->importTimeEdit->time().toString(Qt::ISODate);
    querySettings_["invoiceDaysPrior"] = QString::number(ui->daysPrevSpinBox->value());
    querySettings_["chunkSize"] = QString::number(ui->chunkSizeSpinBox->value());
    querySettings_["usingUploadInterval"] = ui->importIntervalCheckBox->isChecked();
    querySettings_["usingUploadDaily"] = ui->importDailyCheckBox->isChecked();

    settings_.saveSettings(QFile(dbPath_), querySettings_);
}

void InvoiceQueryInputWidget::loadSettings()
{
    querySettings_ = settings_.loadSettings(QFile(dbPath_), querySettings_);

    ui->importIntervalSpinBox->setValue(querySettings_["millisecondInterval"].toString().toInt());
    ui->importTimeEdit->setTime(QTime::fromString(querySettings_["dailyUploadTime"].toString(), Qt::ISODate));
    ui->daysPrevSpinBox->setValue(querySettings_["invoiceDaysPrior"].toString().toInt());
    ui->chunkSizeSpinBox->setValue(querySettings_["chunkSize"].toString().toInt());
    ui->importIntervalCheckBox->setChecked(querySettings_["usingUploadInterval"].toString().toInt());
    ui->importDailyCheckBox->setChecked(querySettings_["usingUploadDaily"].toString().toInt());
}
