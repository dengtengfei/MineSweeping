/********************************************************************************
** Form generated from reading UI file 'GameSetting.ui'
**
** Created: Sun Nov 17 20:07:21 2019
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESETTING_H
#define UI_GAMESETTING_H

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
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GameSetting
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioBtnPrimary;
    QRadioButton *radioBtnMiddle;
    QRadioButton *radioBtnAdvance;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioBtnCustom;
    QGridLayout *gridLayout_2;
    QSpinBox *spbBomb;
    QLabel *label_3;
    QLabel *label_2;
    QSpinBox *spbHeight;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *spbWidth;
    QSpacerItem *verticalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *spbCellSize;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *GameSetting)
    {
        if (GameSetting->objectName().isEmpty())
            GameSetting->setObjectName(QString::fromUtf8("GameSetting"));
        GameSetting->resize(365, 283);
        gridLayout = new QGridLayout(GameSetting);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(GameSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioBtnPrimary = new QRadioButton(groupBox);
        radioBtnPrimary->setObjectName(QString::fromUtf8("radioBtnPrimary"));
        radioBtnPrimary->setChecked(true);

        verticalLayout->addWidget(radioBtnPrimary);

        radioBtnMiddle = new QRadioButton(groupBox);
        radioBtnMiddle->setObjectName(QString::fromUtf8("radioBtnMiddle"));
        radioBtnMiddle->setChecked(false);

        verticalLayout->addWidget(radioBtnMiddle);

        radioBtnAdvance = new QRadioButton(groupBox);
        radioBtnAdvance->setObjectName(QString::fromUtf8("radioBtnAdvance"));

        verticalLayout->addWidget(radioBtnAdvance);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioBtnCustom = new QRadioButton(groupBox);
        radioBtnCustom->setObjectName(QString::fromUtf8("radioBtnCustom"));

        verticalLayout_2->addWidget(radioBtnCustom);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(12);
        spbBomb = new QSpinBox(groupBox);
        spbBomb->setObjectName(QString::fromUtf8("spbBomb"));
        spbBomb->setEnabled(false);
        spbBomb->setMinimum(10);
        spbBomb->setMaximum(4000);

        gridLayout_2->addWidget(spbBomb, 2, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(false);

        gridLayout_2->addWidget(label_3, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);

        gridLayout_2->addWidget(label_2, 1, 1, 1, 1);

        spbHeight = new QSpinBox(groupBox);
        spbHeight->setObjectName(QString::fromUtf8("spbHeight"));
        spbHeight->setEnabled(false);
        spbHeight->setMinimum(9);
        spbHeight->setMaximum(50);

        gridLayout_2->addWidget(spbHeight, 0, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(26, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        spbWidth = new QSpinBox(groupBox);
        spbWidth->setObjectName(QString::fromUtf8("spbWidth"));
        spbWidth->setEnabled(false);
        spbWidth->setMinimum(9);
        spbWidth->setMaximum(100);

        gridLayout_2->addWidget(spbWidth, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 3);

        btnOK = new QPushButton(GameSetting);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        gridLayout->addWidget(btnOK, 2, 1, 1, 1);

        btnCancel = new QPushButton(GameSetting);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        gridLayout->addWidget(btnCancel, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(GameSetting);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        spbCellSize = new QSpinBox(groupBox_2);
        spbCellSize->setObjectName(QString::fromUtf8("spbCellSize"));
        spbCellSize->setMinimum(18);
        spbCellSize->setMaximum(50);
        spbCellSize->setValue(20);

        horizontalLayout_2->addWidget(spbCellSize);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 3);

        QWidget::setTabOrder(radioBtnPrimary, radioBtnMiddle);
        QWidget::setTabOrder(radioBtnMiddle, radioBtnAdvance);
        QWidget::setTabOrder(radioBtnAdvance, radioBtnCustom);
        QWidget::setTabOrder(radioBtnCustom, spbHeight);
        QWidget::setTabOrder(spbHeight, spbWidth);
        QWidget::setTabOrder(spbWidth, spbBomb);
        QWidget::setTabOrder(spbBomb, btnOK);
        QWidget::setTabOrder(btnOK, btnCancel);

        retranslateUi(GameSetting);

        QMetaObject::connectSlotsByName(GameSetting);
    } // setupUi

    void retranslateUi(QDialog *GameSetting)
    {
        GameSetting->setWindowTitle(QApplication::translate("GameSetting", "GameSetting", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("GameSetting", "\351\232\276\345\272\246", 0, QApplication::UnicodeUTF8));
        radioBtnPrimary->setText(QApplication::translate("GameSetting", "\345\210\235\347\272\247(&B)\n"
"10\344\270\252\351\233\267\n"
"9 x 9\345\271\263\351\223\272\347\275\221\346\240\274", 0, QApplication::UnicodeUTF8));
        radioBtnMiddle->setText(QApplication::translate("GameSetting", "\344\270\255\347\272\247(&I)\n"
"40\344\270\252\351\233\267\n"
"16 x 16\345\271\263\351\223\272\347\275\221\346\240\274", 0, QApplication::UnicodeUTF8));
        radioBtnAdvance->setText(QApplication::translate("GameSetting", "\351\253\230\347\272\247(&V)\n"
"99\344\270\252\351\233\267\n"
"16 x 30\345\271\263\351\223\272\347\275\221\346\240\274", 0, QApplication::UnicodeUTF8));
        radioBtnCustom->setText(QApplication::translate("GameSetting", "\350\207\252\345\256\232\344\271\211(&U)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GameSetting", "\351\233\267\346\225\260(10-4000)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GameSetting", "\345\256\275\345\272\246(9-100)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GameSetting", "\351\253\230\345\272\246(9-50)", 0, QApplication::UnicodeUTF8));
        btnOK->setText(QApplication::translate("GameSetting", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("GameSetting", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("GameSetting", "\345\205\266\344\273\226", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("GameSetting", "\346\226\271\346\240\274\345\260\272\345\257\270(18-50)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameSetting: public Ui_GameSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESETTING_H
