#include "lottery_newline.h"
#include "ui_lottery_newline.h"

Lottery_newline::Lottery_newline(QPushButton *parent) :
    QPushButton(parent),
    ui(new Ui::Lottery_newline)
{
    ui->setupUi(this);

}

Lottery_newline::~Lottery_newline()
{
    delete ui;
}

