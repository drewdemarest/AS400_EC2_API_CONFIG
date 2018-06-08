#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inputwidgets/as400inputwidget.h"
#include "inputwidgets/importscheduleinputwidget.h"
#include "inputwidgets/mysqlinputwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AS400InputWidget *as400Input = new AS400InputWidget(this);
    ImportScheduleInputWidget *schdeuleInput = new ImportScheduleInputWidget(this);
    MySQLInputWidget *mysqlInput = new MySQLInputWidget(this);
};

#endif // MAINWINDOW_H
