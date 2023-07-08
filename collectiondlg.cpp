#include "collectiondlg.h"
#include "ui_collectiondlg.h"

#include <QTimer>

#define YELLOW 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define WHITE 5

CollectionDlg::CollectionDlg(QWidget *parent,Frog * f,QDialog* y) :
    QDialog(parent),myFrog(f),this_yard(y),
    ui(new Ui::CollectionDlg)
{
    ui->setupUi(this);
    this->setFixedSize(600,500);
    setWindowTitle("Collection");
    setWindowIcon(QIcon(":/mail_yotuba.png"));

    QTimer *pTimer=new QTimer();
    connect(pTimer, &QTimer::timeout, [=](){
        ui->YellowLabel->setText(QStringLiteral("黄玉珠 ×")+QString::number(myFrog->Collection[YELLOW]));
        ui->RedLabel->setText(QStringLiteral("红玉珠 ×")+QString::number(myFrog->Collection[RED]));
        ui->GreenLabel->setText(QStringLiteral("绿玉珠 ×")+QString::number(myFrog->Collection[GREEN]));
        ui->BlueLabel->setText(QStringLiteral("青玉珠 ×")+QString::number(myFrog->Collection[BLUE]));
        ui->WhiteLabel->setText(QStringLiteral("白玉珠 ×")+QString::number(myFrog->Collection[WHITE]));
    });
    pTimer->start(5000); // 每1000ms更新一次
}

CollectionDlg::~CollectionDlg()
{
    delete ui;
}

void CollectionDlg::mousePressEvent(QMouseEvent* ev){
    QRect back(ui->ok_btn->pos(),ui->ok_btn->size());
    if(back.contains(ev->pos())){
        this->accept();
        this_yard->show();
    }
}
