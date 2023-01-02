#ifndef WEAPONS1_H
#define WEAPONS1_H

#include <QDialog>

namespace Ui {
class weapons1;
}

class weapons1 : public QDialog
{
    Q_OBJECT
signals:
    void SIG_Change1();
    void SIG_Bomb();
    void SIG_Move1();
public:
    explicit weapons1(QWidget *parent = 0);
    ~weapons1();
    void setWinFlags();
private slots:
    void on_pb_bomb_clicked();

    void on_pb_sur_clicked();

    void on_pb_move_clicked();

private:
    Ui::weapons1 *ui;
};

#endif // WEAPONS1_H
