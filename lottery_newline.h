#ifndef LOTTERY_NEWLINE_H
#define LOTTERY_NEWLINE_H

#include <QWidget>
#include<QPushButton>
#include<QCloseEvent>

namespace Ui {
class Lottery_newline;
}

class Lottery_newline : public QPushButton
{
    Q_OBJECT

public:
    explicit Lottery_newline(QPushButton *parent = nullptr);
    ~Lottery_newline();
    //void sendRaffle(int & num);


private:
    Ui::Lottery_newline *ui;
};

#endif // LOTTERY_NEWLINE_H
