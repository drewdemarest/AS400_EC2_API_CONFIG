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
    QJsonObject scheduleSettings_ =    {{"invoiceInterval",         QJsonValue()},
                                        {"invoiceDaysPrior",        QJsonValue()},
                                        {"invoiceChunkSize",        QJsonValue()},
                                        {"customerChainInterval",   QJsonValue()},
                                        {"customerChainChunkSize",  QJsonValue()}};
};

#endif // CUSTOMERCHAINQUERYINPUTWIDGET_H
