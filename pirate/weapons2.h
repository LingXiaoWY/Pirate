#ifndef WEAPONS2_H
#define WEAPONS2_H

#include <QDialog>

namespace Ui {
class weapons2;
}

class weapons2 : public QDialog
{
    Q_OBJECT
signals:
    void SIG_Change2();
    void SIG_Bomb();
    void SIG_Move2();
public:
    explicit weapons2(QWidget *parent = 0);
    ~weapons2();
    void setWinFlags();
private slots:
    void on_pb_bomb_clicked();

    void on_pb_sur_clicked();

    void on_pb_move_clicked();

private:
    Ui::weapons2 *ui;
};

#endif // WEAPONS2_H
