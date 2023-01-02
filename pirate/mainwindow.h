#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsItem>
#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QPaintEvent>
#include <QPainter>
#include <QPoint>
#include <QPointF>
#include <QDebug>
#include <QTimer>
#include <unordered_map>
#include "packdef.h"
#include <string.h>
#include <QLineF>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void SIG_close();
    void SIG_weapons1();
    void SIG_weapons2();
    void SIG_Change1();
    void SIG_Change2();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //重绘事件：小人的移动
    void paintEvent(QPaintEvent *event);

    //设置最小化，退出
    void setWinFlags();
    //关闭事件
    void closeEvent(QCloseEvent *event);
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent *event);

    //设置红队可选
    void setRedChecked();
    //设置红队不可选
    void setRedUnChecked();
    //设置蓝队可选
    void setBlueChecked();
    //设置蓝队不可选
    void setBlueUnChecked();

    //切换回合函数
    void changeRedAndBlue();

    //显示炸弹
    void showBomb();

    //开始游戏
    void startGame();

public:
    //定时器倒计时
    int m_colorCounter;

    //人物是否可以移动
    bool m_PerMove[DEF_PERSON];

    //炸弹是否可以移动
    bool m_BombMove[DEF_PERSON];

    //红方还是蓝方回合
    int m_RedOrBlue;
private slots:
    void on_pb_captain1_clicked();

    void on_pb_captain2_clicked();

    void on_pb_sailor1_clicked();

    void on_pb_sailor2_clicked();

    void slot_countTimer();

    void slot_BoxTimer();

    void slot_record();

    //飞行槽函数
    void slot_fly();

private:
    Ui::MainWindow *ui;
    //重绘定时器
    QTimer m_timer;
    //回合定时器
    QTimer m_countTimer;

    //飞行定时器
    QTimer m_timerFly;
    //定时器计数器
    int m_Counter;

    //箱子定时器倒计时
    int m_boxCounter;


    //允许投掷炸弹
    bool m_moveBomb;

    //物理引擎系数
    float m_Q,m_Z,m_S;

    //鼠标松开后，进行位置移动定时器
    QTimer m_timerPos;
    //箱子刷新
    QTimer m_timerBox;

    //双方的分数
    int m_score1;
    int m_score2;
    //双方士兵HP
    std::unordered_map<int,int>m_RedHP;
    std::unordered_map<int,int>m_BlueHP;

    //游戏结束
    bool m_isOver;

    //窗口边界
    QGraphicsLineItem *m_pBoundUp,*m_pBoundDown,*m_pBoundLeft,*m_pBoundRight;

    //地形边界
    QGraphicsLineItem *m_pBoundTer[7];

    //设置炸弹发射变量
    bool m_bombflag;

    //地形端点
    QPointF m_tPoint[8];

    //移动位置点
    QPoint m_movePoint;

    //在鼠标释放位置在哪个象限
    bool m_tQuadrant;//第三象限
    bool m_fQuadrant;//第四象限
};

#endif // MAINWINDOW_H
