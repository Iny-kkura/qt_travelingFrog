#ifndef CARD_NEWLINE_H
#define CARD_NEWLINE_H

#include <QWidget>
#include<QPixmap>
#include<QPushButton>

namespace Ui {
class card_newline;
}

class card_newline : public QPushButton
{
    Q_OBJECT

public:
    explicit card_newline(QWidget *parent = nullptr);
    ~card_newline();
    void addcard(const QString& newcard);

private:
    Ui::card_newline *ui;
};

#endif // CARD_NEWLINE_H
