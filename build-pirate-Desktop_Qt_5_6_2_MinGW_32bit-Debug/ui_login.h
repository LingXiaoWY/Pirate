/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *lb_main;
    QPushButton *pb_start;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(982, 717);
        login->setMinimumSize(QSize(982, 717));
        login->setMaximumSize(QSize(982, 717));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/captain2.png"), QSize(), QIcon::Normal, QIcon::Off);
        login->setWindowIcon(icon);
        lb_main = new QLabel(login);
        lb_main->setObjectName(QStringLiteral("lb_main"));
        lb_main->setGeometry(QRect(0, 0, 982, 717));
        lb_main->setPixmap(QPixmap(QString::fromUtf8(":/image/login.jpg")));
        pb_start = new QPushButton(login);
        pb_start->setObjectName(QStringLiteral("pb_start"));
        pb_start->setGeometry(QRect(349, 335, 287, 45));
        pb_start->setStyleSheet(QStringLiteral("background: transparent;"));
        pb_start->setFlat(true);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "\346\265\267\347\233\227\345\206\233\345\233\242\346\212\242\345\256\235\350\227\217", 0));
        lb_main->setText(QString());
        pb_start->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
