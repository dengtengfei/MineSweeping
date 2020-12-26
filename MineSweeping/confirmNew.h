#ifndef CONFIRMNEW_H
#define CONFIRMNEW_H

#include <QDialog>
#include "ui_confirmNew.h"

class confirmNew : public QDialog
{
	Q_OBJECT

public:
	confirmNew(QWidget *parent = 0);
	~confirmNew();

private:
	Ui::confirmNew ui;
};

#endif // CONFIRMNEW_H
