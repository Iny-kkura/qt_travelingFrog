#include "logindlg.h"
#include "ui_logindlg.h"
#include <QApplication>

LoginDlg::LoginDlg(QWidget *parent, QString *s) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    this->setFixedSize(550,400);
    this->setWindowTitle("Login");
    this->setWindowIcon(QIcon(":/pictures/icon_name.png"));
    this->Frog_name=s;
    connect(ui->LoginBtn,&QPushButton::clicked,this,&LoginDlg::on_LoginBtn_clicked);
    connect(ui->ExitBtn,&QPushButton::clicked,this,&LoginDlg::on_ExitBtn_clicked);
}

LoginDlg::~LoginDlg()
{
    delete ui;
}


void LoginDlg::on_LoginBtn_clicked()
{
    *Frog_name = ui->lineEdit->text();
    this->accept();
}

void LoginDlg::on_ExitBtn_clicked()
{
    this->close();
}
