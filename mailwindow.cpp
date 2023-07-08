#include "mailwindow.h"
#include "ui_mailwindow.h"
#include"map.h"
#include"card_newline.h"
#include"card.h"
#include<QDebug>
#include"newraffle.h"
#include"lottery_newline.h"
#include"frog.h"


int MailWindow::startline=0;
QVector<QPushButton*> MailWindow::stock;


MailWindow::MailWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MailWindow)
{
    ui->setupUi(this);
    this->setFixedSize(600,700);
    this->setWindowIcon(QIcon(":/pictures/mail_yotuba.png"));

}

MailWindow::~MailWindow()
{
    delete ui;
}

bool MailWindow::sendNewMail(bool ishome)
{
    if(ishome)
        return false;
    Mail newMail;
    //bool ishome=false;//suppose frog is out
    QString citytogo=QString::fromStdString(newMail.mail(ishome));
    if(!citytogo.isEmpty())
    {
        //new button
        QString setpic="border-image:url(:/pictures/mail_"+citytogo+".png);";
        //QString setpic="border-image:url(:/mail_ star.png);";
        card_newline * btn=new card_newline;
        btn->setParent(this);
        btn->addcard(setpic);
        btn->setGeometry(15,startline,btn->width(),btn->height());
        btn->show();

        stock.append(btn);
        startline+=btn->height();

        qDebug()<<"mail"<<startline;


        //new window
        connect(btn,&QPushButton::clicked,[=](){
            Card* newCard=new Card(setpic);
            newCard->addPic(setpic);
            newCard->show();
            /* QWidget* newCard=new QWidget;
            newCard->setStyleSheet(setpic);
            newCard->show();*/

            connect(newCard,&Card::card_Closed,btn,[=](){//how to delete the button
                qDebug()<<"widget close";

                //the animation of disappearance of button   nonono!!!
                //animation=new QPropertyAnimation(btn,"opacity",this);
                /*QGraphicsOpacityEffect *opacity = new QGraphicsOpacityEffect(btn);
                    btn->setGraphicsOpacityEffect(opacity); //应用到需要透明变化的控件；

                //使用属性动画类让控件在透明度范围内变化
                QPropertyAnimation *opacityAnimation = new QPropertyAnimation(opacity, "opacity");
                opacityAnimation->setDuration(30000); //动效时长3s
                opacityAnimation->setStartValue(0);
                opacityAnimation->setEndValue(1);
                opacityAnimation->start();*/

                // disappear
                btn->hide();

                //deal with the loc of other buttons
                int index=stock.indexOf(btn);
                stock.remove(index);
                if(index!=stock.count())
                {
                    for(int i=index;i<stock.count();++i)
                    {
                        stock[i]->setGeometry(stock[i]->x(),stock[i]->y()-stock[i]->height(),stock[i]->width(),stock[i]->height());
                    }
                }

                startline-=btn->height();
                delete btn;
                delete newCard;
            });
        });

    }
    emit newmailArrived();
    return true;
}

bool MailWindow::sendNewRaffle(int & num,Frog* f)
{
    if(num==0)
        return false;
    qDebug()<<"raffle1"<<startline;
    Lottery_newline* btn_Raffle=new Lottery_newline;
    btn_Raffle->setParent(this);
    btn_Raffle->setGeometry(15,startline,btn_Raffle->width(),btn_Raffle->height());
    btn_Raffle->show();

    stock.append(btn_Raffle);
    startline+=btn_Raffle->height();
    qDebug()<<"raffle2"<<startline;

    connect(btn_Raffle,&QPushButton::clicked,[=](){
        NewRaffle *   newRaffle=new NewRaffle;
        //QWidget* newRaffle=new QWidget;
        newRaffle->setStyleSheet("border-image:url(:/pictures/frame_02.png);");
        newRaffle->setNum(num,f);

        newRaffle->show();
        connect(newRaffle,&NewRaffle::raffle_Closed,btn_Raffle,[=](){
            // disappear
            QPropertyAnimation *a=new QPropertyAnimation(btn_Raffle,"pos");
            a->setStartValue(btn_Raffle->pos());
            a->setEndValue(QPoint(-width(),0));
            a->setDuration(2000);

            btn_Raffle->hide();

            //deal with the loc of other buttons
            int index=stock.indexOf(btn_Raffle);
            stock.remove(index);
            if(index!=stock.count())
            {
                for(int i=index;i<stock.count();++i)
                {
                    stock[i]->setGeometry(stock[i]->x(),stock[i]->y()-stock[i]->height(),stock[i]->width(),stock[i]->height());
                }
            }

            startline-=btn_Raffle->height();
            delete a;
            delete btn_Raffle;
            delete newRaffle;
        });
    });
    emit newmailArrived();
    return true;
}



void MailWindow::mousePressEvent(QMouseEvent* ev){
    QRect close(ui->close->pos(),ui->close->size());
    if(close.contains(ev->pos())){
        this->close();
        this->this_yard->show();
    }
}
