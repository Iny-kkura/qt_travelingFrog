#include "lotterydialog_01.h"
#include "ui_lotterydialog_01.h"
#include"lotter.h"

//bugs:  judge=false the text can't  show
//          the bag item need to add the res
LotteryDialog_01::LotteryDialog_01(QWidget *parent,bool judge,Frog* f) :
    QDialog(parent),
    ui(new Ui::LotteryDialog_01)
{
    ui->setupUi(this);
    //this->show();

    setWindowIcon(QIcon(":/pictures/mail_yotuba.png"));
    this->setGeometry(500,500,467,468);
    if(judge)
    {
        ui->warninglabel->setVisible(false);
        //lotterng get res  show the right ball
        int res_lotter= Lotter::lottering();
        f->Collection[res_lotter]+=1;
        f->Write(f->myName);

        QLabel* ballpic=ui->theball;
        ballpic->setGeometry(200,100,300,300);

        // animation->setTargetObject(ballpic);
        animation=new QPropertyAnimation(ballpic,"geometry");
        animation->setDuration(1000);
        animation->setStartValue(QRect(400,80,300,300));
        animation->setEndValue(ballpic->geometry());


  switch(res_lotter){
    case YELLOW:
        ballpic->setStyleSheet("image:url(:/pictures/lottery_ball_01.png)");

        break;
    case RED:
        ballpic->setStyleSheet("image:url(:/pictures/lottery_ball_02.png)");
        break;
    case BLUE:
        ballpic->setStyleSheet("image:url(:/pictures/lottery_ball_03.png)");
        break;
    case GREEN:
        ballpic->setStyleSheet("image:url(:/pictures/lottery_ball_04.png)");
        break;
    default:
        ballpic->setStyleSheet("image:url(:/pictures/lottery_ball_05.png)");
        break;
    }
    animation->start();
    }
    else
    {
   // ballpic->setPixmap(QPixmap(:/pictures/lottery_frame_01.png"));
    this->setGeometry(500,500,460,150);
    this->setStyleSheet("QDialog{border-image:url(:/pictures/lottery_frame_01.jpg);}");
    ui->warninglabel->setGeometry(700,700,81,31);
    //ui->warninglabel->setVisible(true);
    //ui->warninglabel->show();
    /*QLabel* ballpic=ui->theball;
    ballpic->setText("兑换券不足");
    ballpic->setAlignment(Qt::AlignCenter);//??
    ballpic->show();*/
    //this->text
    }

    /*QTimer* timer=new QTimer(this);
    timer->setInterval(10000);
    connect(timer,&QTimer::timeout,this,&QDialog::close);*/
   // this->close();
    this->exec();
}


LotteryDialog_01::~LotteryDialog_01()
{
    delete ui;
}

