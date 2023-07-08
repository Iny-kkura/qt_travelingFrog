#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tableblg.h"
#include "store.h"
#include "frog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    TableBlg* Table;
    QDialog *MyYard;
    Store *this_store;
    Frog* myFrog;
    ~MainWindow();

private slots:
    void on_Prepare_clicked();
    void on_to_yard_clicked();
    void mousePressEvent(QMouseEvent* ev);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
