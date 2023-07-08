#include "lotterydialog_02.h"
#include "ui_lotterydialog_02.h"

LotteryDialog_02::LotteryDialog_02(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LotteryDialog_02)
{
    ui->setupUi(this);
    setWindowTitle(QString("list"));
    setWindowIcon(QIcon(":/pictures/mail_yotuba.png"));
    this->setFixedSize(500,400);
    this->exec();
}

LotteryDialog_02::~LotteryDialog_02()
{
    delete ui;
}
