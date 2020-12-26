#ifndef GAMESETTING_H
#define GAMESETTING_H

#include <QDialog>
#include "ui_GameSetting.h"

class GameSetting : public QDialog
{
	Q_OBJECT

public:
	GameSetting(QWidget *parent = 0);
	~GameSetting();
	void showEvent(QShowEvent *);
	void setRank(int* pRank) {m_pRank = pRank;}
	void setCols(int* pCols) {m_pCols = pCols;}
	void setRows(int* pCols) {m_pRows = pCols;}
	void setBombs(int* pBombs) {m_pBombs = pBombs;}
	void setCellSize(int* pSize) {m_pCellSize = pSize;}

signals:
	void setRank();
	void resize();

private slots:
	void showCostume(bool bShow);
	void setValue();
	void setBombs(int);

private:
	Ui::GameSetting ui;
	int* m_pRank;
	int* m_pCols;
	int* m_pRows;
	int* m_pBombs;
	int* m_pCellSize;
};

#endif // GAMESETTING_H
