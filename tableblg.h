#ifndef TABLEBLG_H
#define TABLEBLG_H

#include <QDialog>
#include <QMouseEvent>
#include "frog.h"
#include <QCheckBox>
#include "store.h"

namespace Ui {
class TableBlg;
}

class TableBlg : public QDialog
{
    Q_OBJECT

public:
    explicit TableBlg(QWidget *parent = nullptr);
    Frog* myFrog;
    Store* this_store;
    QMainWindow* this_room;
    /*
    Item* carried_food[2];
    Item* carried_tool[4];
    Item* carried_luck[2];*/
    int food_num = 0;
    int tool_num = 0;
    int haveSelected_food[2]={-1,-1};
    int haveSelected_tool[4]={-1,-1,-1,-1};
    ~TableBlg();

private slots:
    void Push_ok_button();
    void mousePressEvent(QMouseEvent* ev);
    void CheckBoxState();
    void AssignGroup();
    void on_stateChanged(int arg1);

private:
    Ui::TableBlg *ui;
};

#endif // TABLEBLG_H
