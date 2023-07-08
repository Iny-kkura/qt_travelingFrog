#ifndef LOTTERYDIALOG_01_H
#define LOTTERYDIALOG_01_H

#include <QDialog>
#include<QDebug>
#include<QLabel>
#include<QPixmap>
#include<QMouseEvent>
#include<QEventLoop>
#include<QTimer>
#include<QPropertyAnimation>
#include"frog.h"

namespace Ui {
class LotteryDialog_01;
}

class LotteryDialog_01 : public QDialog
{
    Q_OBJECT

public:
    explicit LotteryDialog_01(QWidget *parent = nullptr);
    explicit LotteryDialog_01(QWidget *parent = nullptr,bool judge=true,Frog* f=nullptr);
    ~LotteryDialog_01();
    void mouseMove(QMouseEvent* event);

private:
    Ui::LotteryDialog_01 *ui;
    QPropertyAnimation* animation;
};

#endif // LOTTERYDIALOG_01_H
