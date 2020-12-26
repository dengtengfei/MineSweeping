#ifndef WINWINDOW_H
#define WINWINDOW_H

#include <QDialog>
#include "ui_WinDialog.h"

struct tGameInfo
{
	int t_nGameCount;
	int t_nWinCount;
	int t_nCurStateCount;
	int t_nMaxWin;
	int t_nMaxFailure;
	int t_nTime[5];
	int t_sYear[5];
	int t_sMonth[5];
	int t_sDay[5];
	bool t_bLastState;
};

class WinDialog : public QDialog
{
	Q_OBJECT

public:
	WinDialog(QWidget *parent = 0);
	~WinDialog();
	void addRes(int nRank, bool bWin, int nTime);

private:
	Ui::WinDialog ui;
	int m_nGameCount[3];
	int m_nWinCount[3];
	int m_nMinTime[3];
	tGameInfo m_tGameInfo[3];
};

#endif // WINWINDOW_H
