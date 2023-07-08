#include "tableblg.h"
#include "ui_tableblg.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QTimer>
#include <QMessageBox>

QCheckBox* group[17];
QString name[17] = {"",QStringLiteral("奶油华夫饼"),QStringLiteral("草莓可丽饼"),QStringLiteral("沙拉皮塔饼"),QStringLiteral("茄汁蛋包饭"),
                   QStringLiteral("饺子"),QStringLiteral("香葱烤包子"),QStringLiteral("海苔煎豆腐"),QStringLiteral("桂花蒸米糕"),QStringLiteral("围巾~云纹~"),
                   QStringLiteral("葫芦"),QStringLiteral("水壶"),QStringLiteral("朴素纸伞"),QStringLiteral("自然纸伞"),QStringLiteral("水墨纸伞"),QStringLiteral("简易睡垫"),
                   QStringLiteral("时尚睡垫")};
TableBlg::TableBlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableBlg)
{
    ui->setupUi(this);
    this->setFixedSize(1250,600);
    setWindowTitle("Table");
    setWindowIcon(QIcon(":/pictures/icon_syougou.png"));
    /*
    group[17] = {NULL,ui->choose_1,ui->choose_2,ui->choose_3,ui->choose_4,ui->choose_5,ui->choose_6,ui->choose_7,
            ui->choose_8,ui->choose_9,ui->choose_10,ui->choose_11,ui->choose_12,ui->choose_13,ui->choose_14,
            ui->choose_15,ui->choose_16};*/

    AssignGroup();
    connect(ui->ok_button,&QPushButton::clicked,this,&TableBlg::Push_ok_button);

    //初始化按钮
    QTimer *pTimer=new QTimer();
    connect(pTimer, &QTimer::timeout, [=](){
        group[1]->setText(QStringLiteral("奶油华夫饼 ×")+QString::number(myFrog->TypeNum[1]));
        ui->choose_2->setText(QStringLiteral("草莓可丽饼 ×")+QString::number(myFrog->TypeNum[2]));
        ui->choose_3->setText(QStringLiteral("沙拉皮塔饼 ×")+QString::number(myFrog->TypeNum[3]));
        ui->choose_4->setText(QStringLiteral("茄汁蛋包饭 ×")+QString::number(myFrog->TypeNum[4]));
        ui->choose_5->setText(QStringLiteral("饺子 ×")+QString::number(myFrog->TypeNum[5]));
        ui->choose_6->setText(QStringLiteral("香葱烤包子 ×")+QString::number(myFrog->TypeNum[6]));
        ui->choose_7->setText(QStringLiteral("海苔煎豆腐 ×")+QString::number(myFrog->TypeNum[7]));
        ui->choose_8->setText(QStringLiteral("桂花蒸米糕 ×")+QString::number(myFrog->TypeNum[8]));
        ui->choose_9->setText(QStringLiteral("围巾~云纹~ ×")+QString::number(myFrog->TypeNum[9]));
        ui->choose_10->setText(QStringLiteral("葫芦 ×")+QString::number(myFrog->TypeNum[10]));
        ui->choose_11->setText(QStringLiteral("水壶 ×")+QString::number(myFrog->TypeNum[11]));
        ui->choose_12->setText(QStringLiteral("朴素纸伞 ×")+QString::number(myFrog->TypeNum[12]));
        ui->choose_13->setText(QStringLiteral("自然纸伞 ×")+QString::number(myFrog->TypeNum[13]));
        ui->choose_14->setText(QStringLiteral("水墨纸伞 ×")+QString::number(myFrog->TypeNum[14]));
        ui->choose_15->setText(QStringLiteral("简易睡垫 ×")+QString::number(myFrog->TypeNum[15]));
        ui->choose_16->setText(QStringLiteral("时尚睡垫 ×")+QString::number(myFrog->TypeNum[16]));
        CheckBoxState();
    });
    pTimer->start(5000); // 每5000ms更新一次
}

void TableBlg::AssignGroup(){
    group[0] = NULL;
    group[1] = ui->choose_1;
    group[2] = ui->choose_2;
    group[3] = ui->choose_3;
    group[4] = ui->choose_4;
    group[5] = ui->choose_5;
    group[6] = ui->choose_6;
    group[7] = ui->choose_7;
    group[8] = ui->choose_8;
    group[9] = ui->choose_9;
    group[10] = ui->choose_10;
    group[11] = ui->choose_11;
    group[12] = ui->choose_12;
    group[13] = ui->choose_13;
    group[14] = ui->choose_14;
    group[15] = ui->choose_15;
    group[16] = ui->choose_16;
}

