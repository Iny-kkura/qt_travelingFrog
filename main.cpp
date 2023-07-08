#include "mainwindow.h"
#include "tableblg.h"
#include "yard.h"
#include "logindlg.h"
#include "frog.h"
#include "store.h"
#include "lotterywindow.h"
#include "mailwindow.h"
#include"collectiondlg.h"

#include <QApplication>
#include <QtWidgets/QMessageBox>
#include <string>
#include <string.h>
#include <cstring>

//#include<QSoundEffect>
//#include<QMediaPlayer>

//目前拥有的四叶草数量，作为货币
int money;

//需要用户输入青蛙的名字
QString Frog_name;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDlg Login_interface(nullptr,&Frog_name);
    Login_interface.show();
    if(Login_interface.exec()!=QDialog::Accepted)
        return a.exec();

    std::srand((unsigned)time(NULL));

    MainWindow Room;
    Yard MyYard;
    Store Mystore;
    Frog myFrog;
    TableBlg Table;
    LotteryWindow nowlotter;
    MailWindow mail_inter;
    CollectionDlg collection;

    QObject::connect(&mail_inter,&MailWindow::newmailArrived,&MyYard,&Yard::newMailArrived);

    Table.myFrog=&myFrog;
    Table.this_store=&Mystore;
    Table.this_room=&Room;

    myFrog.money = 1000;

    Room.MyYard=&MyYard;
    Room.this_store=&Mystore;
    Room.myFrog=&myFrog;
    Room.Table=&Table;

    MyYard.this_room=&Room;
    MyYard.this_store=&Mystore;
    MyYard.myFrog=&myFrog;
    MyYard.mail_interface=&mail_inter;
     MyYard.Collection=&collection;

    Mystore.this_room=&Room;
    Mystore.this_yard=&MyYard;
    Mystore.myFrog=&myFrog;
    Mystore.this_table=&Table;
    Mystore.lottery=&nowlotter;

    nowlotter.this_store=&Mystore;
    nowlotter.myFrog=&myFrog;

    mail_inter.this_yard=&MyYard;

    collection.myFrog=&myFrog;
    collection.this_yard=&MyYard;


    myFrog.Read(myFrog.myName);

   MyYard.show();
   // collection.show();
    QMessageBox box;
    box.setWindowTitle("提示");
    box.setWindowIcon(QIcon(":/pictures/meisyo_f_13.png"));
    box.setText(Frog_name+"现在不在家");
    box.exec();
    return a.exec();
}
