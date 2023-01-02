#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
    ui = nullptr;
}

void login::setWinFlags()
{
    Qt::WindowFlags windowsFlag = Qt::Dialog;
    windowsFlag |= Qt::WindowMinimizeButtonHint;
    windowsFlag |= Qt::WindowCloseButtonHint;
    setWindowFlags(windowsFlag);
}

void login::on_pb_start_clicked()
{
    Q_EMIT SIG_startPlay();
}
