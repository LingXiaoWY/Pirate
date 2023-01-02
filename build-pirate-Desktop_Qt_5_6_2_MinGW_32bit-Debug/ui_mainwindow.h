/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *lb_main;
    QPushButton *pb_captain1;
    QPushButton *pb_captain2;
    QLabel *lb_terrain;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *lb_color;
    QLabel *lb_timer;
    QLabel *lb_winner;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lb_box;
    QLabel *lb_redscore;
    QLabel *lb_bluescore;
    QLabel *lb_rule;
    QPushButton *pb_sailor1;
    QPushButton *pb_sailor2;
    QPushButton *pb_bomb;
    QLabel *lb_sailor1;
    QLabel *lb_captain1;
    QLabel *lb_captain2;
    QLabel *lb_sailor2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1215, 567);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(15);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/captain2.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lb_main = new QLabel(centralWidget);
        lb_main->setObjectName(QStringLiteral("lb_main"));
        lb_main->setGeometry(QRect(0, 0, 1215, 567));
        lb_main->setMinimumSize(QSize(1215, 567));
        lb_main->setMaximumSize(QSize(1215, 567));
        lb_main->setPixmap(QPixmap(QString::fromUtf8(":/image/background.jpg")));
        lb_main->setScaledContents(true);
        pb_captain1 = new QPushButton(centralWidget);
        pb_captain1->setObjectName(QStringLiteral("pb_captain1"));
        pb_captain1->setGeometry(QRect(490, 393, 57, 62));
        pb_captain1->setStyleSheet(QStringLiteral("background: transparent;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/captain1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_captain1->setIcon(icon1);
        pb_captain1->setIconSize(QSize(57, 62));
        pb_captain1->setCheckable(true);
        pb_captain1->setFlat(true);
        pb_captain2 = new QPushButton(centralWidget);
        pb_captain2->setObjectName(QStringLiteral("pb_captain2"));
        pb_captain2->setGeometry(QRect(680, 390, 62, 62));
        pb_captain2->setStyleSheet(QStringLiteral("background: transparent;"));
        pb_captain2->setIcon(icon);
        pb_captain2->setIconSize(QSize(62, 62));
        pb_captain2->setCheckable(true);
        pb_captain2->setFlat(true);
        lb_terrain = new QLabel(centralWidget);
        lb_terrain->setObjectName(QStringLiteral("lb_terrain"));
        lb_terrain->setGeometry(QRect(390, 430, 441, 161));
        lb_terrain->setTextFormat(Qt::AutoText);
        lb_terrain->setPixmap(QPixmap(QString::fromUtf8(":/image/terrain.png")));
        lb_terrain->setScaledContents(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 1221, 34));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lb_color = new QLabel(layoutWidget);
        lb_color->setObjectName(QStringLiteral("lb_color"));

        horizontalLayout->addWidget(lb_color);

        lb_timer = new QLabel(layoutWidget);
        lb_timer->setObjectName(QStringLiteral("lb_timer"));

        horizontalLayout->addWidget(lb_timer);

        lb_winner = new QLabel(layoutWidget);
        lb_winner->setObjectName(QStringLiteral("lb_winner"));

        horizontalLayout->addWidget(lb_winner);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lb_box = new QLabel(centralWidget);
        lb_box->setObjectName(QStringLiteral("lb_box"));
        lb_box->setGeometry(QRect(570, 385, 77, 67));
        lb_box->setMinimumSize(QSize(77, 67));
        lb_box->setMaximumSize(QSize(77, 67));
        lb_box->setStyleSheet(QStringLiteral("background: transparent;"));
        lb_box->setPixmap(QPixmap(QString::fromUtf8(":/image/box.png")));
        lb_redscore = new QLabel(centralWidget);
        lb_redscore->setObjectName(QStringLiteral("lb_redscore"));
        lb_redscore->setGeometry(QRect(50, 70, 161, 31));
        QFont font1;
        font1.setPointSize(14);
        lb_redscore->setFont(font1);
        lb_bluescore = new QLabel(centralWidget);
        lb_bluescore->setObjectName(QStringLiteral("lb_bluescore"));
        lb_bluescore->setGeometry(QRect(1000, 70, 161, 31));
        lb_bluescore->setFont(font1);
        lb_rule = new QLabel(centralWidget);
        lb_rule->setObjectName(QStringLiteral("lb_rule"));
        lb_rule->setGeometry(QRect(50, 120, 511, 141));
        pb_sailor1 = new QPushButton(centralWidget);
        pb_sailor1->setObjectName(QStringLiteral("pb_sailor1"));
        pb_sailor1->setGeometry(QRect(430, 460, 53, 52));
        pb_sailor1->setStyleSheet(QStringLiteral("background: transparent;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/sailor1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_sailor1->setIcon(icon2);
        pb_sailor1->setIconSize(QSize(53, 52));
        pb_sailor1->setCheckable(true);
        pb_sailor1->setFlat(true);
        pb_sailor2 = new QPushButton(centralWidget);
        pb_sailor2->setObjectName(QStringLiteral("pb_sailor2"));
        pb_sailor2->setGeometry(QRect(740, 460, 53, 51));
        pb_sailor2->setStyleSheet(QStringLiteral("background: transparent;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/sailor2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_sailor2->setIcon(icon3);
        pb_sailor2->setIconSize(QSize(53, 51));
        pb_sailor2->setCheckable(true);
        pb_sailor2->setFlat(true);
        pb_bomb = new QPushButton(centralWidget);
        pb_bomb->setObjectName(QStringLiteral("pb_bomb"));
        pb_bomb->setGeometry(QRect(1170, 100, 40, 57));
        pb_bomb->setStyleSheet(QStringLiteral("background: transparent;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/bomb.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_bomb->setIcon(icon4);
        pb_bomb->setIconSize(QSize(40, 57));
        pb_bomb->setFlat(true);
        lb_sailor1 = new QLabel(centralWidget);
        lb_sailor1->setObjectName(QStringLiteral("lb_sailor1"));
        lb_sailor1->setGeometry(QRect(430, 440, 61, 16));
        QFont font2;
        font2.setPointSize(10);
        lb_sailor1->setFont(font2);
        lb_captain1 = new QLabel(centralWidget);
        lb_captain1->setObjectName(QStringLiteral("lb_captain1"));
        lb_captain1->setGeometry(QRect(490, 370, 61, 16));
        lb_captain1->setFont(font2);
        lb_captain2 = new QLabel(centralWidget);
        lb_captain2->setObjectName(QStringLiteral("lb_captain2"));
        lb_captain2->setGeometry(QRect(680, 370, 61, 16));
        lb_captain2->setFont(font2);
        lb_sailor2 = new QLabel(centralWidget);
        lb_sailor2->setObjectName(QStringLiteral("lb_sailor2"));
        lb_sailor2->setGeometry(QRect(740, 440, 61, 16));
        lb_sailor2->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\270\270\346\210\217\347\225\214\351\235\242", 0));
        lb_main->setText(QString());
        pb_captain1->setText(QString());
        pb_captain2->setText(QString());
        lb_terrain->setText(QString());
        lb_color->setText(QApplication::translate("MainWindow", "\347\272\242\346\226\271\345\233\236\345\220\210", 0));
        lb_timer->setText(QApplication::translate("MainWindow", "00\347\247\222", 0));
        lb_winner->setText(QApplication::translate("MainWindow", "\350\203\234\345\210\251\346\226\271\357\274\232\357\274\237", 0));
        lb_box->setText(QString());
        lb_redscore->setText(QApplication::translate("MainWindow", "\347\272\242\346\226\271\345\276\227\345\210\206\357\274\2320", 0));
        lb_bluescore->setText(QApplication::translate("MainWindow", "\350\223\235\346\226\271\345\276\227\345\210\206\357\274\2320", 0));
        lb_rule->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\346\270\270\346\210\217\350\247\204\345\210\231\357\274\232</p><p>\346\215\241\345\210\260\344\270\200\344\270\252\345\256\235\347\256\261\345\212\24050\345\210\206</p><p>\346\237\220\344\270\200\346\226\271\345\205\210\345\276\227100\346\210\226\345\260\206\345\217\246\344\270\200\346\226\271\345\205\250\351\230\237\344\272\272\346\266\210\347\201\255\345\215\263\350\216\267\350\203\234</p></body></html>", 0));
        pb_sailor1->setText(QString());
        pb_sailor2->setText(QString());
        pb_bomb->setText(QString());
        lb_sailor1->setText(QApplication::translate("MainWindow", "HP:100", 0));
        lb_captain1->setText(QApplication::translate("MainWindow", "HP:100", 0));
        lb_captain2->setText(QApplication::translate("MainWindow", "HP:100", 0));
        lb_sailor2->setText(QApplication::translate("MainWindow", "HP:100", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
