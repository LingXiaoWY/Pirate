#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_RedOrBlue(Red),
    m_score1(0),
    m_score2(0),
    m_Z(0),
    m_Q(0),
    m_S(0),
    m_moveBomb(false),
    m_movePoint(0,0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //绑定定时器和槽函数
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(slot_record()));
    connect(&m_countTimer,SIGNAL(timeout()),this,SLOT(slot_countTimer()));
    connect(&m_timerBox,SIGNAL(timeout()),this,SLOT(slot_BoxTimer()));
    connect(&m_timerFly,SIGNAL(timeout()),this,SLOT(slot_fly()));

    //设置边界
    m_pBoundUp = new QGraphicsLineItem();
    m_pBoundDown = new QGraphicsLineItem();
    m_pBoundLeft = new QGraphicsLineItem();
    m_pBoundRight = new QGraphicsLineItem();
    m_pBoundDown->setLine(0,567,1215,567);
    m_pBoundUp->setLine(0,0,1215,0);
    m_pBoundLeft->setLine(0,0,0,567);
    m_pBoundRight->setLine(1215,0,1215,567);
    //设置地形边界点
    m_tPoint[0] = QPointF(484,456);
    m_tPoint[1] = QPointF(737,456);
    m_tPoint[2] = QPointF(417,513);
    m_tPoint[3] = QPointF(484,513);
    m_tPoint[4] = QPointF(737,513);
    m_tPoint[5] = QPointF(800,513);
    m_tPoint[6] = QPointF(417,565);
    m_tPoint[7] = QPointF(800,565);
    //设置地形边界水平线
    m_pBoundTer[0] = new QGraphicsLineItem(QLineF(m_tPoint[0],m_tPoint[1]));//最上水平线
    m_pBoundTer[1] = new QGraphicsLineItem(QLineF(m_tPoint[2],m_tPoint[3]));
    m_pBoundTer[2] = new QGraphicsLineItem(QLineF(m_tPoint[4],m_tPoint[5]));
    //设置地形边界垂直线
    m_pBoundTer[3] = new QGraphicsLineItem(QLineF(m_tPoint[2],m_tPoint[6]));
    m_pBoundTer[4] = new QGraphicsLineItem(QLineF(m_tPoint[0],m_tPoint[3]));
    m_pBoundTer[5] = new QGraphicsLineItem(QLineF(m_tPoint[1],m_tPoint[4]));
    m_pBoundTer[6] = new QGraphicsLineItem(QLineF(m_tPoint[5],m_tPoint[7]));

    //开始游戏
    startGame();
}

MainWindow::~MainWindow()
{
    delete ui;
    m_timer.stop();
    m_countTimer.stop();
    m_timerBox.stop();
    ui = nullptr;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //重绘事件移动
    for(int i=0;i<DEF_PERSON;i++){
        if(m_PerMove[i] && m_movePoint.x() != 0 && m_movePoint.y() != 0){
            switch(i)
            {
            case bomb:
                ui->pb_bomb->move(m_movePoint);
            break;
            case Captain1:
                ui->pb_captain1->move(m_movePoint);
            break;
            case Captain2:
                ui->pb_captain2->move(m_movePoint);
            break;
            case Sailor1:
                ui->pb_sailor1->move(m_movePoint);
            break;
            case Sailor2:
                ui->pb_sailor2->move(m_movePoint);
            break;
            }
            break;
        }
    }
    event->accept();
}

void MainWindow::setWinFlags()
{
    Qt::WindowFlags windowsFlag = Qt::Dialog;
    windowsFlag |= Qt::WindowMinimizeButtonHint;
    windowsFlag |= Qt::WindowCloseButtonHint;
    setWindowFlags(windowsFlag);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::question(this,"退出","是否退出") == QMessageBox::Yes)
    {
        //发信号
        Q_EMIT SIG_close();
        //同意关闭事件
        event->accept();
    }
    else
    {
        //忽略关闭事件
        event->ignore();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_isOver)
        event->accept();
    QPoint mp = QPoint(event->x(),event->y());//鼠标释放位置
    //1. 计算初始飞行系数
//    m_Q = ((250 - mp.x())+(mp.y()-556))/25;//初始飞行系数
    //2. 递减飞行系数
