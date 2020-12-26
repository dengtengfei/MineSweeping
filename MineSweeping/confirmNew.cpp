#include "confirmNew.h"

confirmNew::confirmNew(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.btnNew, SIGNAL(clicked()), this, SLOT(accept()));
	connect(ui.btnRestart, SIGNAL(clicked()), parent, SLOT(restart()));
	connect(ui.btnRestart, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

confirmNew::~confirmNew()
{

}
