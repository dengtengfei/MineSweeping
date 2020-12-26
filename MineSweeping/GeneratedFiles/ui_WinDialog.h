/********************************************************************************
** Form generated from reading UI file 'WinDialog.ui'
**
** Created: Sun Nov 17 20:07:19 2019
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDIALOG_H
#define UI_WINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WinDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelTime;
    QGridLayout *gridLayout;
    QLabel *labelGameCount;
    QLabel *labelWinCount;
    QLabel *labelDate;
    QLabel *labelMinTime;
    QLabel *labelPercent;
    QGridLayout *gridLayout_2;
    QPushButton *btnNew;
    QPushButton *btnRestart;
    QPushButton *btnExit;

    void setupUi(QDialog *WinDialog)
    {
        if (WinDialog->objectName().isEmpty())
            WinDialog->setObjectName(QString::fromUtf8("WinDialog"));
        WinDialog->resize(380, 287);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WinDialog->sizePolicy().hasHeightForWidth());
        WinDialog->setSizePolicy(sizePolicy);
        WinDialog->setMinimumSize(QSize(380, 0));
        verticalLayout_3 = new QVBoxLayout(WinDialog);
        verticalLayout_3->setSpacing(26);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 17, -1, 17);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(WinDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(WinDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelTime = new QLabel(WinDialog);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));

        verticalLayout_2->addWidget(labelTime);


        verticalLayout_3->addLayout(verticalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(12);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelGameCount = new QLabel(WinDialog);
        labelGameCount->setObjectName(QString::fromUtf8("labelGameCount"));

        gridLayout->addWidget(labelGameCount, 2, 0, 1, 1);

        labelWinCount = new QLabel(WinDialog);
        labelWinCount->setObjectName(QString::fromUtf8("labelWinCount"));

        gridLayout->addWidget(labelWinCount, 3, 0, 1, 1);

        labelDate = new QLabel(WinDialog);
        labelDate->setObjectName(QString::fromUtf8("labelDate"));

        gridLayout->addWidget(labelDate, 1, 1, 1, 1);

        labelMinTime = new QLabel(WinDialog);
        labelMinTime->setObjectName(QString::fromUtf8("labelMinTime"));

        gridLayout->addWidget(labelMinTime, 1, 0, 1, 1);

        labelPercent = new QLabel(WinDialog);
        labelPercent->setObjectName(QString::fromUtf8("labelPercent"));

        gridLayout->addWidget(labelPercent, 3, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(12);
        gridLayout_2->setVerticalSpacing(5);
        btnNew = new QPushButton(WinDialog);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));
        btnNew->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(btnNew, 0, 2, 1, 1);

        btnRestart = new QPushButton(WinDialog);
        btnRestart->setObjectName(QString::fromUtf8("btnRestart"));
        btnRestart->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(btnRestart, 0, 1, 1, 1);

        btnExit = new QPushButton(WinDialog);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(btnExit, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);


        retranslateUi(WinDialog);

        QMetaObject::connectSlotsByName(WinDialog);
    } // setupUi

    void retranslateUi(QDialog *WinDialog)
    {
        WinDialog->setWindowTitle(QApplication::translate("WinDialog", "WinDialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WinDialog", "\346\201\255\345\226\234\357\274\201\346\202\250\350\265\242\344\272\206\357\274\201", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WinDialog", "\346\202\250\346\211\200\347\224\250\347\232\204\346\227\266\351\227\264\346\230\257\350\277\231\344\270\252\351\232\276\345\272\246\347\272\247\345\210\253\347\232\204\346\234\200\347\237\255\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        labelTime->setText(QApplication::translate("WinDialog", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        labelGameCount->setText(QApplication::translate("WinDialog", "\345\267\262\347\216\251\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        labelWinCount->setText(QApplication::translate("WinDialog", "\345\267\262\350\203\234\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        labelDate->setText(QApplication::translate("WinDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        labelMinTime->setText(QApplication::translate("WinDialog", "\346\234\200\344\275\263\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        labelPercent->setText(QApplication::translate("WinDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        btnNew->setText(QApplication::translate("WinDialog", "\345\206\215\347\216\251\344\270\200\345\261\200(&P)", 0, QApplication::UnicodeUTF8));
        btnRestart->setText(QApplication::translate("WinDialog", "\351\207\215\346\226\260\345\274\200\345\247\213\350\277\231\344\270\252\346\270\270\346\210\217(&R)", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("WinDialog", "\351\200\200\345\207\272(&X)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WinDialog: public Ui_WinDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDIALOG_H
