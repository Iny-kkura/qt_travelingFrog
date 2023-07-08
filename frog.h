#ifndef FROG_H
#define FROG_H

#pragma once
#include <vector>
#include "item.h"
#include <QApplication>
#include <QFile>
#define MAX_ITEM_NUM 1000
#define READ 1
#define EAT 2
#define SLEEP 3
#define MAIL_LETTER 4
#define MAIL_PHOTO 5
struct location
{
    bool is_inside;
    int pos[2]={0};//（x,y）的顺序进行访问
    int outside_city;//0表示在家里或者通过is_inside决定是否访问该变量
    location():is_inside(1),outside_city(0) {}
};

class Frog
{
private:
    int action;
    int strength;
    location loc;
public:
    Frog();
    Item* possess[MAX_ITEM_NUM];
    int item_num =0;
    int money;
    int Raffle_num;
    int TypeNum[20];
    QString myName;
    int Collection[6];
    //获取当前抽奖券数目
    int get_raffle();

    //改变抽奖券数目
    void set_raffle(int dn);

    //获取青蛙当前动作
    int get_action();

    //获取用户输入的青蛙的名字
    void GetName(QString s);

    //改变青蛙动作
    bool change_action(int i);

    //获取青蛙当前能量值
    int get_strength();

    //改变青蛙能量值
    bool change_strength(int i);

    //是否在家
    bool get_is_inside();

    //直接通过取反更改是否在家中的状态
    bool change_is_inside();

    //获取当前位置
    int* get_pos();

    //改变当前位置
    bool change_pos(int* new_pos);

    int get_outside_city();

    bool change_outside_city(int i);

    void Read(QString FrogName);
    void Write(QString FrogName);
};

#endif // FROG_H
