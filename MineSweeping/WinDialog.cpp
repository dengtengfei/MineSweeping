#include "WinDialog.h"
#include <QDate>

WinDialog::WinDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setModal(true);
	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
	connect(ui.btnNew, SIGNAL(clicked()), parent, SLOT(newGame()));
	connect(ui.btnNew, SIGNAL(clicked()), this, SLOT(hide()));
	connect(ui.btnExit, SIGNAL(clicked()), parent, SLOT(close()));
	connect(ui.btnRestart, SIGNAL(clicked()), parent, SLOT(restart()));
	connect(ui.btnRestart, SIGNAL(clicked()), this, SLOT(hide()));

	QString strPath = QCoreApplication::applicationDirPath() + "/GameInfo.ini";
	FILE* fp = fopen(strPath.toLocal8Bit(), "rb");
	if(fp)
	{
		fread(&m_tGameInfo, sizeof(tGameInfo), 3, fp);
		fclose(fp);
	}
	else
		memset(m_tGameInfo, 0, sizeof(tGameInfo) * 3);
}

WinDialog::~WinDialog()
{

}

void WinDialog::addRes(int nRank, bool bWin, int nTime)
{
	if (nRank > 2)
	{
		if (bWin)
		{
			setWindowTitle(QString::fromLocal8Bit("游戏胜利"));
			ui.label->setText(QString::fromLocal8Bit("恭喜！您赢了！"));
		}
		else
		{
			setWindowTitle(QString::fromLocal8Bit("游戏失败"));
			ui.label->setText(QString::fromLocal8Bit("不好意思，您输了。下次走运！"));
		}
		ui.labelTime->setText(QString::fromLocal8Bit("时间: ") + QString::number(nTime) + QString::fromLocal8Bit("秒"));
		ui.label_2->hide();
		//ui.labelTime->hide();
		ui.labelMinTime->hide();
		ui.labelDate->hide();
		ui.labelGameCount->hide();
		ui.labelWinCount->hide();
		ui.labelPercent->hide();
		return;
	}
	else
	{
		ui.label_2->show();
		ui.labelTime->show();
		ui.labelMinTime->show();
		ui.labelDate->show();
		ui.labelGameCount->show();
		ui.labelWinCount->show();
		ui.labelPercent->show();
	}

	QString strPath = QCoreApplication::applicationDirPath() + "/GameInfo.ini";
	FILE* fp = fopen(strPath.toLocal8Bit(), "rb");
	if (fp)
		fclose(fp);
	else
		memset(m_tGameInfo, 0, sizeof(tGameInfo) * 3);

	++m_tGameInfo[nRank].t_nGameCount;
	if ((bWin && m_tGameInfo[nRank].t_nWinCount == 0) || m_tGameInfo[nRank].t_bLastState != bWin)
	{
		if (bWin)
			m_tGameInfo[nRank].t_nCurStateCount = 1;
		else
			m_tGameInfo[nRank].t_nCurStateCount = -1;
	}
	else
	{
		if (bWin)
			++m_tGameInfo[nRank].t_nCurStateCount;
		else
			--m_tGameInfo[nRank].t_nCurStateCount;
	}
	if (m_tGameInfo[nRank].t_nMaxWin < m_tGameInfo[nRank].t_nCurStateCount)
		m_tGameInfo[nRank].t_nMaxWin = m_tGameInfo[nRank].t_nCurStateCount;
	if (m_tGameInfo[nRank].t_nMaxFailure > m_tGameInfo[nRank].t_nCurStateCount)
		m_tGameInfo[nRank].t_nMaxFailure = m_tGameInfo[nRank].t_nCurStateCount;
	m_tGameInfo[nRank].t_bLastState = bWin;
	if (bWin)
	{
		setWindowTitle(QString::fromLocal8Bit("游戏胜利"));
		int nYear = QDate::currentDate().year(), nMonth = QDate::currentDate().month(), nDay = QDate::currentDate().day();
		if (m_tGameInfo[nRank].t_nWinCount == 0)
		{
			m_tGameInfo[nRank].t_nTime[0] = nTime;
			m_tGameInfo[nRank].t_sYear[0] = nYear;
			m_tGameInfo[nRank].t_sMonth[0] = nMonth;
			m_tGameInfo[nRank].t_sDay[0] = nDay;
			ui.label_2->show();
		}
		else if ((m_tGameInfo[nRank].t_nWinCount < 5) ||
			(m_tGameInfo[nRank].t_nWinCount > 4 && m_tGameInfo[nRank].t_nTime[4] > nTime))
		{
			int i = (m_tGameInfo[nRank].t_nWinCount > 4 ? 4 : m_tGameInfo[nRank].t_nWinCount);
			for (; i >= 1 ; --i)
			{
				if (m_tGameInfo[nRank].t_nTime[i - 1] <= nTime)
					break;
				m_tGameInfo[nRank].t_nTime[i] = m_tGameInfo[nRank].t_nTime[i - 1];
				m_tGameInfo[nRank].t_sYear[i] = m_tGameInfo[nRank].t_sYear[i - 1];
				m_tGameInfo[nRank].t_sMonth[i] = m_tGameInfo[nRank].t_sMonth[i - 1];
				m_tGameInfo[nRank].t_sDay[i] = m_tGameInfo[nRank].t_sDay[i - 1];
			}
			m_tGameInfo[nRank].t_nTime[i] = nTime;
			m_tGameInfo[nRank].t_sYear[i] = nYear;
			m_tGameInfo[nRank].t_sMonth[i] = nMonth;
			m_tGameInfo[nRank].t_sDay[i] = nDay;
			if (i == 0)
				ui.label_2->show();
			else
				ui.label_2->hide();
		}
		else
			ui.label_2->hide();
		++m_tGameInfo[nRank].t_nWinCount;
		ui.label->setText(QString::fromLocal8Bit("恭喜！您赢了！"));
		ui.btnRestart->hide();
	}
	else
	{
		setWindowTitle(QString::fromLocal8Bit("游戏失败"));
		ui.label->setText(QString::fromLocal8Bit("不好意思，您输了。下次走运！"));
		ui.label_2->hide();
		ui.btnRestart->show();
	}
	ui.labelTime->setText(QString::fromLocal8Bit("时间: ") + QString::number(nTime) + QString::fromLocal8Bit("秒"));
	ui.labelMinTime->setText(QString::fromLocal8Bit("最佳时间: ") + QString::number(m_tGameInfo[nRank].t_nTime[0]) + QString::fromLocal8Bit("秒"));
	ui.labelDate->setText(QString::fromLocal8Bit("日期: ") + QDate::currentDate().toString("yyyy/MM/dd"));
	ui.labelGameCount->setText(QString::fromLocal8Bit("已玩游戏: ") + QString::number(m_tGameInfo[nRank].t_nGameCount));
	ui.labelWinCount->setText(QString::fromLocal8Bit("已胜游戏: ") + QString::number(m_tGameInfo[nRank].t_nWinCount));
	ui.labelPercent->setText(QString::fromLocal8Bit("百分比: ") + QString::number(100.0 * m_tGameInfo[nRank].t_nWinCount / m_tGameInfo[nRank].t_nGameCount, 'f', 2) + "%");
	fp = fopen(strPath.toLocal8Bit(), "wb");
	if(fp)
	{
		fwrite(&m_tGameInfo, sizeof(tGameInfo), 3, fp);
		fclose(fp);
	}
}