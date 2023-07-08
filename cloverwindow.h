#ifndef CLOVERWINDOW_H
#define CLOVERWINDOW_H

#include <QWidget>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>
#include<QStyleOption>

namespace Ui {
class CloverWindow;
}

class CloverWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CloverWindow(QString& address,QWidget *parent = nullptr);
    ~CloverWindow();
    void mousePressEvent(QMouseEvent* ev);
    void paintEvent(QPaintEvent*);

signals:
    void cloverClicked();
    void cloverBorn();

private:
    Ui::CloverWindow *ui;
};

#endif // CLOVERWINDOW_H
