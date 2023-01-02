#include "ckernel.h"

Ckernel::Ckernel(QObject *parent) :
    QObject(parent),
    m_plogin(new login),
    m_pMW(new MainWindow),
    m_pweapons1(new weapons1),
    m_pweapons2(new weapons2)
{
    //界面设置
    m_plogin->setWinFlags();
    m_pMW->setWinFlags();
    m_pweapons1->setWinFlags();
    m_pweapons2->setWinFlags();

    //信号与槽连接
    connect(m_plogin,SIGNAL(SIG_startPlay()),this,SLOT(slot_dealstartplay()));
    connect(m_pMW,SIGNAL(SIG_close()),this,SLOT(slot_dealstopplay()));
    connect(m_pMW,SIGNAL(SIG_weapons1()),this,SLOT(slot_dealweapon1()));
    connect(m_pMW,SIGNAL(SIG_weapons2()),this,SLOT(slot_dealweapon2()));
    connect(m_pweapons1,SIGNAL(SIG_Change1()),this,SLOT(slot_dealweapon1Change()));
    connect(m_pweapons2,SIGNAL(SIG_Change2()),this,SLOT(slot_dealweapon2Change()));
    connect(m_pMW,SIGNAL(SIG_Change1()),this,SLOT(slot_dealweapon1Change()));
    connect(m_pMW,SIGNAL(SIG_Change2()),this,SLOT(slot_dealweapon2Change()));
    connect(m_pweapons1,SIGNAL(SIG_Bomb()),this,SLOT(slot_dealweaponBomb()));
    connect(m_pweapons2,SIGNAL(SIG_Bomb()),this,SLOT(slot_dealweaponBomb()));
    connect(m_pweapons1,SIGNAL(SIG_Move1()),this,SLOT(slot_dealperMove()));
    connect(m_pweapons2,SIGNAL(SIG_Move2()),this,SLOT(slot_dealperMove()));

    //界面显示
    m_plogin->show();
}

Ckernel::~Ckernel()
{
    if(m_plogin)
    {
        m_plogin->hide();
        delete m_plogin;
        m_plogin = nullptr;
    }
    if(m_pMW)
    {
        m_pMW->hide();
        delete m_pMW;
        m_pMW = nullptr;
    }
    if(m_pweapons1)
    {
        m_pweapons1->hide();
        delete m_pweapons1;
        m_pweapons1 = nullptr;
    }
    if(m_pweapons2)
    {
        m_pweapons2->hide();
        delete m_pweapons2;
        m_pweapons2 = nullptr;
    }
}

//开始游戏
void Ckernel::slot_dealstartplay()
{
    if(!m_pMW)
        exit(0);
    m_plogin->hide();
    m_pMW->show();
    m_pMW->startGame();
}

void Ckernel::slot_dealstopplay()
{
    m_pMW->hide();
    m_plogin->show();
}

void Ckernel::slot_dealweapon1()
{
    m_pweapons1->show();
}

void Ckernel::slot_dealweapon2()
{
    m_pweapons2->show();
}

void Ckernel::slot_dealweapon1Change()
{
    m_pweapons1->hide();
    m_pMW->changeRedAndBlue();
    m_pMW->m_colorCounter = DEF_TIME;

}

void Ckernel::slot_dealweapon2Change()
{
    m_pweapons2->hide();
    m_pMW->changeRedAndBlue();
    m_pMW->m_colorCounter = DEF_TIME;
}

void Ckernel::slot_dealweaponBomb()
{
    m_pMW->m_PerMove[bomb] = true;
    m_pMW->showBomb();
    m_pweapons1->hide();
    m_pweapons2->hide();
}

void Ckernel::slot_dealperMove()
{
    if(m_pMW->m_RedOrBlue == Red)
    {
        if(m_pMW->m_BombMove[Captain1]){
            m_pMW->m_PerMove[Captain1] = true;
            m_pMW->m_PerMove[Sailor1] = false;
        }
        if(m_pMW->m_BombMove[Sailor1]){
            m_pMW->m_PerMove[Sailor1] = true;
            m_pMW->m_PerMove[Captain1] = false;
        }
        m_pweapons1->hide();
    }
    else
    {
        if(m_pMW->m_BombMove[Captain2])
        {
            m_pMW->m_PerMove[Captain2] = true;
            m_pMW->m_PerMove[Sailor2] = false;
        }
        if(m_pMW->m_BombMove[Sailor2])
        {
            m_pMW->m_PerMove[Captain2] = false;
            m_pMW->m_PerMove[Sailor2] = true;
        }
        m_pweapons2->hide();
    }
}
