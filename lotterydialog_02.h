#ifndef LOTTERYDIALOG_02_H
#define LOTTERYDIALOG_02_H

#include <QWidget>
#include<QDialog>


namespace Ui {
class LotteryDialog_02;
}

class LotteryDialog_02 : public QDialog
{
    Q_OBJECT

public:
    explicit LotteryDialog_02(QWidget *parent = nullptr);
    ~LotteryDialog_02();

private:
    Ui::LotteryDialog_02 *ui;
};

#endif // LOTTERYDIALOG_02_H
