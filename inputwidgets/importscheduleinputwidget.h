#ifndef IMPORTSCHEDULEINPUTWIDGET_H
#define IMPORTSCHEDULEINPUTWIDGET_H

#include <QWidget>
#include "queryinputwidgets/invoicequeryinputwidget.h"
#include "queryinputwidgets/customerchainqueryinputwidget.h"
#include "queryinputwidgets/openorderheaderqueryinputwidget.h"
#include "queryinputwidgets/openorderdetailqueryinputwidget.h"


namespace Ui {
class ImportScheduleInputWidget;
}

class ImportScheduleInputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImportScheduleInputWidget(QWidget *parent = 0);
    ~ImportScheduleInputWidget();

private:
    Ui::ImportScheduleInputWidget *ui;
    InvoiceQueryInputWidget *invoiceInput = new InvoiceQueryInputWidget(this);
    CustomerChainQueryInputWidget *customerChainInput = new CustomerChainQueryInputWidget(this);
    OpenOrderHeaderQueryInputWidget *openOrderHeaderInput = new OpenOrderHeaderQueryInputWidget(this);
    OpenOrderDetailQueryInputWidget *openOrderDetailInput = new OpenOrderDetailQueryInputWidget(this);
};

#endif // IMPORTSCHEDULEINPUTWIDGET_H
