#include "customerchainqueryinputwidget.h"
#include "ui_customerchainqueryinputwidget.h"

CustomerChainQueryInputWidget::CustomerChainQueryInputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerChainQueryInputWidget)
{
    ui->setupUi(this);
    connect(ui->importDailyCheckBox, &QCheckBox::toggled, this, &CustomerChainQueryInputWidget::dailyTimeImportCheckChanged);
    connect(ui->importIntervalCheckBox, &QCheckBox::toggled, this, &CustomerChainQueryInputWidget::intervalImportCheckChanged);
    connect(ui->commitSettingsButton, &QPushButton::pressed, this, &CustomerChainQueryInputWidget::saveSettings);
    connect(ui->loadExistingSettingsButton, &QPushButton::pressed, this, &CustomerChainQueryInputWidget::loadSettings);

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
    querySettings_["millisecondInterval"]   = QString::number(ui->importIntervalSpinBox->value());
    querySettings_["dailyUploadTime"]       = ui->importTimeEdit->time().toString(Qt::ISODate);
    querySettings_["chunkSize"]             = QString::number(ui->chunkSizeSpinBox->value());
    querySettings_["usingUploadInterval"]   = ui->importIntervalCheckBox->isChecked();
    querySettings_["usingUploadDaily"]      = ui->importDailyCheckBox->isChecked();

    settings_.saveSettings(QFile(dbPath_), querySettings_);
}

void CustomerChainQueryInputWidget::loadSettings()
{
    querySettings_ = settings_.loadSettings(QFile(dbPath_), querySettings_);

    ui->importIntervalSpinBox->setValue(querySettings_["millisecondInterval"].toString().toInt());
    ui->importTimeEdit->setTime(QTime::fromString(querySettings_["dailyUploadTime"].toString(), Qt::ISODate));
    ui->chunkSizeSpinBox->setValue(querySettings_["chunkSize"].toString().toInt());
    ui->importIntervalCheckBox->setChecked(querySettings_["usingUploadInterval"].toString().toInt());
    ui->importDailyCheckBox->setChecked(querySettings_["usingUploadDaily"].toString().toInt());
}

