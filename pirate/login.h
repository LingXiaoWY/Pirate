#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT
signals:
    void SIG_startPlay();
public:
    explicit login(QWidget *parent = 0);
    ~login();

    void setWinFlags();
private slots:
    void on_pb_start_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
