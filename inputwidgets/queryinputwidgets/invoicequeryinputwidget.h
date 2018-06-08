#ifndef INVOICEQUERYINPUTWIDGET_H
#define INVOICEQUERYINPUTWIDGET_H

#include <QWidget>
#include <QtCore>

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

private:
    Ui::InvoiceQueryInputWidget *ui;
};

#endif // INVOICEQUERYINPUTWIDGET_H
