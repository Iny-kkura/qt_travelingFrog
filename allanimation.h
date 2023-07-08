#include <QWidget>
#include<QPropertyAnimation>
#include<QAnimationGroup>
#include<QParallelAnimationGroup>
#include<QSequentialAnimationGroup>
  #include <QGraphicsOpacityEffect>

#include"cloverwindow.h"


class AllAnimation:public QObject
{
Q_OBJECT
public:
    explicit AllAnimation();
    ~AllAnimation();
    static void setDisappear(CloverWindow* target);
    static void setGrow(CloverWindow* w);
    static QPropertyAnimation * ani1,*ani2,*ani3,*ani4,*ani5;
   static QParallelAnimationGroup *clo_dis_1;
    static QSequentialAnimationGroup  *cloverDisppear,*cloverGrow;
private:


};


