#ifndef MAILWINDOW_H
#define MAILWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QMouseEvent>
#include <QDialog>
#include<QVector>
#include<QPropertyAnimation>
#include<QGraphicsOpacityEffect>
#include"frog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MailWindow; }
QT_END_NAMESPACE

class MailWindow : public QMainWindow
{
    Q_OBJECT

public:
    MailWindow(QWidget *parent = nullptr);
    ~MailWindow();
    QDialog* this_yard;
    static int startline;
    static QVector<QPushButton*> stock;
    bool sendNewMail(bool ishome);
    bool sendNewRaffle(int & num,Frog* f);

 signals:
    void newmailArrived();

private slots:
    void mousePressEvent(QMouseEvent* ev);

private:
    Ui::MailWindow *ui;
};
#endif // MAILWINDOW_H