//    m_Z = (m_Q / 0.8);
//    m_S = m_Z - m_Q;
    m_Z = 2;
    m_S = 1;
    m_Counter = 1;
    //3. 记录物体中心点
    for(int i=0;i<DEF_PERSON;i++)
    {
        if(m_PerMove[i])
        {
            switch (i) {
            case bomb:
            {
                m_movePoint = ui->pb_bomb->pos();
                m_bombflag = true;
            }
            break;
            case Captain1:
            {
                m_movePoint = ui->pb_captain1->pos();
            }
            break;
            case Sailor1:
            {
                m_movePoint = ui->pb_sailor1->pos();
            }
            break;
            case Captain2:
            {
                m_movePoint = ui->pb_captain2->pos();
            }
            break;
            case Sailor2:
            {
                m_movePoint = ui->pb_sailor2->pos();
            }
            break;
            default:
                break;
            }
            break;
        }
    }
    //4. 判断第几象限
    if(mp.y()<=m_movePoint.y() || mp.x() == m_movePoint.x() || m_movePoint == QPoint(0,0))
    {
        m_Q = m_S = m_Z = 0.0;
        m_movePoint = QPoint(0,0);
    }
    else
    {
        if(mp.x()<m_movePoint.x())
            m_tQuadrant = true;
        else
            m_fQuadrant = true;
        //5. 飞行定时器
        m_timerFly.start(11);
    }
    event->accept();
}

void MainWindow::setRedChecked()
{
    if(m_RedHP[Captain1] > 0)
        ui->pb_captain1->setEnabled(true);
    if(m_RedHP[Sailor1] > 0)
        ui->pb_sailor1->setEnabled(true);
    ui->pb_captain1->setChecked(false);
    ui->pb_sailor1->setChecked(false);
}

void MainWindow::setRedUnChecked()
{
    ui->pb_captain1->setEnabled(false);
    ui->pb_sailor1->setEnabled(false);
}

void MainWindow::setBlueChecked()
{
    if(m_BlueHP[Captain2] > 0)
        ui->pb_captain2->setEnabled(true);
    if(m_BlueHP[Sailor2] > 0)
        ui->pb_sailor2->setEnabled(true);
    ui->pb_captain2->setChecked(false);
    ui->pb_sailor2->setChecked(false);
}

void MainWindow::setBlueUnChecked()
{
    ui->pb_captain2->setEnabled(false);
    ui->pb_sailor2->setEnabled(false);
}

void MainWindow::changeRedAndBlue()
{
    memset(m_BombMove,0,sizeof(m_BombMove));
    memset(m_PerMove,0,sizeof(m_PerMove));
    m_RedOrBlue++;
    m_bombflag = false;
    m_PerMove[bomb] = false;
    ui->pb_bomb->hide();
    ui->pb_bomb->move(1170,100);//炸弹回到原位
    if(m_RedOrBlue == 2)
        m_RedOrBlue = Red;
    if(m_RedOrBlue == Red){
        ui->lb_color->setText("红方回合");
        setRedChecked();
        setBlueUnChecked();
    }
    else
    {
        ui->lb_color->setText("蓝方回合");
        setRedUnChecked();
        setBlueChecked();
    }
}

void MainWindow::showBomb()
{
        if(m_RedOrBlue == Red)
        {
            if(m_BombMove[Captain1])
            {
                ui->pb_bomb->move(ui->pb_captain1->pos().x()+8,ui->pb_captain1->pos().y()+3);
                ui->pb_bomb->show();
                m_BombMove[Captain1] = false;
            }
            if(m_BombMove[Sailor1])
            {
                ui->pb_bomb->move(ui->pb_sailor1->pos().x(),ui->pb_sailor1->pos().y()-8);
                ui->pb_bomb->show();
                m_BombMove[Sailor1] = false;
            }

        }
        else
        {
            if(m_BombMove[Captain2])
            {
                ui->pb_bomb->move(ui->pb_captain2->pos().x()+8,ui->pb_captain2->pos().y()+3);
                ui->pb_bomb->show();
                m_BombMove[Captain2] = false;
            }
            if(m_BombMove[Sailor2] )
            {
                ui->pb_bomb->move(ui->pb_sailor2->pos().x()+5,ui->pb_sailor2->pos().y()-8);
                ui->pb_bomb->show();
                m_BombMove[Sailor2] = false;
            }
        }
    m_BombMove[bomb] = true;
}

