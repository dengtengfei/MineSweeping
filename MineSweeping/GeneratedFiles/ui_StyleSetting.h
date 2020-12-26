/********************************************************************************
** Form generated from reading UI file 'StyleSetting.ui'
**
** Created: Sun Nov 17 20:07:20 2019
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STYLESETTING_H
#define UI_STYLESETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StyleSetting
{
public:
    QGridLayout *gridLayout_3;
    QPushButton *btnCancel;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *label;
    QCheckBox *checkBox;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnOK;

    void setupUi(QDialog *StyleSetting)
    {
        if (StyleSetting->objectName().isEmpty())
            StyleSetting->setObjectName(QString::fromUtf8("StyleSetting"));
        StyleSetting->resize(514, 356);
        gridLayout_3 = new QGridLayout(StyleSetting);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btnCancel = new QPushButton(StyleSetting);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        gridLayout_3->addWidget(btnCancel, 5, 2, 1, 1);

        widget = new QWidget(StyleSetting);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(160, 120));
        pushButton->setMaximumSize(QSize(160, 120));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton->setCheckable(false);
        pushButton->setChecked(false);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(160, 120));
        pushButton_2->setMaximumSize(QSize(160, 120));
        pushButton_2->setStyleSheet(QString::fromUtf8(""));
        pushButton_2->setCheckable(false);

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout_3->addWidget(widget, 1, 0, 1, 4);

        label_2 = new QLabel(StyleSetting);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 2, 0, 1, 4);

        label = new QLabel(StyleSetting);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 4);

        checkBox = new QCheckBox(StyleSetting);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_3->addWidget(checkBox, 4, 0, 1, 4);

        widget_2 = new QWidget(StyleSetting);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(160, 120));
        pushButton_4->setMaximumSize(QSize(160, 120));
        pushButton_4->setStyleSheet(QString::fromUtf8(""));
        pushButton_4->setCheckable(false);

        gridLayout_2->addWidget(pushButton_4, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(160, 120));
        pushButton_3->setMaximumSize(QSize(160, 120));
        pushButton_3->setStyleSheet(QString::fromUtf8(""));
        pushButton_3->setCheckable(false);
        pushButton_3->setChecked(false);

        gridLayout_2->addWidget(pushButton_3, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 0, 1, 1);


        gridLayout_3->addWidget(widget_2, 3, 0, 1, 4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 5, 0, 1, 1);

        btnOK = new QPushButton(StyleSetting);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        gridLayout_3->addWidget(btnOK, 5, 1, 1, 1);

        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);
        QWidget::setTabOrder(pushButton_4, checkBox);
        QWidget::setTabOrder(checkBox, btnOK);
        QWidget::setTabOrder(btnOK, btnCancel);

        retranslateUi(StyleSetting);

        QMetaObject::connectSlotsByName(StyleSetting);
    } // setupUi

    void retranslateUi(QDialog *StyleSetting)
    {
        StyleSetting->setWindowTitle(QApplication::translate("StyleSetting", "StyleSetting", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("StyleSetting", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label_2->setText(QApplication::translate("StyleSetting", "\351\200\211\346\213\251\346\243\213\347\233\230", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StyleSetting", "\351\200\211\346\213\251\346\270\270\346\210\217\346\240\267\345\274\217", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("StyleSetting", "\351\232\217\346\234\272\351\200\211\346\213\251\346\270\270\346\210\217\346\240\267\345\274\217\345\222\214\351\224\256\347\233\230(&R)", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QString());
        pushButton_3->setText(QString());
        btnOK->setText(QApplication::translate("StyleSetting", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StyleSetting: public Ui_StyleSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLESETTING_H