TableBlg::~TableBlg()
{
    delete ui;
}

void TableBlg::Push_ok_button(){
    for(int i=1;i<=16;++i){
        if(group[i]->isChecked()){
            if(i<=8){
                if(food_num == 2){
                    QMessageBox boxx(this);
                    boxx.setWindowTitle(QStringLiteral("警告"));
                    boxx.setText(QStringLiteral("您最多只能选择两样食物放在桌面！"));
                    boxx.exec();
                }
                else{
                    QMessageBox boxx(this);
                    boxx.setWindowTitle(QStringLiteral("提示"));
                    boxx.setWindowIcon(QIcon(":/pictures/icon_syougou.png"));
                    boxx.setText(QStringLiteral("确定要把")+name[i]+QStringLiteral("放在桌面吗？"));
                    QPushButton *agreeBut = boxx.addButton(QStringLiteral("是"), QMessageBox::AcceptRole);
                    QPushButton *disagreeBut = boxx.addButton(QStringLiteral("再想想"),QMessageBox::RejectRole);
                    boxx.exec();
                    if(boxx.clickedButton() == (QAbstractButton*)agreeBut){
                        if(food_num == 0){
                            haveSelected_food[0] = i;
                            food_num++;
                        }
                        else{
                            haveSelected_food[1] = i;
                            food_num++;
                        }
                        myFrog->TypeNum[i]--;
                    }
                }
            }
            else{
                if(tool_num==4){
                    QMessageBox boxx(this);
                    boxx.setWindowTitle(QStringLiteral("警告"));
                     boxx.setWindowIcon(QIcon(":/pictures/icon_syougou.png"));
                    boxx.setText(QStringLiteral("您最多只能选择4样工具放在桌面！"));
                    boxx.exec();
                }
                else{
                    QMessageBox boxx(this);
                    boxx.setWindowTitle(QStringLiteral("提示"));
                    boxx.setText(QStringLiteral("确定要把")+name[i]+QStringLiteral("放在桌面吗？"));
                    QPushButton *agreeBut = boxx.addButton(QStringLiteral("是"), QMessageBox::AcceptRole);
                    QPushButton *disagreeBut = boxx.addButton(QStringLiteral("再想想"),QMessageBox::RejectRole);
                    boxx.exec();
                    if(boxx.clickedButton()==(QAbstractButton*)agreeBut){
                        haveSelected_tool[tool_num++] = i;
                        myFrog->TypeNum[i]--;
                    }
                }
            }
            group[i]->setChecked(false);
        }
        else continue;
    }
    this->accept();
}


void TableBlg::mousePressEvent(QMouseEvent* ev){
    //查看当前桌上物品
    QRect to_see_pos(ui->to_see_possession->pos(),ui->to_see_possession->size());
    if(to_see_pos.contains(ev->pos())){
        QMessageBox MBox;
        MBox.setWindowTitle(QStringLiteral("桌面"));
         MBox.setWindowIcon(QIcon(":/pictures/icon_syougou.png"));
        if(food_num == 0 && tool_num == 0){
            MBox.setText(QStringLiteral("当前桌面上没有任何物品！"));
        }
        else{
            QString str = "";
            for(int i=0;i<food_num;++i){
                str+=name[haveSelected_food[i]]+QStringLiteral(" ×1");
                if(i != food_num - 1){
                    str+='\n';
                }
            }
            if(tool_num != 0)
                str+='\n';
            for(int i=0;i<tool_num;++i){
                str+=name[haveSelected_tool[i]]+QStringLiteral(" ×1");
                if(i != tool_num - 1){
                    str+='\n';
                }
            }
            MBox.setText(str);
        }
        MBox.exec();
    }

    //去商店
    QRect to_store(ui->to_shop->pos(),ui->to_shop->size());
    if(to_store.contains(ev->pos())){
        this->accept();
        this->this_room->hide();
        this->this_store->show();
        this->this_store->previous = 2;
    }

}

void TableBlg::CheckBoxState(){
    for(int i=1;i<=16;++i){
        if(myFrog->TypeNum[i]<=0)
            group[i]->setEnabled(false);
        else
            group[i]->setEnabled(true);
    }
}



void TableBlg::on_stateChanged(int arg1)
{

}