void MainWindow::startGame()
{
    ui->lb_captain1->setText("HP:100");
    ui->lb_captain2->setText("HP:100");
    ui->lb_sailor1->setText("HP:100");
    ui->lb_sailor2->setText("HP:100");
    ui->lb_captain1->show();
    ui->lb_captain2->show();
    ui->lb_sailor1->show();
    ui->lb_sailor2->show();
    ui->lb_color->show();
    ui->lb_timer->show();
    ui->lb_box->move(570,385);
    ui->lb_box->show();
    ui->pb_captain1->show();
    ui->pb_captain2->show();
    ui->pb_sailor1->show();
    ui->pb_sailor2->show();
    ui->pb_captain1->move(490,393);
    ui->pb_captain2->move(680,390);
    ui->pb_sailor1->move(430,460);
    ui->pb_sailor2->move(740,460);
    ui->lb_captain1->move(490,370);
    ui->lb_captain2->move(680,367);
    ui->lb_sailor1->move(430,437);
    ui->lb_sailor2->move(740,437);
    ui->pb_bomb->move(1170,100);
    ui->lb_timer->setText("");
    ui->lb_winner->setText("");
    ui->lb_color->setText("红方回合");
    ui->pb_bomb->hide();
    memset(m_PerMove,0,sizeof(m_PerMove));
    memset(m_BombMove,0,sizeof(m_BombMove));
    m_RedHP[Sailor1] = 100;
    m_RedHP[Captain1] = 100;
    m_BlueHP[Sailor2] = 100;
    m_BlueHP[Captain2] = 100;
    m_timer.start(1000/100);
    setRedChecked();
    setBlueUnChecked();
    m_colorCounter = DEF_TIME;
    m_boxCounter = 0;
    m_countTimer.start(1000);
    m_timerBox.start(1000);
    m_timerFly.stop();
    m_isOver = false;
    m_score1 = 0;
    m_score2 = 0;
    m_Counter = 1;
    m_bombflag = false;
    m_movePoint = QPoint(0,0);
    memset(m_BombMove,0,sizeof(m_BombMove));
    memset(m_PerMove,0,sizeof(m_PerMove));
}


void MainWindow::on_pb_captain1_clicked()
{
    if(!m_PerMove[Captain1] && !m_BombMove[Captain1])
        Q_EMIT SIG_weapons1();
    m_BombMove[Captain1] = true;
    ui->pb_captain1->setChecked(true);
}

void MainWindow::on_pb_captain2_clicked()
{
    if(!m_PerMove[Captain2] && !m_BombMove[Captain2])
      Q_EMIT SIG_weapons2();
    m_BombMove[Captain2] = true;
    ui->pb_captain2->setChecked(true);
}

void MainWindow::on_pb_sailor1_clicked()
{
    if(!m_PerMove[Sailor1] && !m_BombMove[Sailor1])
        Q_EMIT SIG_weapons1();
    m_BombMove[Sailor1] = true;
    ui->pb_sailor1->setChecked(true);
}

void MainWindow::on_pb_sailor2_clicked()
{
    if(!m_PerMove[Sailor2] && !m_BombMove[Sailor2])
        Q_EMIT SIG_weapons2();
    m_BombMove[Sailor2] = true;
    ui->pb_sailor2->setChecked(true);
}

void MainWindow::slot_countTimer()
{
    m_colorCounter--;
    if(m_colorCounter < 1)
    {
        ui->lb_timer->setText(QString("%1秒").arg(m_colorCounter,2,10,QChar('0')));
        if(m_RedOrBlue == Red)
            Q_EMIT SIG_Change1();
        else
            Q_EMIT SIG_Change2();
        return;
    }
    //界面文本更新
    ui->lb_timer->setText(QString("%1秒").arg(m_colorCounter,2,10,QChar('0')));
}

void MainWindow::slot_BoxTimer()
{
    ++m_boxCounter;
    if(m_boxCounter == DEF_BOX_TIME)
    {
        ui->lb_box->show();
        ui->lb_box->move(570,385);
        m_boxCounter %= DEF_BOX_TIME;
    }
}

