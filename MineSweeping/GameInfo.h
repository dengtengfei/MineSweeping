#ifndef GAMEINFO_H
#define GAMEINFO_H

#include <QDialog>
#include "ui_GameInfo.h"
#include "WinDialog.h"

class GameInfo : public QDialog
{
	Q_OBJECT

public:
	GameInfo(QWidget *parent = 0);
	~GameInfo();
	void showEvent(QShowEvent *);

private slots:
	void setData(int);
	void tToZero();

private:
	Ui::GameInfo ui;
	tGameInfo m_tGameInfo[3];
};

#endif // GAMEINFO_H
