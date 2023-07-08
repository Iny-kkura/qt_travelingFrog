#ifndef ITEM_H
#define ITEM_H

#include <QDialog>

class Item
{
protected:
    //每件商品的价格
    int price;
    //所在商店的页数
    int Atpage;
    //所在页面位置
    //leftup-0,rightup-1,leftdown-2,rightdown-3
    int position;
    //物品种类,0-食物，1-工具
    int type;
    //物品编号
    int num;
public:
    Item();
    QString ItemName;
    int Get_type() const{
        return type;
    }
    int Get_number() const{
        return num;
    }
    int Get_price() const {
            return price;
        }
    int GetPage() const {
        return Atpage;
    }
    int GetPosition() const {
        return position;
    }
    QString Intro_firstLine;
    QString Intro_secondLine;
    QString Intro_thirdLine;
};


//食物
class Food :public Item {
protected:
    //食物补充给青蛙的能量
    int energy;
public:
    Food(){
        type = 0;
    }
    int Get_energy() {
        return energy;
    } 
};

//工具类
class Tool :public Item {
protected:
public:
    Tool(){
        type = 1;
    }
};

//华夫饼
class waffles :public Food {
public:
    //构造函数，每件商品的价格和能量是固定的
    waffles() {
        price = 10;
        num = 1;
        ItemName = QStringLiteral("奶油华夫饼");
        Intro_firstLine = QStringLiteral("香喷喷的原味华夫饼");
        Intro_secondLine = QStringLiteral("涂上天天的奶油");
        Intro_thirdLine = QStringLiteral("嘴馋的时候就来一个吧");
    }
};

//可丽饼
class crepe :public Food {
public:
    //构造函数，每件商品的价格和能量是固定的
    crepe() {
        price = 30;
        num = 2;
        ItemName = QStringLiteral("草莓可丽饼");
        Intro_firstLine = QStringLiteral("奶香味十足的薄煎饼");
        Intro_secondLine = QStringLiteral("卷上新鲜的草莓");
        Intro_thirdLine = QStringLiteral("想少吃点就选这个吧");
    }
};

//茄汁蛋包饭
class omelet_rice :public Food {
public:
    //构造函数，每件商品的价格和能量是固定的
    omelet_rice() {
        price = 80;
        num = 4;
        ItemName = QStringLiteral("茄汁蛋包饭");
        Intro_firstLine = QStringLiteral("口感柔软嫩滑的煎蛋");
        Intro_secondLine = QStringLiteral("裹着暖暖的茄汁炒饭");
        Intro_thirdLine = QStringLiteral("吃完身心都变愉快了呢");
    }
};

//沙拉皮塔饼
class sala_pie:public Food{
public:
    sala_pie(){
        price = 50;
        num = 3;
        ItemName = QStringLiteral("沙拉皮塔饼");
        Intro_firstLine = QStringLiteral("烤的鼓鼓的口袋面包");
        Intro_secondLine = QStringLiteral("装上满满的蔬菜沙拉");
        Intro_thirdLine = QStringLiteral("可以美美饱餐一顿了");
    }
};

//饺子
class jiaozi :public Food {
public:
    //构造函数，每件商品的价格和能量是固定的
    jiaozi() {
        price = 90;
        num = 5;
        ItemName = QStringLiteral("饺子");
        Intro_firstLine = QStringLiteral("热乎乎的白胖大饺子");
        Intro_secondLine = QStringLiteral("皮薄馅儿大颜值高");
        Intro_thirdLine = QStringLiteral("和寒冷的冬天更配哦");
    }
};

//香葱烤包子
class shengjian :public Food {
public:
    //构造函数，每件商品的价格和能量是固定的
    shengjian() {
        price = 100;
        num = 6;
        ItemName = QStringLiteral("香葱烤包子");
        Intro_firstLine = QStringLiteral("外皮烤的焦黄的包子");
        Intro_secondLine = QStringLiteral("散发浓郁的葱香");
        Intro_thirdLine = QStringLiteral("满满的都是大漠风情");
    }
};

