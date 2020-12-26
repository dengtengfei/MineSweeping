#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QTimer>
#include <QDesktopServices>
#include <QUrl> 
#include "ui_About.h"

class About : public QDialog
{
	Q_OBJECT

public:
	About(QWidget *parent = 0);
	~About();
private slots:
	void onButtonClicked();
	void contactByQQ();
private:
	Ui::About ui;
	QDialog* m_pCopyDialog;
	QTimer* m_pTimer;
};

#endif // ABOUT_H
