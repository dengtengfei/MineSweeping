/********************************************************************************
** Form generated from reading UI file 'minesweeping.ui'
**
** Created: Sun Nov 17 20:07:21 2019
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINESWEEPING_H
#define UI_MINESWEEPING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>
#include "itablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MineSweepingClass
{
public:
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionQuit;
    QAction *action;
    QAction *action_3;
    QAction *actionInfo;
    QAction *actionSetting;
    QAction *actionStyle;
    QAction *actionStart;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *labelTime;
    QLabel *bombIcon;
    QLabel *labelBombCount;
    QSpacerItem *horizontalSpacer_2;
    QLabel *timeIcon;
    ITableWidget *tableWidget;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_3;

    void setupUi(QMainWindow *MineSweepingClass)
    {
        if (MineSweepingClass->objectName().isEmpty())
            MineSweepingClass->setObjectName(QString::fromUtf8("MineSweepingClass"));
        MineSweepingClass->resize(192, 243);
        MineSweepingClass->setMouseTracking(true);
        MineSweepingClass->setStyleSheet(QString::fromUtf8(""));
        actionHelp = new QAction(MineSweepingClass);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout = new QAction(MineSweepingClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionQuit = new QAction(MineSweepingClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        action = new QAction(MineSweepingClass);
        action->setObjectName(QString::fromUtf8("action"));
        action_3 = new QAction(MineSweepingClass);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        actionInfo = new QAction(MineSweepingClass);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        actionSetting = new QAction(MineSweepingClass);
        actionSetting->setObjectName(QString::fromUtf8("actionSetting"));
        actionStyle = new QAction(MineSweepingClass);
        actionStyle->setObjectName(QString::fromUtf8("actionStyle"));
        actionStart = new QAction(MineSweepingClass);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        centralWidget = new QWidget(MineSweepingClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMouseTracking(true);
        centralWidget->setStyleSheet(QString::fromUtf8("/*QWidget#centralWidget\n"
"{\n"
"	background-color: rgb(217, 226, 235);\n"
"}*/"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(20, 20, 20, 9);
        labelTime = new QLabel(centralWidget);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setMinimumSize(QSize(30, 0));
        labelTime->setMouseTracking(true);
        labelTime->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color:rgb(150,150,150);\n"
"color:rgb(244,244,244);\n"
"border-radius:5px"));
        labelTime->setFrameShape(QFrame::WinPanel);
        labelTime->setFrameShadow(QFrame::Sunken);
        labelTime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelTime, 2, 3, 1, 1);

        bombIcon = new QLabel(centralWidget);
        bombIcon->setObjectName(QString::fromUtf8("bombIcon"));
        bombIcon->setMinimumSize(QSize(25, 25));
        bombIcon->setMouseTracking(true);

        gridLayout->addWidget(bombIcon, 2, 6, 1, 1);

        labelBombCount = new QLabel(centralWidget);
        labelBombCount->setObjectName(QString::fromUtf8("labelBombCount"));
        labelBombCount->setMinimumSize(QSize(30, 0));
        labelBombCount->setMouseTracking(true);
        labelBombCount->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color:rgb(150,150,150);\n"
"color:rgb(244,244,244);\n"
"border-radius:5px"));
        labelBombCount->setFrameShape(QFrame::WinPanel);
        labelBombCount->setFrameShadow(QFrame::Sunken);
        labelBombCount->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelBombCount, 2, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        timeIcon = new QLabel(centralWidget);
        timeIcon->setObjectName(QString::fromUtf8("timeIcon"));
        timeIcon->setMinimumSize(QSize(25, 25));
        timeIcon->setMouseTracking(true);

        gridLayout->addWidget(timeIcon, 2, 2, 1, 1);

        tableWidget = new ITableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMouseTracking(true);
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget->verticalHeader()->setMinimumSectionSize(10);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 8);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 7, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 4, 1, 1);

        MineSweepingClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MineSweepingClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 192, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MineSweepingClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(actionStart);
        menu->addAction(actionInfo);
        menu->addAction(actionSetting);
        menu->addAction(actionStyle);
        menu->addSeparator();
        menu->addAction(actionQuit);
        menu_3->addAction(actionHelp);
        menu_3->addSeparator();
        menu_3->addAction(actionAbout);

        retranslateUi(MineSweepingClass);

        QMetaObject::connectSlotsByName(MineSweepingClass);
    } // setupUi

    void retranslateUi(QMainWindow *MineSweepingClass)
    {
        MineSweepingClass->setWindowTitle(QApplication::translate("MineSweepingClass", "MineSweeping", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MineSweepingClass", "\346\237\245\347\234\213\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionHelp->setStatusTip(QApplication::translate("MineSweepingClass", "\346\237\245\347\234\213\346\211\253\351\233\267\345\270\256\345\212\251\346\226\207\346\241\243(\344\273\216Window\346\217\220\345\217\226)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionAbout->setText(QApplication::translate("MineSweepingClass", "\345\205\263\344\272\216\346\211\253\351\233\267", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MineSweepingClass", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MineSweepingClass", "\346\230\257\345\220\246", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("MineSweepingClass", "\347\273\237\350\256\241\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        actionInfo->setText(QApplication::translate("MineSweepingClass", "\347\273\237\350\256\241\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        actionSetting->setText(QApplication::translate("MineSweepingClass", "\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        actionStyle->setText(QApplication::translate("MineSweepingClass", "\346\233\264\346\224\271\345\244\226\350\247\202", 0, QApplication::UnicodeUTF8));
        actionStart->setText(QApplication::translate("MineSweepingClass", "\346\226\260\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        labelTime->setText(QApplication::translate("MineSweepingClass", "0", 0, QApplication::UnicodeUTF8));
        bombIcon->setText(QString());
        labelBombCount->setText(QApplication::translate("MineSweepingClass", "10", 0, QApplication::UnicodeUTF8));
        timeIcon->setText(QString());
        menu->setTitle(QApplication::translate("MineSweepingClass", "\346\270\270\346\210\217(&G)", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MineSweepingClass", "\345\270\256\345\212\251(&H)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MineSweepingClass: public Ui_MineSweepingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINESWEEPING_H
