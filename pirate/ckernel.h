#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include <QMessageBox>
#include <QString>
#include "mainwindow.h"
#include "weapons1.h"
#include "weapons2.h"
#include "login.h"
#include "packdef.h"

class Ckernel : public QObject
{
    Q_OBJECT
private:
    explicit Ckernel(QObject *parent = 0);
    ~Ckernel();


    MainWindow* m_pMW;
    login* m_plogin;
    weapons1* m_pweapons1;
    weapons2* m_pweapons2;


public:
    static Ckernel*getInstance()
    {
        static Ckernel ckernel;
        return &ckernel;
    }
signals:

public slots:
    //开始游戏处理
    void slot_dealstartplay();

    //游戏界面销毁重新进入登录界面
    void slot_dealstopplay();

    //选择小人触发武器界面
    void slot_dealweapon1();
    void slot_dealweapon2();

    //切换回合
    void slot_dealweapon1Change();
    void slot_dealweapon2Change();

    //显示炸弹
    void slot_dealweaponBomb();

    //处理小人移动
    void slot_dealperMove();
};

#endif // CKERNEL_H
