#include "GameSetting.h"

GameSetting::GameSetting(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	setWindowTitle(QString::fromLocal8Bit("СЎПо"));
	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
	connect(ui.radioBtnCustom, SIGNAL(toggled(bool)), this, SLOT(showCostume(bool)));
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(setValue()));
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.spbBomb, SIGNAL(valueChanged(int)), this, SLOT(setBombs(int)));
	connect(this, SIGNAL(setRank()), parent, SLOT(setRank()));
	connect(this, SIGNAL(resize()), parent, SLOT(reSize()));
}

GameSetting::~GameSetting()
{

}

void GameSetting::showEvent(QShowEvent *event)
{
	if (*m_pRank == 0 && ui.radioBtnPrimary->isChecked() == false)
		ui.radioBtnPrimary->setChecked(true);
	if (*m_pRank == 1 && ui.radioBtnMiddle->isChecked() == false)
		ui.radioBtnMiddle->setChecked(true);
	if (*m_pRank == 2 && ui.radioBtnAdvance->isChecked() == false)
		ui.radioBtnAdvance->setChecked(true);
	if (*m_pRank == 3)
	{
		if (ui.radioBtnCustom->isChecked() == false)
			ui.radioBtnCustom->setChecked(true);
		ui.spbHeight->setValue(*m_pRows);
		ui.spbWidth->setValue(*m_pCols);
		ui.spbBomb->setValue(*m_pBombs);
	}
	ui.spbCellSize->setValue(*m_pCellSize);
	return QDialog::showEvent(event);
}

void GameSetting::showCostume(bool bShow)
{
	if (bShow)
	{
		ui.label->setEnabled(true);
		ui.label_2->setEnabled(true);
		ui.label_3->setEnabled(true);
		ui.spbHeight->setEnabled(true);
		ui.spbWidth->setEnabled(true);
		ui.spbBomb->setEnabled(true);
	}
	else
	{
		ui.label->setEnabled(false);
		ui.label_2->setEnabled(false);
		ui.label_3->setEnabled(false);
		ui.spbHeight->setEnabled(false);
		ui.spbWidth->setEnabled(false);
		ui.spbBomb->setEnabled(false);
	}
}

void GameSetting::setValue()
{
	if (*m_pCellSize != ui.spbCellSize->value())
	{
		*m_pCellSize = ui.spbCellSize->value();
		emit resize();
	}
	if (*m_pRank != 0 && ui.radioBtnPrimary->isChecked())
		*m_pRank = 0;
	else if (*m_pRank != 1 && ui.radioBtnMiddle->isChecked())
		*m_pRank = 1;
	else if (*m_pRank != 2 && ui.radioBtnAdvance->isChecked())
		*m_pRank = 2;
	else if (ui.radioBtnCustom->isChecked())
	{
		*m_pRank = 3;
		if (*m_pRows != ui.spbHeight->value())
			*m_pRows = ui.spbHeight->value();
		if (*m_pCols != ui.spbWidth->value())
			*m_pCols = ui.spbWidth->value();
		if (*m_pBombs != ui.spbBomb->value())
			*m_pBombs = ui.spbBomb->value();
	}
	else
		return;
	emit setRank();
}

void GameSetting::setBombs(int nBombs)
{
	if (nBombs > ui.spbHeight->value() * ui.spbWidth->value() * 0.8)
		nBombs = ui.spbHeight->value() * ui.spbWidth->value() * 0.8;
	ui.spbBomb->blockSignals(true);
	ui.spbBomb->setValue(nBombs);
	ui.spbBomb->blockSignals(false);
}