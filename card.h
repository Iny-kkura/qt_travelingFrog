#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include<QPaintEvent>
#include<QCloseEvent>
#include<QStyleOption>
#include<QPainter>

namespace Ui {
class Card;
}

class Card : public QWidget
{
    Q_OBJECT

public:
    explicit Card(const QString str,QWidget *parent = nullptr);
    ~Card();
    void addPic(const QString address);

protected:
    void paintEvent(QPaintEvent*);
    void closeEvent(QCloseEvent*);
signals:
    void card_Closed();
private:
    Ui::Card *ui;
};

#endif // CARD_H
