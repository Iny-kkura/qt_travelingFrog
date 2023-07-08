#include "lotterywindow.h"
#include "ui_lotterywindow.h"
#include"lotter.h"
#include"lotterydialog_01.h"
#include"lotterydialog_02.h"

//bugs: the thread how to realize or connect the signals   about thenumofRaffle

LotteryWindow::LotteryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LotteryWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setFixedSize(750,1300);
    setFixedSize(728,1208);
    this->setWindowTitle("LotteryWindow");
    setWindowIcon(QIcon(":/pictures/mail_yotuba.png"));
    //LotteryWindow->setStyleSheet("border-image:url(:/lottery_background.jpg)");

    //showRaffle();//??thread
    //label to show the num of raffle

    ui->numofRaffle->setStyleSheet("background-color:transparent;");
    QString str=QString::number(myFrog->get_raffle());
    ui->numofRaffle->setText(str);
    //ui->numofRaffle->setGeometry(500,90,100,40);
    ui->numofRaffle->show();

//startbutton finished   q:stress animation |slots
    QPushButton* start=ui->startbutton;

    connect(start,&QPushButton::clicked,this,&LotteryWindow::startbutton_click);
    //connect(start,&QPushButton::clicked,this,&LotteryWindow::showRaffle);
    QTimer *pTimer=new QTimer();
    connect(pTimer, &QTimer::timeout,this, [=](){
        ui->numofRaffle->setText(QString::number(myFrog->get_raffle()));
    });
    pTimer->start(1000); // 每1000ms更新一次

//listbutton
    QPushButton* list=ui->rewardlist;
    connect(list,&QPushButton::clicked,this,&LotteryWindow::rewardlist_click);
}

LotteryWindow::~LotteryWindow()
{
    delete ui;
}

void LotteryWindow:: startbutton_click()//produce the dialog
{
    //qDebug()<<"moving...";
    if(Lotter::startLotter(myFrog))
    {
        LotteryDialog_01  lotterydialog_01(this,true,myFrog);
        lotterydialog_01.show();

    }
    else
    {
        LotteryDialog_01  lotterydialog_01(this,false);
        lotterydialog_01.show();
    }

 }

/*void LotteryWindow::showRaffle()
 {
    //label to show the num of raffle
    QLabel* numofRaffle=new QLabel(nullptr,this);
    numofRaffle->setStyleSheet("background-color:transparent;");
    int num_Raffle=Lotter::getRaffle();
    QString str=QString::number(num_Raffle);
    numofRaffle->setText(str);
    numofRaffle->setGeometry(250,45,50,20);
}*/

 void LotteryWindow::rewardlist_click()
{
    //show the dialog_02
    LotteryDialog_02 lotteryDialog_02;
    lotteryDialog_02.show();
}

void LotteryWindow::mousePressEvent(QMouseEvent *ev){
    QRect to_store(ui->to_store->pos(),ui->to_store->size());
    if(to_store.contains(ev->pos())){
        this->hide();
        this_store->show();
    }
}
