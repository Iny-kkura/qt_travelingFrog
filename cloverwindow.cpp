#include "cloverwindow.h"
#include "ui_cloverwindow.h"

void cloverClicked(){};
void cloverBorn(){};

CloverWindow::CloverWindow(QString & address,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CloverWindow)
{
    ui->setupUi(this);
    setStyleSheet("border-image:url("+address+");");
}

CloverWindow::~CloverWindow()
{
    delete ui;
}

void CloverWindow::mousePressEvent(QMouseEvent* ev)
{
    emit cloverClicked();
    //add the num of clover
}

void CloverWindow::paintEvent(QPaintEvent*)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}
