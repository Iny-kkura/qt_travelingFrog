#ifndef LOTTERYWINDOW_H
#define LOTTERYWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>
#include"frog.h"

namespace Ui {
class LotteryWindow;
}

class LotteryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LotteryWindow(QWidget *parent = nullptr);
    ~LotteryWindow();
    QDialog* this_store;
    Frog* myFrog;
    void produceLotteringWindow();
    void startbutton_click();
    void showRaffle();
    void rewardlist_click();
    void mousePressEvent(QMouseEvent* ev);

private:
    Ui::LotteryWindow *ui;
};

#endif // LOTTERYWINDOW_H
