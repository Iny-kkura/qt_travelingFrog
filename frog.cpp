#include "frog.h"
#include <QFileDevice>
#include<QFile>
#include <QTextStream>
#include <QDebug>
#define YELLOW 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define WHITE 5


Frog::Frog(): item_num(0),
money(0), Raffle_num(0)
{
    for(int i=0;i<6;++i)
        Collection[i]=0;
    for(int i=0;i<20;++i){
        TypeNum[i] = 0;
    }
}

int Frog::get_raffle()
{
    qDebug()<<"get_raffle called"<<Raffle_num;
    return Raffle_num;
}

void Frog::set_raffle(int dn)
{
    Raffle_num+=dn;
     qDebug()<<"set_raffle called"<<Raffle_num;
    return;
}
int Frog::get_action()
{
    return action;
}

bool Frog::change_action(int i)
{
    action = i;
    return true;
}

int Frog::get_strength()
{
    return strength;
}

bool Frog::change_strength(int i)
{
    strength = i;
    return true;
}

bool Frog::get_is_inside()
{
    return loc.is_inside;
}


bool Frog::change_is_inside()//直接通过取反更改是否在家中的状态
{
    loc.is_inside = !loc.is_inside;
    return true;
}


int* Frog::get_pos()
{
    return loc.pos;
}

bool Frog::change_pos(int* new_pos)
{
    loc.pos[0] = ~new_pos[0];
    loc.pos[1] = new_pos[1];
    return true;
}

int Frog::get_outside_city()
{
    return loc.outside_city;
}

bool Frog::change_outside_city(int i)
{
    loc.outside_city = i;
    return true;
}

void Frog::Read(QString FrogName){
    QString na;
    int num[23];
    QFile file("../user_info.txt");
    bool ok=file.open(QIODevice::ReadOnly| QIODevice::Text);
    QTextStream ss(&file);
    if(ok){
        int flag = 0;
        while(!ss.atEnd()){
            ss>>na;
            for(int i=0;i<=22;++i){
                QString temp;
                ss>>temp;
                num[i]=temp.toInt();
            }
            if(na == FrogName){
                flag = 1;
                money = num[0];
                for(int i=1;i<=16;++i){
                    TypeNum[i]=num[i];
                }
                Raffle_num = num[17];
                for(int i=18;i<=22;++i){
                    Collection[i-17]=num[i];
                }
                break;
            }
        }
    }
    else
        qDebug()<<"false";
    file.close();
}

void Frog::Write(QString FrogName){
    QFile readfile("D:\\homework&pics\\frog_travel\\Travelling_Frog(1)\\Travelling_Frog\\user_info.txt");
    bool ok=readfile.open(QIODevice::ReadOnly| QIODevice::Text);
    QString strAll;
    if(ok){
        QTextStream ss(&readfile);
        strAll=ss.readAll();
    }
    else{
        qDebug()<<"false";
    }
    readfile.close();

    readfile.open(QIODevice::Truncate | QIODevice::ReadWrite);
    readfile.close();

    QFile writefile("D:\\homework&pics\\frog_travel\\Travelling_Frog(1)\\Travelling_Frog\\user_info.txt");
    QStringList strList;
    ok=writefile.open(QIODevice::Truncate| QIODevice::WriteOnly |QIODevice::Text);
    int flag=0;
    if(ok){
        QTextStream stream(&writefile);
        strList=strAll.split("\n");
        for(int i=0;i<strList.count();i+=24){
            if(i==0)
                stream<<strList.at(i)<<Qt::endl;
            else
                stream<<Qt::endl<<strList.at(i)<<Qt::endl;
            if(strList.at(i).contains(FrogName)){
                flag=1;
                for(int j=i+1;j<=i+23;++j){
                    if(j == i+1){
                        QString tempstr=QString::number(money);
                        stream<<tempstr<<Qt::endl;
                    }
                    else if(j>=i+2 && j<=i+17){
                        QString tempstr=QString::number(TypeNum[j-i-1]);
                        stream<<tempstr<<Qt::endl;
                    }
                    else if(j==i+18){
                        QString tempstr=QString::number(Raffle_num);
                        stream<<tempstr<<Qt::endl;
                    }
                    else{
                        QString tempstr=QString::number(Collection[j-i-18]);
                        if(j==i+23){
                            stream<<tempstr;
                        }
                        else{
                            stream<<tempstr<<Qt::endl;
                        }
                    }
                }
            }
            else{
                for(int j=i+1;j<=i+23 && j<strList.count();++j){
                    if(j==i+23)
                        stream<<strList.at(j);
                    else
                        stream<<strList.at(j)<<Qt::endl;
                }
            }
        }
    }
    else
        qDebug()<<"false";
    writefile.close();
    if(flag==0){
        ok=writefile.open(QIODevice::Append|QIODevice::WriteOnly|QIODevice::Text);
        if(ok){
            QTextStream stream(&writefile);
            stream<<FrogName<<Qt::endl;
            stream<<QString::number(money)<<Qt::endl;
            for(int i=1;i<=22;++i){
                if(i<=16){
                    stream<<QString::number(TypeNum[i])<<Qt::endl;
                }
                else if(i==17){
                    stream<<QString::number(Raffle_num)<<Qt::endl;
                }
                else if(i>17 && i<22){
                    stream<<QString::number(Collection[i-17])<<Qt::endl;
                }
                else{
                    stream<<QString::number(Collection[i-17]);
                }
            }
        }
        writefile.close();
    }
    else
        qDebug()<<"false";
}
