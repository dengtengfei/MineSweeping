/********************************************************************************
** Form generated from reading UI file 'confirmNew.ui'
**
** Created: Sun Nov 17 20:07:21 2019
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMNEW_H
#define UI_CONFIRMNEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_confirmNew
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCommandLinkButton *btnNew;
    QCommandLinkButton *btnRestart;
    QCommandLinkButton *btnCancel;

    void setupUi(QDialog *confirmNew)
    {
        if (confirmNew->objectName().isEmpty())
            confirmNew->setObjectName(QString::fromUtf8("confirmNew"));
        confirmNew->resize(462, 299);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(confirmNew->sizePolicy().hasHeightForWidth());
        confirmNew->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(confirmNew);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(confirmNew);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 150, 225);"));

        verticalLayout->addWidget(label);

        btnNew = new QCommandLinkButton(confirmNew);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));
        btnNew->setMinimumSize(QSize(0, 70));

        verticalLayout->addWidget(btnNew);

        btnRestart = new QCommandLinkButton(confirmNew);
        btnRestart->setObjectName(QString::fromUtf8("btnRestart"));
        btnRestart->setMinimumSize(QSize(0, 70));

        verticalLayout->addWidget(btnRestart);

        btnCancel = new QCommandLinkButton(confirmNew);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(0, 70));

        verticalLayout->addWidget(btnCancel);


        retranslateUi(confirmNew);

        QMetaObject::connectSlotsByName(confirmNew);
    } // setupUi

    void retranslateUi(QDialog *confirmNew)
    {
        confirmNew->setWindowTitle(QApplication::translate("confirmNew", "confirmNew", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("confirmNew", "\346\270\270\346\210\217\346\255\243\345\234\250\350\277\233\350\241\214\357\274\214\346\202\250\345\270\214\346\234\233\345\201\232\344\273\200\344\271\210\357\274\237", 0, QApplication::UnicodeUTF8));
        btnNew->setText(QApplication::translate("confirmNew", "\351\200\200\345\207\272\345\271\266\351\207\215\346\226\260\345\274\200\345\247\213\346\270\270\346\210\217(&N)\n"
"\346\234\254\345\261\200\345\260\206\344\275\234\344\270\272\345\244\261\350\264\245\350\256\260\345\205\245\347\273\237\350\256\241\344\277\241\346\201\257\343\200\202", 0, QApplication::UnicodeUTF8));
        btnRestart->setText(QApplication::translate("confirmNew", "\351\207\215\346\226\260\345\274\200\345\247\213\350\277\231\344\270\252\346\270\270\346\210\217(&R)\n"
"\346\234\254\345\261\200\345\260\206\344\275\234\344\270\272\345\244\261\350\264\245\350\256\260\345\205\245\347\273\237\350\256\241\344\277\241\346\201\257\343\200\202", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("confirmNew", "\347\273\247\347\273\255\346\270\270\346\210\217(&K)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class confirmNew: public Ui_confirmNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMNEW_H
