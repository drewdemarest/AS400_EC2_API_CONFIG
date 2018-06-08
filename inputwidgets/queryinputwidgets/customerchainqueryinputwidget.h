#ifndef CUSTOMERCHAINQUERYINPUTWIDGET_H
#define CUSTOMERCHAINQUERYINPUTWIDGET_H

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

private:
    Ui::CustomerChainQueryInputWidget *ui;
};

#endif // CUSTOMERCHAINQUERYINPUTWIDGET_H
