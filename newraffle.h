#ifndef NEWRAFFLE_H
#define NEWRAFFLE_H

#include <QWidget>
#include<QIcon>
#include"frog.h"


namespace Ui {
class NewRaffle;
}

class NewRaffle : public QWidget
{
    Q_OBJECT

public:
    explicit NewRaffle(QWidget *parent = nullptr);
    ~NewRaffle();
    void setNum(const int& num,Frog* f=nullptr);
     void closeEvent(QCloseEvent*);

signals:
     void raffle_Closed();

private:
    Ui::NewRaffle *ui;
};

#endif // NEWRAFFLE_H
