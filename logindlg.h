#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = nullptr, QString *s = NULL);
    QString *Frog_name;
    ~LoginDlg();

public slots:
    void on_LoginBtn_clicked();

private slots:
    void on_ExitBtn_clicked();

private:
    Ui::LoginDlg *ui;
};

#endif // LOGINDLG_H
