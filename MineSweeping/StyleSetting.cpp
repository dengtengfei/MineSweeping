#include "StyleSetting.h"

StyleSetting::StyleSetting(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	setWindowTitle(QString::fromLocal8Bit("更改外观"));
	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(setBomb()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(setBomb()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(setStyle()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(setStyle()));
	connect(this, SIGNAL(emitCellStyle()), parent, SLOT(setCellStyle()));
	connect(this, SIGNAL(emitBombStyle()), parent, SLOT(setBombStyle()));
	connect(ui.checkBox, SIGNAL(stateChanged(int)), this, SLOT(setRandom(int)));
	//connect(ui.btnOK, SIGNAL(clicked()), parent, SLOT(setCellStyle()));
	//connect(ui.btnOK, SIGNAL(clicked()), parent, SLOT(setBombStyle()));
	//connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(confirm()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

StyleSetting::~StyleSetting()
{

}

void StyleSetting::showEvent(QShowEvent *e)
{
	setStyle();
	setBomb();
	ui.checkBox->setChecked(*m_pRandom);
	return QDialog::showEvent(e);
}

void StyleSetting::setRandom(int nChecked)
{
	*m_pRandom = nChecked;
}

void StyleSetting::setStyle()
{
	QString strImageDir = QCoreApplication::applicationDirPath() + "/image/";
	if (sender() == ui.pushButton_3 || (sender() == NULL && *m_pCellStyle == 0))
	{
		ui.pushButton_3->setStyleSheet("border-image: url(" + strImageDir + "style1Selected.png);\n""border:none;");
		ui.pushButton_4->setStyleSheet("border-image: url(" + strImageDir + "style2Unselected.png);\n""border:none;");
		//if (*m_pCellStyle == 1)
		//{
		//	*m_pCellStyle = 0;
		//	emit emitCellStyle();
		//}
		m_nLastCellStyle = 0;
		if (*m_pRandom)
			*m_pCellStyle = rand() % 2;
		else
			*m_pCellStyle = 0;
	}
	else if (sender() == ui.pushButton_4 || (sender() == NULL && *m_pCellStyle == 1))
	{
		ui.pushButton_3->setStyleSheet("border-image: url(" + strImageDir + "style1Unselected.png);\n""border:none;");
		ui.pushButton_4->setStyleSheet("border-image: url(" + strImageDir + "style2Selected.png);\n""border:none;");
		//if (*m_pCellStyle == 0)
		//{
		//	*m_pCellStyle = 1;
		//	emit emitCellStyle();
		//}
		m_nLastCellStyle = 1;
		if (*m_pRandom)
			*m_pCellStyle = rand() % 2;
		else
			*m_pCellStyle = 1;
	}
}

void StyleSetting::setBomb()
{
	QString strImageDir = QCoreApplication::applicationDirPath() + "/image/";
	if (sender() == ui.pushButton || (sender() == NULL && *m_pBombStyle == 0))
	{
		ui.pushButton->setStyleSheet("border-image: url(" + strImageDir + "bomb1Selected.png);\n""border:none;");
		ui.pushButton_2->setStyleSheet("border-image: url(" + strImageDir + "bomb2Unselected.png);\n""border:none;");
		//if (*m_pBombStyle == 1)
		//{
		//	*m_pBombStyle = 0;
		//	emit emitBombStyle();
		//}
		m_nLastBombStyle = 0;
		if (*m_pRandom)
			*m_pBombStyle = rand() % 2;
		else
			*m_pBombStyle = 0;
	}
	else if (sender() == ui.pushButton_2 || (sender() == NULL && *m_pBombStyle == 1))
	{
		ui.pushButton->setStyleSheet("border-image: url(" + strImageDir + "bomb1Unselected.png);\n""border:none;");
		ui.pushButton_2->setStyleSheet("border-image: url(" + strImageDir + "bomb2Selected.png);\n""border:none;");
		//if (*m_pBombStyle == 0)
		//{
		//	*m_pBombStyle = 1;
		//	emit emitBombStyle();
		//}
		m_nLastBombStyle = 1;
		if (*m_pRandom)
			*m_pBombStyle = rand() % 2;
		else
			*m_pBombStyle = 1;
	}
}

void StyleSetting::confirm()
{
	if (*m_pRandom)
	{
		*m_pBombStyle = rand() % 2;
		*m_pCellStyle = rand() % 2;
	}
	else
	{
		*m_pBombStyle = m_nLastBombStyle;
		*m_pCellStyle = m_nLastCellStyle;
	}
	emit emitBombStyle();
	emit emitCellStyle();
	close();
}