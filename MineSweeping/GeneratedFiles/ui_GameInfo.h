/********************************************************************************
** Form generated from reading UI file 'GameInfo.ui'
**
** Created: Sun Nov 17 20:07:21 2019
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEINFO_H
#define UI_GAMEINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GameInfo
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelGameCount;
    QLabel *labelWinCount;
    QLabel *labelPercentage;
    QLabel *labelMaxWin;
    QLabel *labelMaxFailure;
    QLabel *labelCur;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;
    QPushButton *btnToZero;

    void setupUi(QDialog *GameInfo)
    {
        if (GameInfo->objectName().isEmpty())
            GameInfo->setObjectName(QString::fromUtf8("GameInfo"));
        GameInfo->resize(684, 216);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameInfo->sizePolicy().hasHeightForWidth());
        GameInfo->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(GameInfo);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(GameInfo);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(160, 80));

        verticalLayout->addWidget(listWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(GameInfo);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(240, 0));
        groupBox->setMaximumSize(QSize(16777215, 100));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelGameCount = new QLabel(GameInfo);
        labelGameCount->setObjectName(QString::fromUtf8("labelGameCount"));
        labelGameCount->setMinimumSize(QSize(240, 0));

        verticalLayout_4->addWidget(labelGameCount);

        labelWinCount = new QLabel(GameInfo);
        labelWinCount->setObjectName(QString::fromUtf8("labelWinCount"));

        verticalLayout_4->addWidget(labelWinCount);

        labelPercentage = new QLabel(GameInfo);
        labelPercentage->setObjectName(QString::fromUtf8("labelPercentage"));

        verticalLayout_4->addWidget(labelPercentage);

        labelMaxWin = new QLabel(GameInfo);
        labelMaxWin->setObjectName(QString::fromUtf8("labelMaxWin"));

        verticalLayout_4->addWidget(labelMaxWin);

        labelMaxFailure = new QLabel(GameInfo);
        labelMaxFailure->setObjectName(QString::fromUtf8("labelMaxFailure"));

        verticalLayout_4->addWidget(labelMaxFailure);

        labelCur = new QLabel(GameInfo);
        labelCur->setObjectName(QString::fromUtf8("labelCur"));

        verticalLayout_4->addWidget(labelCur);


        gridLayout->addLayout(verticalLayout_4, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnClose = new QPushButton(GameInfo);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setMinimumSize(QSize(155, 28));

        horizontalLayout->addWidget(btnClose);

        btnToZero = new QPushButton(GameInfo);
        btnToZero->setObjectName(QString::fromUtf8("btnToZero"));
        btnToZero->setMinimumSize(QSize(155, 28));

        horizontalLayout->addWidget(btnToZero);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 3);


        retranslateUi(GameInfo);

        listWidget->setCurrentRow(0);


        QMetaObject::connectSlotsByName(GameInfo);
    } // setupUi

    void retranslateUi(QDialog *GameInfo)
    {
        GameInfo->setWindowTitle(QApplication::translate("GameInfo", "GameInfo", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("GameInfo", "\345\210\235\347\272\247", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("GameInfo", "\344\270\255\347\272\247", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("GameInfo", "\351\253\230\347\272\247", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QApplication::translate("GameInfo", "\346\234\200\344\275\263\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GameInfo", "TextLabel", 0, QApplication::UnicodeUTF8));
        labelGameCount->setText(QApplication::translate("GameInfo", "TextLabel", 0, QApplication::UnicodeUTF8));
        labelWinCount->setText(QApplication::translate("GameInfo", "TextLabel", 0, QApplication::UnicodeUTF8));
        labelPercentage->setText(QApplication::translate("GameInfo", "TextLabel", 0, QApplication::UnicodeUTF8));
        labelMaxWin->setText(QApplication::translate("GameInfo", "TextLabel", 0, QApplication::UnicodeUTF8));
        labelMaxFailure->setText(QApplication::translate("GameInfo", "TextLabel", 0, QApplication::UnicodeUTF8));
        labelCur->setText(QApplication::translate("GameInfo", "TextLabel", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("GameInfo", "\345\205\263\351\227\255(&C)", 0, QApplication::UnicodeUTF8));
        btnToZero->setText(QApplication::translate("GameInfo", "\351\207\215\347\275\256(&R)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameInfo: public Ui_GameInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEINFO_H
