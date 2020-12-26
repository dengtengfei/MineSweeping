#include "GameInfo.h"

GameInfo::GameInfo(QWidget *parent)
: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	setWindowTitle(QString::fromLocal8Bit("统计信息"));
	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);

	memset(m_tGameInfo, 0, sizeof(tGameInfo) * 3);
	connect(ui.listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(setData(int)));
	connect(ui.btnClose, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.btnToZero, SIGNAL(clicked()), this, SLOT(tToZero()));
}

GameInfo::~GameInfo()
{

}

void GameInfo::showEvent(QShowEvent *e)
{
	QString strPath = QCoreApplication::applicationDirPath() + "/GameInfo.ini";
	FILE* fp = fopen(strPath.toLocal8Bit(), "rb");
	if (fp)
	{
		fread(&m_tGameInfo, sizeof(tGameInfo), 3, fp);
		fclose(fp);
	}
	setData(ui.listWidget->currentRow());
}

void GameInfo::setData(int nIndex)
{
	if (m_tGameInfo[nIndex].t_nWinCount)
	{
		ui.label->setText(QString::number(m_tGameInfo[nIndex].t_nTime[0]) + "s\t\t\t" + QString::number(m_tGameInfo[nIndex].t_sYear[0])
			+ "/" + QString::number(m_tGameInfo[nIndex].t_sMonth[0]) + "/" + QString::number(m_tGameInfo[nIndex].t_sDay[0]));
		for (int i = 1; i < 5 && i < m_tGameInfo[nIndex].t_nWinCount; ++i)
			ui.label->setText(ui.label->text() + "\n" + QString::number(m_tGameInfo[nIndex].t_nTime[i]) + "s\t\t\t" + QString::number(m_tGameInfo[nIndex].t_sYear[i])
			+ "/" + QString::number(m_tGameInfo[nIndex].t_sMonth[i])+ "/" + QString::number(m_tGameInfo[nIndex].t_sDay[i]));
	}
	else
		ui.label->clear();

	ui.labelGameCount->setText(QString::fromLocal8Bit("已玩游戏:") + QString::number(m_tGameInfo[nIndex].t_nGameCount));
	ui.labelWinCount->setText(QString::fromLocal8Bit("已胜游戏:") + QString::number(m_tGameInfo[nIndex].t_nWinCount));
	if (m_tGameInfo[nIndex].t_nWinCount == 0)
		ui.labelPercentage->setText(QString::fromLocal8Bit("获胜率:0%"));
	else
		ui.labelPercentage->setText(QString::fromLocal8Bit("获胜率:") + QString::number(100.0 * m_tGameInfo[nIndex].t_nWinCount / m_tGameInfo[nIndex].t_nGameCount, 'f', 2) + "%");
	ui.labelMaxWin->setText(QString::fromLocal8Bit("最多连胜:") + QString::number(m_tGameInfo[nIndex].t_nMaxWin));
	ui.labelMaxFailure->setText(QString::fromLocal8Bit("最多连败:") + QString::number(abs(m_tGameInfo[nIndex].t_nMaxFailure)));
	ui.labelCur->setText(QString::fromLocal8Bit("当前连局:") + QString::number(m_tGameInfo[nIndex].t_nCurStateCount));
}

void GameInfo::tToZero()
{
	memset(m_tGameInfo, 0, sizeof(tGameInfo) * 3);
	setData(ui.listWidget->currentRow());
	QString strPath = QCoreApplication::applicationDirPath() + "/GameInfo.ini";
	remove(strPath.toLocal8Bit().data());
}