//桂花蒸米糕
class rice_cake: public Food{
public:
    rice_cake(){
        price = 100;
        num = 8;
        ItemName = QStringLiteral("桂花蒸米糕");
        Intro_firstLine = QStringLiteral("软糯可口的蒸米糕");
        Intro_secondLine = QStringLiteral("揉入甜而不腻的桂花");
        Intro_thirdLine = QStringLiteral("满满的都是水乡韵味");
    }
};

//海苔煎豆腐
class tofu:public Food{
public:
    tofu(){
        price = 100;
        num = 7;
        ItemName = QStringLiteral("海苔煎豆腐");
        Intro_firstLine = QStringLiteral("外焦里嫩的煎豆腐");
        Intro_secondLine = QStringLiteral("混入海苔的鲜香");
        Intro_thirdLine = QStringLiteral("满满的都是大海的味道");
    }
};

//围巾-云纹
class scarf_cloud :public Tool {
public:
    scarf_cloud(){
        price = 400;
        num = 9;
        Intro_firstLine = QStringLiteral("高端大气上档次的红色围巾");
        Intro_secondLine = QStringLiteral("戴在头上美美哒");
        Intro_thirdLine = QStringLiteral("为旅途增添一抹亮色");
    }
};

//葫芦
class hulu:public Tool{
public:
    hulu(){
        price = 450;
        num = 10;
        ItemName = QStringLiteral("葫芦");
        Intro_firstLine = QStringLiteral("古装剧同款葫芦");
        Intro_secondLine = QStringLiteral("小巧便捷不渗漏");
        Intro_thirdLine = QStringLiteral("炎炎夏日的解渴神器");
    }
};

//水壶
class kettle:public Tool{
public:
    kettle(){
        price = 750;
        num = 11;
        ItemName = QStringLiteral("水壶");
        Intro_firstLine = QStringLiteral("旅行者常备的运动水壶");
        Intro_secondLine = QStringLiteral("坚固耐用不变形");
        Intro_thirdLine = QStringLiteral("炎炎夏日的解渴神器");
    }
};

//朴素纸伞
class umbrella_simple:public Tool{
public:
    umbrella_simple(){
        price = 450;
        num = 12;
        ItemName = QStringLiteral("朴素纸伞");
        Intro_firstLine = QStringLiteral("民间艺人手工制作的纸伞");
        Intro_secondLine = QStringLiteral("古朴典雅不花哨");
        Intro_thirdLine = QStringLiteral("下雨天也有好心情");
    }
};

//自然纸伞
class umbrella_nature:public Tool{
public:
    umbrella_nature(){
        price = 700;
        num = 13;
        ItemName = QStringLiteral("自然纸伞");
        Intro_firstLine = QStringLiteral("民间艺人手工制作的纸伞");
        Intro_secondLine = QStringLiteral("洋溢着自然气息");
        Intro_thirdLine = QStringLiteral("下雨天也有好心情");
    }
};

//水墨纸伞
class umbrella_calligraphy:public Tool{
public:
    umbrella_calligraphy(){
        price = 1200;
        num = 14;
        ItemName = QStringLiteral("水墨纸伞");
        Intro_firstLine = QStringLiteral("民间艺人手工制作的纸伞");
        Intro_secondLine = QStringLiteral("描绘江南水乡的风韵");
        Intro_thirdLine = QStringLiteral("下雨天也有好心情");
    }
};

//简易睡垫
class cushion_simple:public Tool{
public:
    cushion_simple(){
        price = 600;
        num = 15;
        ItemName = QStringLiteral("简易睡垫");
        Intro_firstLine = QStringLiteral("简约风格的入门级睡垫");
        Intro_secondLine = QStringLiteral("舒适便携可折叠");
        Intro_thirdLine = QStringLiteral("户外也有家的温暖");
    }
};

//时尚睡垫
class cushion_fashion:public Tool{
public:
    cushion_fashion(){
        price = 900;
        num = 16;
        ItemName = QStringLiteral("时尚睡垫");
        Intro_firstLine = QStringLiteral("条纹风格的入门级睡垫");
        Intro_secondLine = QStringLiteral("舒适便携可折叠");
        Intro_thirdLine = QStringLiteral("户外也有家的温暖");
    }
};

#endif // ITEM_H
