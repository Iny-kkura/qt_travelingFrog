#ifndef COLLECTIONDLG_H
#define COLLECTIONDLG_H

#include <QDialog>
#include <QMouseEvent>
#include "frog.h"

namespace Ui {
class CollectionDlg;
}

class CollectionDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CollectionDlg(QWidget *parent = nullptr,Frog* f=nullptr,QDialog* y=nullptr);
    Frog* myFrog;
    QDialog* this_yard;
    ~CollectionDlg();

private slots:
    void mousePressEvent(QMouseEvent* ev);

private:
    Ui::CollectionDlg *ui;
};

#endif // COLLECTIONDLG_H
