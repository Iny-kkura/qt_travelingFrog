#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tableblg.h"
#include "yard.h"
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(768,1280);
    this->setMouseTracking(true);
    setWindowTitle(QString("Home"));
    setWindowIcon(QIcon(":/pictures/meisyo_f_13.png"));

    connect(ui->Prepare,&QPushButton::clicked,this,&MainWindow::on_Prepare_clicked);

    //用一个定时信号来更新显示四叶草数目
    QTimer *pTimer=new QTimer();
    connect(pTimer, &QTimer::timeout, [=](){
        ui->MoneyNumber->setText(QString::number(myFrog->money));
    });
    pTimer->start(1000); // 每1000ms更新一次

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Prepare_clicked()
{
    this->Table->show();
    QMessageBox box(Table);
    box.setWindowTitle("提示");
    box.setWindowIcon(QIcon(":/pictures/icon_syougou.png"));
    box.setText(QStringLiteral("您至多可以选择2种食物和4种工具放入背包内！"));
    box.exec();
}

void MainWindow::on_to_yard_clicked()
{
    this->hide();
    this->MyYard->show();
}

void MainWindow::mousePressEvent(QMouseEvent* ev){
    //去商店
    QRect To_store(ui->to_store->pos(),ui->to_store->size());
    if(To_store.contains(ev->pos())){
        this->hide();
        this->this_store->show();
        this->this_store->previous = 0;
    }
}

