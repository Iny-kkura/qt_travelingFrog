#include "newraffle.h"
#include "ui_newraffle.h"

NewRaffle::NewRaffle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewRaffle)
{
    ui->setupUi(this);
    setWindowTitle("NewRaffle");
    setWindowIcon(QIcon(":/pictures/mail_hukubiki.png"));
    ui->widget->setStyleSheet("border-image: url(:/pictures/frame_02.png);");

}

NewRaffle::~NewRaffle()
{
    delete ui;
}

void NewRaffle::setNum(const int& num,Frog* f)
{
    QString str="恭喜获得"+QString::number(num)+"张兑换券";
     ui->label_2->setText(str);
    f->set_raffle(num);
}

void NewRaffle::closeEvent(QCloseEvent*)
{
     emit raffle_Closed();
}
