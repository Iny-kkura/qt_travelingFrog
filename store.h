#ifndef STORE_H
#define STORE_H

#include <QDialog>
#include <QMainWindow>
#include <QMouseEvent>
#include "item.h"
#include "frog.h"
#include "lotterywindow.h"

namespace Ui {
class Store;
}

class Store : public QDialog
{
    Q_OBJECT

public:
    explicit Store(QWidget *parent = nullptr);
    QDialog* this_yard;
    QDialog* this_table;
    QMainWindow* this_room;
    LotteryWindow* lottery;
    Frog* myFrog;
    int previous;   //用于记录上次进入商城的地点，0-room，1-yard，2-Table
    int page = 1;   //表示商城页码
    Item* select = NULL;  //标记临时选中商品
    ~Store();

private slots:
    void mousePressEvent(QMouseEvent* ev);
    void PageChange();

private:
    Ui::Store *ui;
};

#endif // STORE_H
