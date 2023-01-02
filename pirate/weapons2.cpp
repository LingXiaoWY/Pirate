#include "weapons2.h"
#include "ui_weapons2.h"

weapons2::weapons2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::weapons2)
{
    ui->setupUi(this);
}

weapons2::~weapons2()
{
    delete ui;
}

void weapons2::setWinFlags()
{
    Qt::WindowFlags windowsFlag = Qt::Dialog;
    windowsFlag |= Qt::WindowMinimizeButtonHint;
    windowsFlag |= Qt::WindowCloseButtonHint;
    setWindowFlags(windowsFlag);
}


void weapons2::on_pb_bomb_clicked()
{
    if(ui->pb_bomb->isEnabled())
        Q_EMIT SIG_Bomb();
}

void weapons2::on_pb_sur_clicked()
{
    Q_EMIT SIG_Change2();
}

void weapons2::on_pb_move_clicked()
{
    if(ui->pb_move->isEnabled())
        Q_EMIT SIG_Move2();
}
