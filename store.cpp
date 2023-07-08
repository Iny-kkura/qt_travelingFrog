#include "store.h"
#include "ui_store.h"
#include <QTimer>
#include <QWidget>
#include <QMessageBox>

Store::Store(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);
    this->setFixedSize(750,1300);
    setWindowTitle(QString("Store"));
    setWindowIcon(QIcon(":/pictures/icon_syougou.png"));
    ui->Buy_Button->hide();
    this->setMouseTracking(true);

    //用一个定时信号来更新显示四叶草数目
    QTimer *pTimer=new QTimer();
    connect(pTimer, &QTimer::timeout, [=](){
        ui->MoneyNumber->setText(QString::number(myFrog->money));
    });
    pTimer->start(1000); // 每1000ms更新一次
}

Store::~Store()
{
    delete ui;
}

void Store::mousePressEvent(QMouseEvent* ev){
    //“返回”
    QRect GoBack(ui->Back->pos(),ui->Back->size());
    if(GoBack.contains(ev->pos())){
        if(this->previous == 0){
            this->accept();
            this->this_room->show();
        }
        else if(this->previous == 1){
            this->accept();
            this->this_yard->show();
        }
        else{
            this->accept();
            this->this_table->show();
            this->this_room->show();
        }
        return;
    }

    //“庭院”
    QRect To_yard(ui->store_to_yard->pos(),ui->store_to_yard->size());
    if(To_yard.contains(ev->pos())){
        this->accept();
        this->this_yard->show();
        return;
    }

    //“房间”
    QRect To_room(ui->store_to_room->pos(),ui->store_to_room->size());
    if(To_room.contains(ev->pos())){
        this->accept();
        this->this_room->show();
        return;
    }

    //翻页
    QRect change(ui->PageChange->pos(),ui->PageChange->size());
    if(change.contains(ev->pos())){
        page++;
        page = page % 5;
        if(page==0)
            page=1;
        PageChange();
        return;
    }
    QRect change_pre(ui->PageChange_pre->pos(),ui->PageChange_pre->size());
    if(change_pre.contains(ev->pos())){
        page--;
        page = page % 5;
        if(page==0)
            page=1;
        PageChange();
        return;
    }

    //抽奖
    QRect to_lot(ui->to_lottery->pos(),ui->to_lottery->size());
    if(to_lot.contains(ev->pos())){
        this->accept();
        this->lottery->show();
    }

    //显示商品信息
    QRect leftup(ui->leftup->pos(),ui->leftup->size());
    QRect leftdown(ui->leftdown->pos(),ui->leftdown->size());
    QRect rightup(ui->rightup->pos(),ui->rightup->size());
    QRect rightdown(ui->rightdown->pos(),ui->rightdown->size());
    QRect Purchase(ui->Buy_Button->pos(),ui->Buy_Button->size());
    if(leftup.contains(ev->pos())){
        ui->Buy_Button->show();
        if(page == 1)
            select = new waffles;
        else if(page == 2)
            select = new jiaozi;
        else if(page == 3)
            select = new scarf_cloud;
        else if(page == 4)
            select = new umbrella_nature;
        ui->firstLine->setText(select->Intro_firstLine);
        ui->secondLine->setText(select->Intro_secondLine);
        ui->thirdLine->setText(select->Intro_thirdLine);
        return;
    }
    else if(rightup.contains(ev->pos())){
        ui->Buy_Button->show();
        if(page == 1)
            select = new crepe;
        else if(page == 2)
            select = new shengjian;
        else if(page == 3)
            select = new hulu;
        else if(page == 4)
            select = new umbrella_calligraphy;
        ui->firstLine->setText(select->Intro_firstLine);
        ui->secondLine->setText(select->Intro_secondLine);
        ui->thirdLine->setText(select->Intro_thirdLine);
        return;
    }
    else if(leftdown.contains(ev->pos())){
        ui->Buy_Button->show();
        if(page == 1)
            select = new sala_pie;
        else if(page == 2)
            select = new tofu;
        else if(page == 3)
            select = new kettle;
        else if(page == 4)
            select = new cushion_simple;
        ui->firstLine->setText(select->Intro_firstLine);
        ui->secondLine->setText(select->Intro_secondLine);
        ui->thirdLine->setText(select->Intro_thirdLine);
        return;
    }
    else if(rightdown.contains(ev->pos())){
        ui->Buy_Button->show();
        if(page == 1)
            select = new omelet_rice;
        else if(page == 2)
            select = new rice_cake;
        else if(page == 3)
            select = new umbrella_simple;
        else if(page == 4)
            select = new cushion_fashion;
        ui->firstLine->setText(select->Intro_firstLine);
        ui->secondLine->setText(select->Intro_secondLine);
        ui->thirdLine->setText(select->Intro_thirdLine);
        return;
    }
    else{
        if(Purchase.contains(ev->pos()) && select != NULL){
            if (select->Get_price() > myFrog->money){
                QMessageBox box;
                box.setWindowTitle(QStringLiteral("警告"));
                box.setText(QStringLiteral("三叶草数目不足！"));
                box.exec();
                return;
            }
            QMessageBox MBox;
            MBox.setWindowTitle(QStringLiteral("提示"));
            MBox.setWindowIcon(QIcon(":/pictures/icon_syougou.png"));
            MBox.setText(QStringLiteral("确定要购买")+select->ItemName+QStringLiteral("吗？"));
            QPushButton *agreeBut = MBox.addButton(QStringLiteral("是"), QMessageBox::AcceptRole);
            QPushButton *disagreeBut = MBox.addButton(QStringLiteral("再想想"),QMessageBox::RejectRole);
            MBox.exec();
            if(MBox.clickedButton() == (QAbstractButton*)agreeBut){
                myFrog->possess[myFrog->item_num++] = select;
                myFrog->money -= select->Get_price();
                myFrog->TypeNum[select->Get_number()]++;
            }
            else{}
        }
        ui->Buy_Button->hide();
        select = NULL;
        ui->firstLine->setText("");
        ui->secondLine->setText("");
        ui->thirdLine->setText("");
    }

}

void Store::PageChange(){
    if(this->page == 1){
        this->setStyleSheet("QDialog{border-image: url(:/myPictures/pictures/store_page1.jpg);}");
    }
    else if(this->page == 2){
        this->setStyleSheet("QDialog{border-image: url(:/myPictures/pictures/store_page2.jpg);}");
    }
    else if(this->page == 3){
        this->setStyleSheet("QDialog{border-image: url(:/myPictures/pictures/store_page3.jpg);}");
    }
    else if(this->page == 4){
        this->setStyleSheet("QDialog{border-image: url(:/myPictures/pictures/store_page4.jpg);}");
    }
}
