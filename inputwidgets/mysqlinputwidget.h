#ifndef MYSQLINPUTWIDGET_H
#define MYSQLINPUTWIDGET_H

#include "json_settings/jsonsettings.h"
#include <QWidget>

namespace Ui {
class MySQLInputWidget;
}

class MySQLInputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MySQLInputWidget(QWidget *parent = 0);
    ~MySQLInputWidget();

private slots:
    void sslCheckBoxChanged(bool checked);
    void saveSettings();
    void loadSettings();

private:
    Ui::MySQLInputWidget *ui;
    QString dbPath_ = qApp->applicationDirPath() + "/mysqlsettings.db";
    JsonSettings settings_;
    QJsonObject mySQLSettings_ =    {{"caStr",           QJsonValue()},
                                     {"usingSSL",        QJsonValue()},
                                     {"clientKeyStr",    QJsonValue()},
                                     {"clientCertStr",   QJsonValue()},
                                     {"hostName",        QJsonValue()},
                                     {"databaseName",    QJsonValue()},
                                     {"userName",        QJsonValue()},
                                     {"password",        QJsonValue()}};
};

#endif // MYSQLINPUTWIDGET_H
