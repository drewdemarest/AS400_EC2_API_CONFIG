#ifndef CUSTOMERCHAINQUERYINPUTWIDGET_H
#define CUSTOMERCHAINQUERYINPUTWIDGET_H

#include "json_settings/jsonsettings.h"
#include <QWidget>

namespace Ui {
class CustomerChainQueryInputWidget;
}

class CustomerChainQueryInputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerChainQueryInputWidget(QWidget *parent = 0);
    ~CustomerChainQueryInputWidget();

private slots:
    void dailyTimeImportCheckChanged(bool checked);
    void intervalImportCheckChanged(bool checked);
    void saveSettings();
    void loadSettings();

private:
    Ui::CustomerChainQueryInputWidget *ui;
    JsonSettings settings_;
    QString dbPath_ = qApp->applicationDirPath() + "/custChainQuery.db";
    QJsonObject querySettings_ =    {{"millisecondInterval", QJsonValue()},
                                     {"dailyUploadTime",     QJsonValue()},
                                     {"chunkSize",           QJsonValue()},
                                     {"usingUploadInterval", QJsonValue()},
                                     {"usingUploadDaily",    QJsonValue()}};
};

#endif // CUSTOMERCHAINQUERYINPUTWIDGET_H
