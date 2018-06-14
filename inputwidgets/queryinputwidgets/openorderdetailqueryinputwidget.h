#ifndef OPENORDERDETAILQUERYINPUTWIDGET_H
#define OPENORDERDETAILQUERYINPUTWIDGET_H

#include "json_settings/jsonsettings.h"
#include <QWidget>

namespace Ui {
class OpenOrderDetailQueryInputWidget;
}

class OpenOrderDetailQueryInputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OpenOrderDetailQueryInputWidget(QWidget *parent = 0);
    ~OpenOrderDetailQueryInputWidget();

private slots:
    void dailyTimeImportCheckChanged(bool checked);
    void intervalImportCheckChanged(bool checked);
    void saveSettings();
    void loadSettings();

private:
    Ui::OpenOrderDetailQueryInputWidget *ui;
    JsonSettings settings_;
    QString dbPath_ = qApp->applicationDirPath() + "/openOrderDetailQuery.db";
    QJsonObject querySettings_ =    {{"millisecondInterval", QJsonValue()},
                                     {"dailyUploadTime",     QJsonValue()},
                                     {"chunkSize",           QJsonValue()},
                                     {"usingUploadInterval", QJsonValue()},
                                     {"usingUploadDaily",    QJsonValue()}};
};

#endif // OPENORDERDETAILQUERYINPUTWIDGET_H
