#include "weapons1.h"
#include "ui_weapons1.h"

weapons1::weapons1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::weapons1)
{
    ui->setupUi(this);
}

weapons1::~weapons1()
{
    delete ui;
}

void weapons1::setWinFlags()
{
    Qt::WindowFlags windowsFlag = Qt::Dialog;
    windowsFlag |= Qt::WindowMinimizeButtonHint;
    windowsFlag |= Qt::WindowCloseButtonHint;
    setWindowFlags(windowsFlag);
}

void weapons1::on_pb_bomb_clicked()
{
    if(ui->pb_bomb->isEnabled())
        Q_EMIT SIG_Bomb();
}

void weapons1::on_pb_sur_clicked()
{
    Q_EMIT SIG_Change1();
}

void weapons1::on_pb_move_clicked()
{
    if(ui->pb_move->isEnabled())
        Q_EMIT SIG_Move1();
}