void MainWindow::slot_record()
{
    if(m_isOver)
        return;
    for(int i=0;i<DEF_PERSON;i++)
    {
        switch(i)
        {
        case bomb:
        {
            bool flag = false;
            QGraphicsRectItem *pItem1 = new QGraphicsRectItem();
            QGraphicsRectItem *pItem2 = new QGraphicsRectItem();
            QGraphicsRectItem *pItem3 = new QGraphicsRectItem();
            pItem1->setRect(QRectF(ui->pb_bomb->x(),ui->pb_bomb->y(),BOMB_WIDTH,BOMB_HEIGHT));
            if(m_RedOrBlue == Red)
            {
                pItem2->setRect(QRectF(ui->pb_captain2->x(),ui->pb_captain2->y(),CAPTAIN2_WIDTH,CAPTAIN2_HEIGHT));
                pItem3->setRect(QRectF(ui->pb_sailor2->x(),ui->pb_sailor2->y(),SAILOR2_WIDTH,SAILOR2_HEIGHT));
                if(pItem1->collidesWithItem(pItem2) && ui->pb_captain2->isVisible())
                {
                    flag = true;
                    if(m_BlueHP[Captain2] > 0 && ui->pb_bomb->isVisible())
                        m_BlueHP[Captain2] -= 35;
                    if(m_BlueHP[Captain2] <= 0)
                    {
                        m_BlueHP[Captain2] = 0;
                        ui->pb_captain2->hide();
                        ui->lb_captain2->hide();
                    }
                    ui->lb_captain2->setText(QString("HP:%1").arg(m_BlueHP[Captain2]));


                }
                if(pItem1->collidesWithItem(pItem3) && ui->pb_sailor2->isVisible())
                {
                    flag = true;
                    if(m_BlueHP[Sailor2] > 0 && ui->pb_bomb->isVisible())
                        m_BlueHP[Sailor2] -= 35;
                    if(m_BlueHP[Sailor2] <= 0)
                    {
                        m_BlueHP[Sailor2] = 0;
                        ui->pb_sailor2->hide();
                        ui->lb_sailor2->hide();
                    }
                    ui->lb_sailor2->setText(QString("HP:%1").arg(m_BlueHP[Sailor2]));
                }
            }
            else
            {
                pItem2->setRect(QRectF(ui->pb_captain1->x(),ui->pb_captain1->y(),CAPTAIN1_WIDTH,CAPTAIN1_HEIGHT));
                pItem3->setRect(QRectF(ui->pb_sailor1->x(),ui->pb_sailor1->y(),SAILOR1_WIDTH,SAILOR1_HEIGHT));
                if(pItem1->collidesWithItem(pItem2) && ui->pb_captain1->isVisible())
                {
                    flag = true;
                    if(m_RedHP[Captain1] > 0 && ui->pb_bomb->isVisible())
                        m_RedHP[Captain1] -= 35;
                    if(m_RedHP[Captain1] <= 0)
                    {
                        m_RedHP[Captain1] = 0;
                        ui->pb_captain1->hide();
                        ui->lb_captain1->hide();
                    }
                    ui->lb_captain1->setText(QString("HP:%1").arg(m_RedHP[Captain1]));
                }
                if(pItem1->collidesWithItem(pItem3) && ui->pb_sailor1->isVisible())
                {
                    flag = true;
                    if(m_RedHP[Sailor1] > 0 && ui->pb_bomb->isVisible())
                        m_RedHP[Sailor1] -= 35;
                    if(m_RedHP[Sailor1] <= 0)
                    {
                        m_RedHP[Sailor1] = 0;
                        ui->pb_sailor1->hide();
                        ui->lb_sailor1->hide();
                    }
                    ui->lb_sailor1->setText(QString("HP:%1").arg(m_RedHP[Sailor1]));
                }
            }

            if(m_bombflag){
                pItem2->setRect(485,455,252,50);
                pItem3->setRect(422,510,378,55);
                if((pItem1->collidesWithItem(pItem2) ||
                   pItem1->collidesWithItem(pItem3) ||
                   pItem1->collidesWithItem(m_pBoundDown) ||
                   pItem1->collidesWithItem(m_pBoundLeft) ||
                   pItem1->collidesWithItem(m_pBoundUp) ||
                   pItem1->collidesWithItem(m_pBoundRight))&&ui->pb_bomb->isVisible())
                   flag = true;
            }
            if(flag)
            {
                ui->pb_bomb->hide();
                ui->pb_bomb->move(1170,100);
                m_movePoint = QPoint(0,0);
                m_timerFly.stop();
                m_PerMove[bomb] = false;
                m_bombflag = false;
                m_tQuadrant = false;
                m_fQuadrant = false;
            }
        }break;
        case Captain1:
        {
            ui->lb_captain1->move(ui->pb_captain1->x(),ui->pb_captain1->y()-23);
            QGraphicsRectItem *pItem1 = new QGraphicsRectItem();
            pItem1->setRect(QRectF(ui->lb_box->x(),ui->lb_box->y(),BOX_WIDTH,BOX_HEIGHT));
            QGraphicsRectItem *pItem2 = new QGraphicsRectItem();
            pItem2->setRect(QRectF(ui->pb_captain1->x(),ui->pb_captain1->y(),CAPTAIN1_WIDTH,CAPTAIN1_HEIGHT));
            //窗口边界判断
            if((pItem2->collidesWithItem(m_pBoundDown) ||
               pItem2->collidesWithItem(m_pBoundLeft) ||
               pItem2->collidesWithItem(m_pBoundUp) ||
               pItem2->collidesWithItem(m_pBoundRight))&&ui->pb_captain1->isVisible())
            {
                ui->pb_captain1->hide();
                ui->lb_captain1->hide();
                m_RedHP[Captain1] = 0;
                m_movePoint = QPoint(0,0);
                m_PerMove[Captain1] = false;
                m_BombMove[Captain1] = false;
                m_timerFly.stop();
                m_tQuadrant = false;
                m_fQuadrant = false;
            }
            //箱子判断
            if(pItem1->collidesWithItem(pItem2) && ui->lb_box->isVisible())
            {
                m_score1 += 50;
                m_boxCounter = 1;
                ui->lb_box->move(570,385+BOX_HEIGHT+5);
                ui->lb_box->hide();
            }
            ui->lb_redscore->setText(QString("红方得分：%1").arg(m_score1));

            bool flag = false;
            //地形碰撞判断
            //水平线
            for(int j=0;j<3;j++)
            {
                if(pItem2->collidesWithItem(m_pBoundTer[j]))
                {
                    int posx1 = 0,posx2 = 0,posy = 0;
                    switch(j)
                    {
                    case 0:
                    {
                        posx1 = m_tPoint[0].x();
                        posx2 = m_tPoint[1].x();
                        posy = m_tPoint[0].y();
                    }
                    break;
                    case 1:
                    {
                        posx1 = m_tPoint[2].x();
                        posx2 = m_tPoint[3].x();
                        posy = m_tPoint[2].y();
                    }break;
                    case 2:
                    {
                        posx1 = m_tPoint[3].x();
                        posx2 = m_tPoint[4].x();
                        posy = m_tPoint[3].y();
                    }break;
                    }
                    if((ui->pb_captain1->pos().x()+CAPTAIN1_WIDTH/2)<posx1 || (ui->pb_captain1->pos().x()+CAPTAIN1_WIDTH/2) > posx2)
                        continue;

                    flag = true;
                    ui->pb_captain1->move(ui->pb_captain1->pos().x(),posy-CAPTAIN1_HEIGHT-1);
                    ui->pb_captain1->show();
                    m_movePoint = QPoint(0,0);
                    m_PerMove[Captain1] = false;
                    m_timerFly.stop();
                    m_tQuadrant = false;
                    m_fQuadrant = false;
                    break;
                }
            }
            //垂直线
            if(!flag)
            for(int j=3;j<7;j++)
            {
                if(pItem2->collidesWithItem(m_pBoundTer[j]) && m_S > 0)
                {
                    m_S = -m_S;
                    int pos = 0;
                    switch(j)
                    {
                    case 3:
                    {
                        pos = 417;
                        ui->pb_captain1->move(pos-CAPTAIN1_WIDTH-1,ui->pb_captain1->pos().y());
                    }break;
                    case 4:{
                        pos = 480;
                        ui->pb_captain1->move(pos-CAPTAIN1_WIDTH-1,ui->pb_captain1->pos().y());
                    }break;
                    case 5:{
                        pos = 737;
                        ui->pb_captain1->move(pos+1,ui->pb_captain1->pos().y());
                    }break;
                    case 6:{
                        pos = 800;
                        ui->pb_captain1->move(pos+1,ui->pb_captain1->pos().y());
                    }break;
                    }
                    ui->pb_captain1->show();
                    break;
                }
            }
        }break;
        case Captain2:
        {
            ui->lb_captain2->move(ui->pb_captain2->x(),ui->pb_captain2->y()-23);
            QGraphicsRectItem *pItem1 = new QGraphicsRectItem();
            pItem1->setRect(QRectF(ui->lb_box->x(),ui->lb_box->y(),BOX_WIDTH,BOX_HEIGHT));
            QGraphicsRectItem *pItem2 = new QGraphicsRectItem();
            pItem2->setRect(QRectF(ui->pb_captain2->x(),ui->pb_captain2->y(),CAPTAIN2_WIDTH,CAPTAIN2_HEIGHT));
            if((pItem2->collidesWithItem(m_pBoundDown) ||
                pItem2->collidesWithItem(m_pBoundLeft) ||
                pItem2->collidesWithItem(m_pBoundUp) ||
                pItem2->collidesWithItem(m_pBoundRight))&&ui->pb_captain2->isVisible())
            {
                ui->pb_captain2->hide();
                ui->lb_captain2->hide();
                m_BlueHP[Captain2] = 0;
                m_movePoint = QPoint(0,0);
                m_PerMove[Captain2] = false;
                m_BombMove[Captain2] = false;
                m_timerFly.stop();
                m_tQuadrant = false;
                m_fQuadrant = false;
            }
            if(pItem1->collidesWithItem(pItem2)&& ui->lb_box->isVisible())
            {
                m_score2 += 50;
                m_boxCounter = 1;
                ui->lb_box->move(570,385+BOX_HEIGHT+5);
                ui->lb_box->hide();
            }
            ui->lb_bluescore->setText(QString("蓝方得分：%1").arg(m_score2));
            bool flag = false;
            //地形碰撞判断
            //水平线
            for(int j=0;j<3;j++)
            {
                if(pItem2->collidesWithItem(m_pBoundTer[j]))
                {
                    int posx1 = 0,posx2 = 0,posy = 0;
                    switch(j)
                    {
                    case 0:
                    {
                        posx1 = m_tPoint[0].x();
                        posx2 = m_tPoint[1].x();
                        posy = m_tPoint[0].y();
                    }
                    break;
                    case 1:
                    {
                        posx1 = m_tPoint[2].x();
                        posx2 = m_tPoint[3].x();
                        posy = m_tPoint[2].y();
                    }break;
                    case 2:
                    {
                        posx1 = m_tPoint[3].x();
                        posx2 = m_tPoint[4].x();
                        posy = m_tPoint[3].y();
                    }break;
                    }
                    if((ui->pb_captain2->pos().x()+CAPTAIN2_WIDTH/2)<posx1 || (ui->pb_captain2->pos().x()+CAPTAIN2_WIDTH/2) > posx2)
                        continue;

                    flag = true;
                    ui->pb_captain2->move(ui->pb_captain2->pos().x(),posy-CAPTAIN2_HEIGHT-1);
                    ui->pb_captain2->show();
                    m_movePoint = QPoint(0,0);
                    m_PerMove[Captain2] = false;
                    m_timerFly.stop();
                    m_tQuadrant = false;
                    m_fQuadrant = false;
                    break;
                }
            }
            //垂直线
            if(!flag)
            for(int j=3;j<7;j++)
            {
                if(pItem2->collidesWithItem(m_pBoundTer[j]) && m_S > 0)
                {
                    m_S = -m_S;
                    int pos = 0;
                    switch(j)
                    {
                    case 3:
                    {
                        pos = 417;
                        ui->pb_captain2->move(pos-CAPTAIN2_WIDTH-1,ui->pb_captain2->pos().y());
                    }break;
                    case 4:{
                        pos = 480;
                        ui->pb_captain2->move(pos-CAPTAIN2_WIDTH-1,ui->pb_captain2->pos().y());
                    }break;
                    case 5:{
                        pos = 737;
                        ui->pb_captain2->move(pos+1,ui->pb_captain2->pos().y());
                    }break;
                    case 6:{
                        pos = 800;
                        ui->pb_captain2->move(pos+1,ui->pb_captain2->pos().y());
                    }break;
                    }
                    ui->pb_captain2->show();
                    break;
                }
            }
        }
        break;
        case Sailor1:
        {
            ui->lb_sailor1->move(ui->pb_sailor1->x(),ui->pb_sailor1->y()-23);
            QGraphicsRectItem *pItem1 = new QGraphicsRectItem();
            pItem1->setRect(QRectF(ui->lb_box->x(),ui->lb_box->y(),BOX_WIDTH,BOX_HEIGHT));
            QGraphicsRectItem *pItem2 = new QGraphicsRectItem();
            pItem2->setRect(QRectF(ui->pb_sailor1->x(),ui->pb_sailor1->y(),SAILOR1_WIDTH,SAILOR1_HEIGHT));
            if((pItem2->collidesWithItem(m_pBoundDown) ||
                pItem2->collidesWithItem(m_pBoundLeft) ||
                pItem2->collidesWithItem(m_pBoundUp) ||
                pItem2->collidesWithItem(m_pBoundRight))&&ui->pb_sailor1->isVisible())
            {
                ui->pb_sailor1->hide();
                ui->lb_sailor1->hide();
                m_RedHP[Sailor1] = 0;
                m_movePoint = QPoint(0,0);
                m_PerMove[Sailor1] = false;
                m_BombMove[Sailor1] = false;
                m_timerFly.stop();
                m_tQuadrant = false;
                m_fQuadrant = false;
            }
            if(pItem1->collidesWithItem(pItem2)&& ui->lb_box->isVisible())
            {
                m_score1 += 50;
                m_boxCounter = 1;
                ui->lb_box->move(570,385+BOX_HEIGHT+5);
                ui->lb_box->hide();
            }
            ui->lb_redscore->setText(QString("红方得分：%1").arg(m_score1));
            //地形碰撞判断
            //水平线
            bool flag = false;
            for(int j=0;j<3;j++)
            {
                if(pItem2->collidesWithItem(m_pBoundTer[j]))
                {
                    int posx1 = 0,posx2 = 0,posy = 0;
                    switch(j)
                    {
                    case 0:
                    {
                        posx1 = m_tPoint[0].x();
                        posx2 = m_tPoint[1].x();
                        posy = m_tPoint[0].y();
                    }
                    break;
                    case 1:
                    {
                        posx1 = m_tPoint[2].x();
                        posx2 = m_tPoint[3].x();
                        posy = m_tPoint[2].y();
                    }break;
                    case 2:
                    {
                        posx1 = m_tPoint[3].x();
                        posx2 = m_tPoint[4].x();
                        posy = m_tPoint[3].y();
                    }break;
                    }
                    if((ui->pb_sailor1->pos().x() + SAILOR1_WIDTH/2)<posx1 || (ui->pb_sailor1->pos().x() + SAILOR1_WIDTH/2) > posx2)
                        continue;

                    flag = true;
                    ui->pb_sailor1->move(ui->pb_sailor1->pos().x(),posy-SAILOR1_HEIGHT-1);
                    ui->pb_sailor1->show();
                    m_movePoint = QPoint(0,0);
                    m_PerMove[Sailor1] = false;
                    m_timerFly.stop();
                    m_tQuadrant = false;
                    m_fQuadrant = false;
                    break;
                }
            }
            //垂直线
            if(!flag)
            for(int j=3;j<7;j++)
            {
                if(pItem2->collidesWithItem(m_pBoundTer[j]) && m_S > 0)
                {
                    m_S = -m_S;
                    int pos = 0;
                    switch(j)
                    {
                    case 3:
                    {
                        pos = 417;
                        ui->pb_sailor1->move(pos-SAILOR1_WIDTH-1,ui->pb_sailor1->pos().y());
                    }break;
                    case 4:{
                        pos = 480;
                        ui->pb_sailor1->move(pos-SAILOR1_WIDTH-1,ui->pb_sailor1->pos().y());
                    }break;
                    case 5:{
                        pos = 737;
                        ui->pb_sailor1->move(pos+1,ui->pb_sailor1->pos().y());
                    }break;
                    case 6:{
                        pos = 800;
                        ui->pb_sailor1->move(pos+1,ui->pb_sailor1->pos().y());
                    }break;
                    }
                    ui->pb_sailor1->show();
                    break;
                }
            }
        }
        break;
        case Sailor2:
        {
            ui->lb_sailor2->move(ui->pb_sailor2->x(),ui->pb_sailor2->y()-23);
            QGraphicsRectItem *pItem1 = new QGraphicsRectItem();
            pItem1->setRect(QRectF(ui->lb_box->x(),ui->lb_box->y(),BOX_WIDTH,BOX_HEIGHT));
            QGraphicsRectItem *pItem2 = new QGraphicsRectItem();
            pItem2->setRect(QRectF(ui->pb_sailor2->x(),ui->pb_sailor2->y(),SAILOR2_WIDTH,SAILOR2_HEIGHT));
            if((pItem2->collidesWithItem(m_pBoundDown) ||
                pItem2->collidesWithItem(m_pBoundLeft) ||
                pItem2->collidesWithItem(m_pBoundUp) ||
                pItem2->collidesWithItem(m_pBoundRight))&&ui->pb_sailor2->isVisible())
            {
                ui->lb_sailor2->hide();
                ui->pb_sailor2->hide();
                m_BlueHP[Sailor2] = 0;
                m_movePoint = QPoint(0,0);
                m_PerMove[Sailor2] = false;
                m_BombMove[Sailor2] = false;
                m_timerFly.stop();
                m_tQuadrant = false;
                m_fQuadrant = false;
            }
            if(pItem1->collidesWithItem(pItem2)&& ui->lb_box->isVisible())
            {
                m_score2 += 50;
                m_boxCounter = 1;
                ui->lb_box->move(570,385+BOX_HEIGHT+5);
                ui->lb_box->hide();
            }
            ui->lb_bluescore->setText(QString("蓝方得分：%1").arg(m_score2));
            //地形碰撞判断
            //水平线
            bool flag = false; //水平线判断，垂直线就不用判断
            for(int j=0;j<3;j++)
            {
                if(pItem2->collidesWithItem(m_pBoundTer[j]))
                {
                    int posx1 = 0,posx2 = 0,posy = 0;
                    switch(j)
                    {
                    case 0:
                    {
                        posx1 = m_tPoint[0].x();
                        posx2 = m_tPoint[1].x();
                        posy = m_tPoint[0].y();
                    }
                    break;
                    case 1:
                    {
                        posx1 = m_tPoint[2].x();
                        posx2 = m_tPoint[3].x();
                        posy = m_tPoint[2].y();
                    }break;
                    case 2:
                    {
                        posx1 = m_tPoint[3].x();
                        posx2 = m_tPoint[4].x();
                        posy = m_tPoint[3].y();
                    }break;
                    }
                    if( (ui->pb_sailor2->pos().x()+ SAILOR2_WIDTH/2)<posx1 || (ui->pb_sailor2->pos().x() + SAILOR2_WIDTH/2) > posx2)
                        continue;

                    flag = true;
                    ui->pb_sailor2->move(ui->pb_sailor2->pos().x(),posy-SAILOR2_HEIGHT-1);
                    ui->pb_sailor2->show();
                    m_movePoint = QPoint(0,0);
                    m_PerMove[Sailor2] = false;
                    m_timerFly.stop();
                    m_tQuadrant = false;
                    m_fQuadrant = false;
                    break;
                }
            }
            if(!flag)
            for(int j=3;j<7;j++)
            {
                if(pItem2->collidesWithItem(m_pBoundTer[j]) && m_S > 0)
                {
                    m_S = -m_S;
                    int pos = 0;
                    switch(j)
                    {
                    case 3:
                    {
                        pos = 417;
                        ui->pb_sailor2->move(pos-SAILOR2_WIDTH-1,ui->pb_sailor2->pos().y());
                    }break;
                    case 4:{
                        pos = 480;
                        ui->pb_sailor2->move(pos-SAILOR2_WIDTH-1,ui->pb_sailor2->pos().y());
                    }break;
                    case 5:{
                        pos = 737;
                        ui->pb_sailor2->move(pos+1,ui->pb_sailor2->pos().y());
                    }break;
                    case 6:{
                        pos = 800;
                        ui->pb_sailor2->move(pos+1,ui->pb_sailor2->pos().y());
                    }break;
                    }
                    ui->pb_sailor2->show();
                    break;
                }
            }
        }
        break;
        }
    }
    //判断是否满足胜利条件
    int RedHP = 0,BlueHP = 0;
    for(auto i:m_RedHP)
        RedHP += i.second;
    for(auto i:m_BlueHP)
        BlueHP += i.second;
    if(m_score1 == 100 || BlueHP <= 0)
    {
        ui->lb_winner->setText("红方胜利");
        m_isOver = true;
    }
    if(m_score2 == 100 ||RedHP <= 0)
    {
        ui->lb_winner->setText("蓝方胜利");
        m_isOver = true;
    }
    //游戏结束
    if(m_isOver)
    {
        ui->lb_color->hide();
        ui->lb_timer->hide();
        m_timer.stop();
        m_timerBox.stop();
        m_countTimer.stop();
        m_timerFly.stop();
        setRedUnChecked();
        setBlueUnChecked();
        if(QMessageBox::question(this,QString("游戏结束"),QString("是否返回主菜单"))==QMessageBox::Yes)
        {
            Q_EMIT SIG_close();
        }
        else
        {
            startGame();
        }
    }
    repaint();
}

void MainWindow::slot_fly()
{
    if(m_S > 0)
        m_S += 0.1;
    m_Counter += 3;
    if(m_tQuadrant)
    {
        m_movePoint = QPoint(m_movePoint.x()+m_S,m_movePoint.y()-m_Z);
        if(m_Counter > 10)
            m_Z -= 0.1;
    }
    else if(m_fQuadrant)
    {
        m_movePoint = QPoint(m_movePoint.x()-m_S,m_movePoint.y()-m_Z);
        if(m_Counter > 10)
            m_Z -= 0.1;
    }
}
