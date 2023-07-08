#include "allanimation.h"


QPropertyAnimation *AllAnimation:: ani1,*AllAnimation::ani2,*AllAnimation::ani3,*AllAnimation::ani4,*AllAnimation::ani5;
QParallelAnimationGroup *AllAnimation::clo_dis_1;
QSequentialAnimationGroup  *AllAnimation::cloverDisppear,*AllAnimation::cloverGrow;

AllAnimation::AllAnimation()
{
}

AllAnimation::~AllAnimation()
{
}

void AllAnimation::setDisappear(CloverWindow* target)
{
    cloverDisppear=new QSequentialAnimationGroup;
    clo_dis_1=new QParallelAnimationGroup;

    //ani1-loc
    //ani1=new QPropertyAnimation(target,"geometry");
    //ani1->setDuration(1000);
    //ani1->setStartValue(target->geometry());
    //ani1->setEndValue(QRect(target->x(),target->y()-20,target->width(),target->height()));
    //clo_dis_1->addAnimation(ani1);

    //ani2-small
    ani2=new QPropertyAnimation(target,"geometry");
    ani2->setDuration(1000);
    ani2->setStartValue(target->geometry());
    ani2->setEndValue(QRect(target->x(),target->y(),int(target->width()*0.9),int(target->height()*0.9)));
   // clo_dis_1->addAnimation(ani2);

    cloverDisppear->addAnimation(ani2);

    //ani3-opacity
    QGraphicsOpacityEffect *opacity = new QGraphicsOpacityEffect(target);
    opacity->setOpacity(1);
    target->setGraphicsEffect(opacity); //应用到需要透明变化的控件；

    //使用属性动画类让控件在透明度范围内变化
    ani3 = new QPropertyAnimation(opacity, "opacity");
    ani3->setDuration(1000);
    ani3->setStartValue(1);
    ani3->setEndValue(0);
   /* ani3=new QPropertyAnimation(target,"windowOpacity");
    ani3->setDuration(1000);
    ani3->setStartValue(1);
    ani3->setEndValue(0);*/
    cloverDisppear->addAnimation(ani3);

    connect(target,&CloverWindow::cloverClicked,target,[=](){
        cloverDisppear->start();
    });

}
void AllAnimation::setGrow(CloverWindow* w)
{
    cloverGrow=new QSequentialAnimationGroup;

    //large
    ani4=new QPropertyAnimation(w,"geometry");
    ani4->setDuration(600);
    ani4->setStartValue(w->geometry());
    float dx=w->x()*0.004;
    float dy=w->y()*0.004;
    ani4->setEndValue(QRect(w->x()-dx*2,w->y()-dy,w->width()+dx*4,w->height()+dy*2));
    cloverGrow->addAnimation(ani4);
    cloverGrow->addPause(300);

    //small
    ani5=new QPropertyAnimation(w,"geometry");
    ani5->setDuration(600);
    ani5->setStartValue(w->geometry());
    ani5->setEndValue(QRect(w->x()+dx*2,w->y()+dy,w->width()-dx*4,w->height()-dy*2));
    cloverGrow->addAnimation(ani5);

    cloverGrow->setLoopCount(-1);
    cloverGrow->start();

    //return cloverGrow;
}
