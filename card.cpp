#include "ui_card.h"
#include"card.h"

Card::Card(const QString str,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Card)
{
    ui->setupUi(this);
    setWindowTitle("card");
    setWindowIcon(QIcon(":/pictures/mail_yotuba.png"));
    setStyleSheet(str);
}

Card::~Card()
{
    delete ui;
}
void Card::addPic(const QString address)
{

    ui->cover->setStyleSheet(address);
    qDebug()<<"set";
}

void Card::paintEvent(QPaintEvent*)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}

void Card::closeEvent(QCloseEvent*)
{
    emit card_Closed();
}
