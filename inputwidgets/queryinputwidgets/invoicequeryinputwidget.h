#ifndef INVOICEQUERYINPUTWIDGET_H
#define INVOICEQUERYINPUTWIDGET_H

#include "json_settings/jsonsettings.h"
#include <QWidget>

namespace Ui {
class InvoiceQueryInputWidget;
}

class InvoiceQueryInputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InvoiceQueryInputWidget(QWidget *parent = 0);
    ~InvoiceQueryInputWidget();

private slots:
    void dailyTimeImportCheckChanged(bool checked);
    void intervalImportCheckChanged(bool checked);
    void saveSettings();
    void loadSettings();

private:
    Ui::InvoiceQueryInputWidget *ui;
    JsonSettings settings_;

    QString dbPath_ = qApp->applicationDirPath() + "/invoiceQuery.db";
    QJsonObject querySettings_ =   {{"millisecondInterval",    QJsonValue()},
                                    {"dailyUploadTime",         QJsonValue()},
                                    {"invoiceDaysPrior",        QJsonValue()},
                                    {"chunkSize",               QJsonValue()},
                                    {"usingUploadInterval",     QJsonValue()},
                                    {"usingUploadDaily",        QJsonValue()}};
};

#endif // INVOICEQUERYINPUTWIDGET_H
