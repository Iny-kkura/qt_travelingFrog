#include "card_newline.h"
#include "ui_card_newline.h"

card_newline::card_newline(QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::card_newline)
{
    ui->setupUi(this);
}

card_newline::~card_newline()
{
    delete ui;
}
void card_newline::addcard(const QString& newcard)
{

    ui->label->setStyleSheet(newcard);
}
