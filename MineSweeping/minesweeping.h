#ifndef MINESWEEPING_H
#define MINESWEEPING_H

#include <QtGui/QMainWindow>
#include "ui_minesweeping.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QDir>
#include <QDesktopWidget>
#include "time.h"
#include "About.h"
#include "WinDialog.h"
#include "GameSetting.h"
#include "GameInfo.h"
#include "StyleSetting.h"
#include "confirmNew.h"
//#define CELL_SIZE 20
struct mapUnit
{
	int t_nState;
	int t_nCount;
	bool t_bClicked;
};
class MineSweeping : public QMainWindow
{
	Q_OBJECT

public:
	MineSweeping(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MineSweeping();

private:
	void initStyle();
	void initTableWidget();
	void initConnection();
	void initVariable();
	void timerEvent(QTimerEvent *event);
	void closeEvent(QCloseEvent *event);
	void mouseMoveEvent(QMouseEvent *);
	void resizeEvent(QResizeEvent *);

	void generateMap(int firstRowIndex, int firstColumnIndex);
	int calculateAroundBombCount(int row, int column);
	void check0(int row, int column);
	int checkStart();
	int checkFinish();
	void clearCellColor(int row, int column);
	void saveMap();
	void readMap();
	void saveConfig();
	void readConfig();
	void checkMemory();
	void addRes(bool bRes);

	mapUnit* m_pMapData;
	bool m_bIsFirstCell;
	bool m_bIsFinish;
	int m_nBombCount;
	int m_nRows;
	int m_nCols;
	int m_nCellCount;
	int m_nLeftBombCount;
	int m_nTimer;
	int m_nTimerID;
	int m_nRank;
	int m_nCellSize;
	int m_nBombStyle;
	int m_nCellStyle;
	int m_nRandomStyle;
	int m_nLastHighLight;
	QString m_strImageDir;
	QBrush m_brushCell;
	QIcon m_iconRedFlag, m_iconUnknow, m_iconBomb;

	About* m_pAbout;
	WinDialog* m_pWinDialog;
	GameSetting* m_pGameSetting;
	GameInfo* m_pGameInfo;
	StyleSetting* m_pStyleSetting;
	confirmNew* m_pConfirmNew;

public slots:
	void cellClickeSlot(int row, int column, int type);
	void newGame();
	void restart();
	void showAbout();
	void showHelp();
	void showSetting();
	void showInfo();
	void showStyle();
	void setRank();
	void reSize();
	void setBombStyle();
	void setCellStyle();
	void setHighLight(int, int);
	void showWindow();

private:
	Ui::MineSweepingClass ui;
};

#endif // MINESWEEPING_H
