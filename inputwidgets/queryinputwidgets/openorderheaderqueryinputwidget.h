#ifndef OPENORDERHEADERQUERYINPUTWIDGET_H
#define OPENORDERHEADERQUERYINPUTWIDGET_H

#include "json_settings/jsonsettings.h"
#include <QWidget>

namespace Ui {
class OpenOrderHeaderQueryInputWidget;
}

class OpenOrderHeaderQueryInputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OpenOrderHeaderQueryInputWidget(QWidget *parent = 0);
    ~OpenOrderHeaderQueryInputWidget();

private slots:
    void dailyTimeImportCheckChanged(bool checked);
    void intervalImportCheckChanged(bool checked);
    void saveSettings();
    void loadSettings();

private:
    Ui::OpenOrderHeaderQueryInputWidget *ui;
    JsonSettings settings_;

    QString dbPath_ = qApp->applicationDirPath() + "/openOrderHeaderQuery.db";
    QJsonObject querySettings_ =   {{"millisecondInterval",    QJsonValue()},
                                    {"dailyUploadTime",         QJsonValue()},
                                    {"chunkSize",               QJsonValue()},
                                    {"usingUploadInterval",     QJsonValue()},
                                    {"usingUploadDaily",        QJsonValue()}};
};

#endif // OPENORDERHEADERQUERYINPUTWIDGET_H
