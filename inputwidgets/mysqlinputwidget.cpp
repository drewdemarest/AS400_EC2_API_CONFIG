#include "mysqlinputwidget.h"
#include "ui_mysqlinputwidget.h"

MySQLInputWidget::MySQLInputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MySQLInputWidget)
{
    ui->setupUi(this);
    connect(ui->sslCheckBox, &QCheckBox::toggled, this, &MySQLInputWidget::sslCheckBoxChanged);
    connect(ui->commitSettingsButton, &QPushButton::pressed, this, &MySQLInputWidget::saveSettings);
    connect(ui->loadSettingsButton, &QPushButton::pressed, this, &MySQLInputWidget::loadSettings);
}

MySQLInputWidget::~MySQLInputWidget()
{
    delete ui;
}

void MySQLInputWidget::sslCheckBoxChanged(bool checked)
{
    ui->caFileLineEdit->setEnabled(checked);
    ui->caFileBrowseButton->setEnabled(checked);
    ui->clientCertLineEdit->setEnabled(checked);
    ui->clientCertBrowseButton->setEnabled(checked);
    ui->clientKeyLineEdit->setEnabled(checked);
    ui->clientKeyBrowseButton->setEnabled(checked);
}

void MySQLInputWidget::saveSettings()
{
    mySQLSettings_["password"] =        ui->passwordLineEdit->text();
    mySQLSettings_["userName"] =        ui->usernameLineEdit->text();
    mySQLSettings_["usingSSL"] =        ui->sslCheckBox->isChecked();
    //mySQLSettings_["databaseName"] = databaseName;
    mySQLSettings_["hostName"] =        ui->hostnameLineEdit->text();
    mySQLSettings_["caStr"] =           ui->caFileLineEdit->text();
    mySQLSettings_["clientKeyStr"] =    ui->clientKeyLineEdit->text();
    mySQLSettings_["clientCertStr"] =   ui->clientCertLineEdit->text();
    settings_.saveSettings(QFile(dbPath_), mySQLSettings_);
}

void MySQLInputWidget::loadSettings()
{
    mySQLSettings_ = settings_.loadSettings(QFile(dbPath_), mySQLSettings_);
    ui->passwordLineEdit->setText(mySQLSettings_["password"].toString());
    ui->usernameLineEdit->setText(mySQLSettings_["userName"].toString());
    //mySQLSettings_["databaseName"] = databaseName;
    ui->sslCheckBox->setChecked(mySQLSettings_["usingSSL"].toString().toInt());
    ui->hostnameLineEdit->setText(mySQLSettings_["hostName"].toString());
    ui->caFileLineEdit->setText(mySQLSettings_["caStr"].toString());
    ui->clientKeyLineEdit->setText(mySQLSettings_["clientKeyStr"].toString());
    ui->clientCertLineEdit->setText(mySQLSettings_["clientCertStr"].toString());
}
