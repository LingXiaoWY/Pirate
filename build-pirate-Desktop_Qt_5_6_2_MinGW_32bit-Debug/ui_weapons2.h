/********************************************************************************
** Form generated from reading UI file 'weapons2.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEAPONS2_H
#define UI_WEAPONS2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_weapons2
{
public:
    QLabel *lb_main;
    QPushButton *pb_move;
    QPushButton *pb_sur;
    QPushButton *pb_bomb;

    void setupUi(QDialog *weapons2)
    {
        if (weapons2->objectName().isEmpty())
            weapons2->setObjectName(QStringLiteral("weapons2"));
        weapons2->resize(593, 543);
        QIcon icon;
        icon.addFile(QStringLiteral("../image/sailor2.png"), QSize(), QIcon::Normal, QIcon::Off);
        weapons2->setWindowIcon(icon);
        lb_main = new QLabel(weapons2);
        lb_main->setObjectName(QStringLiteral("lb_main"));
        lb_main->setGeometry(QRect(0, 0, 593, 543));
        lb_main->setPixmap(QPixmap(QString::fromUtf8("../image/weapons2.jpg")));
        pb_move = new QPushButton(weapons2);
        pb_move->setObjectName(QStringLiteral("pb_move"));
        pb_move->setGeometry(QRect(24, 54, 188, 122));
        pb_move->setMinimumSize(QSize(188, 122));
        pb_move->setMaximumSize(QSize(188, 122));
        pb_move->setStyleSheet(QStringLiteral("background: transparent;"));
        pb_move->setCheckable(true);
        pb_move->setFlat(true);
        pb_sur = new QPushButton(weapons2);
        pb_sur->setObjectName(QStringLiteral("pb_sur"));
        pb_sur->setGeometry(QRect(24, 200, 188, 122));
        pb_sur->setMinimumSize(QSize(188, 122));
        pb_sur->setMaximumSize(QSize(188, 122));
        pb_sur->setStyleSheet(QStringLiteral("background: transparent;"));
        pb_sur->setFlat(true);
        pb_bomb = new QPushButton(weapons2);
        pb_bomb->setObjectName(QStringLiteral("pb_bomb"));
        pb_bomb->setGeometry(QRect(249, 55, 52, 76));
        pb_bomb->setStyleSheet(QStringLiteral("background: transparent;"));
        pb_bomb->setCheckable(true);
        pb_bomb->setFlat(true);

        retranslateUi(weapons2);

        QMetaObject::connectSlotsByName(weapons2);
    } // setupUi

    void retranslateUi(QDialog *weapons2)
    {
        weapons2->setWindowTitle(QApplication::translate("weapons2", "weapons", 0));
        lb_main->setText(QString());
        pb_move->setText(QString());
        pb_sur->setText(QString());
        pb_bomb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class weapons2: public Ui_weapons2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEAPONS2_H
