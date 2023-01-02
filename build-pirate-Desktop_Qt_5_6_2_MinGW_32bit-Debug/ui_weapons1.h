/********************************************************************************
** Form generated from reading UI file 'weapons1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEAPONS1_H
#define UI_WEAPONS1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_weapons1
{
public:
    QLabel *lb_main;
    QPushButton *pb_move;
    QPushButton *pb_sur;
    QPushButton *pb_bomb;

    void setupUi(QDialog *weapons1)
    {
        if (weapons1->objectName().isEmpty())
            weapons1->setObjectName(QStringLiteral("weapons1"));
        weapons1->resize(597, 542);
        weapons1->setMinimumSize(QSize(597, 542));
        weapons1->setMaximumSize(QSize(597, 542));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/sailor1.png"), QSize(), QIcon::Normal, QIcon::Off);
        weapons1->setWindowIcon(icon);
        lb_main = new QLabel(weapons1);
        lb_main->setObjectName(QStringLiteral("lb_main"));
        lb_main->setGeometry(QRect(0, 0, 597, 542));
        lb_main->setPixmap(QPixmap(QString::fromUtf8(":/image/weapons1.jpg")));
        pb_move = new QPushButton(weapons1);
        pb_move->setObjectName(QStringLiteral("pb_move"));
        pb_move->setGeometry(QRect(22, 50, 191, 131));
        pb_move->setStyleSheet(QStringLiteral("background: transparent;"));
        pb_move->setCheckable(true);
        pb_move->setFlat(true);
        pb_sur = new QPushButton(weapons1);
        pb_sur->setObjectName(QStringLiteral("pb_sur"));
        pb_sur->setGeometry(QRect(22, 190, 191, 131));
        pb_sur->setStyleSheet(QStringLiteral("background: transparent;"));
        pb_sur->setFlat(true);
        pb_bomb = new QPushButton(weapons1);
        pb_bomb->setObjectName(QStringLiteral("pb_bomb"));
        pb_bomb->setGeometry(QRect(241, 50, 59, 81));
        pb_bomb->setStyleSheet(QStringLiteral("background: transparent;"));
        pb_bomb->setCheckable(true);
        pb_bomb->setFlat(true);

        retranslateUi(weapons1);

        QMetaObject::connectSlotsByName(weapons1);
    } // setupUi

    void retranslateUi(QDialog *weapons1)
    {
        weapons1->setWindowTitle(QApplication::translate("weapons1", "weapons", 0));
        lb_main->setText(QString());
        pb_move->setText(QString());
        pb_sur->setText(QString());
        pb_bomb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class weapons1: public Ui_weapons1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEAPONS1_H
