#include "minesweeping.h"
#include "windows.h"

MineSweeping::MineSweeping(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	initVariable();
	readMap();
	initStyle();
	initTableWidget();
	initConnection();
}

MineSweeping::~MineSweeping()
{
	delete[] m_pMapData;
	if (m_pAbout)
		m_pAbout->close();
	if (m_pWinDialog)
		m_pWinDialog->close();
	if (m_pGameSetting)
		m_pGameSetting->close();
	if (m_pGameInfo)
		m_pGameInfo->close();
	if (m_pStyleSetting)
		m_pStyleSetting->close();
	if (m_pConfirmNew)
		m_pConfirmNew->close();
}

void MineSweeping::closeEvent(QCloseEvent *event)
{
	if(0 == m_bIsFinish)
		if(-1 == checkStart())
			event->ignore();
	saveConfig();
}

void MineSweeping::timerEvent(QTimerEvent *event)
{
	if (m_bIsFirstCell)
		return QMainWindow::timerEvent(event);
	ui.labelTime->setText(QString::number(m_nTimer));
	m_nTimer++;
}

void MineSweeping::mouseMoveEvent(QMouseEvent *event)
{
	//if(!ui.tableWidget->geometry().contains(this->mapFromGlobal(QCursor::pos())))
	{
		if (m_nLastHighLight >= 0 && m_nLastHighLight < m_nCellCount/* && m_pMapData && !m_pMapData[nIndex].t_bClicked*/)
			ui.tableWidget->item(m_nLastHighLight / m_nCols, m_nLastHighLight % m_nCols)->setBackground(m_brushCell);
	}
	return QMainWindow::mouseMoveEvent(event);
}

void MineSweeping::resizeEvent(QResizeEvent *event)
{
	QRect windowRect = QApplication::desktop()->rect();
	windowRect.setBottom(GetSystemMetrics(SM_CYFULLSCREEN));
	const QRect rect = frameGeometry();

	if (rect.width() <= windowRect.width() && rect.height() <= windowRect.height())
		move((windowRect.width() - rect.width()) / 2, (windowRect.height() - rect.height()) / 2);
	//else if (rect.width() >= windowRect.width() && rect.height() < windowRect.height() && rect.bottom() < windowRect.bottom())
	//	move(0,rect.top());
	//else if (rect.height() > windowRect.height() && rect.width() < windowRect.width() && rect.right() < windowRect.right())
	//	move(rect.left(), 0);
	else
		move(0, 0);

	return QMainWindow::resizeEvent(event);
}

void MineSweeping::showWindow()
{
	showNormal(); 
	raise(); 
	activateWindow();
}

void MineSweeping::saveMap()
{
	QString strPath = QCoreApplication::applicationDirPath() + "/MineSweeping.ini";
	FILE* fp = fopen(strPath.toLocal8Bit(), "wb");
	if(fp)
	{
		fwrite(&m_nTimer, sizeof(int), 1, fp);
		fwrite(&m_nLeftBombCount, sizeof(int), 1, fp);
		fwrite(m_pMapData, sizeof(mapUnit), m_nRows * m_nCols, fp);
		fclose(fp);
	}
}

void MineSweeping::readMap()
{
	readConfig();
	QString strPath = QCoreApplication::applicationDirPath() + "/MineSweeping.ini";
	FILE* fp = fopen(strPath.toLocal8Bit(), "rb");
	if(fp)
	{
		int nReply = QMessageBox::question(this, QString::fromLocal8Bit("找到保存的游戏"), QString::fromLocal8Bit("您希望继续保存的游戏吗"), QApplication::translate("MineSweepingClass", "\346\230\257", 0, QApplication::UnicodeUTF8)
			, QApplication::translate("MineSweepingClass", "\345\220\246", 0, QApplication::UnicodeUTF8));
		if(nReply == 0) 
		{
			checkMemory();
			fread(&m_nTimer, sizeof(int), 1, fp);
			fread(&m_nLeftBombCount, sizeof(int), 1, fp);
			fread(m_pMapData, sizeof(mapUnit), m_nRows * m_nCols, fp);
			m_nTimerID = this->startTimer(1000);
			m_bIsFirstCell = false;
			ui.labelBombCount->setText(QString::number(m_nLeftBombCount));
		}
		fclose(fp);
		if (nReply == 0)
			remove(strPath.toLocal8Bit().data());
	}
}

void MineSweeping::saveConfig()
{
	QString strPath = QCoreApplication::applicationDirPath() + "/Setting.ini";
	FILE* fp = fopen(strPath.toLocal8Bit(), "wb");
	if(fp)
	{
		fwrite(&m_nRank, sizeof(int), 1, fp);
		fwrite(&m_nRows, sizeof(int), 1, fp);
		fwrite(&m_nCols, sizeof(int), 1, fp);
		fwrite(&m_nBombCount, sizeof(int), 1, fp);
		fwrite(&m_nCellSize, sizeof(int), 1, fp);
		fwrite(&m_nBombStyle, sizeof(int), 1, fp);
		fwrite(&m_nCellStyle, sizeof(int), 1, fp);
		fwrite(&m_nRandomStyle, sizeof(int), 1, fp);
		fclose(fp);
	}
}

void MineSweeping::readConfig()
{
	QString strPath = QCoreApplication::applicationDirPath() + "/Setting.ini";
	FILE* fp = fopen(strPath.toLocal8Bit(), "rb");
	if(fp)
	{
		fread(&m_nRank, sizeof(int), 1, fp);
		fread(&m_nRows, sizeof(int), 1, fp);
		fread(&m_nCols, sizeof(int), 1, fp);
		fread(&m_nBombCount, sizeof(int), 1, fp);
		fread(&m_nCellSize, sizeof(int), 1, fp);
		fread(&m_nBombStyle, sizeof(int), 1, fp);
		fread(&m_nCellStyle, sizeof(int), 1, fp);
		fread(&m_nRandomStyle, sizeof(int), 1, fp);
		fclose(fp);
		m_nCellCount = m_nRows * m_nCols;
		m_nLeftBombCount = m_nBombCount;
		ui.labelBombCount->setText(QString::number(m_nBombCount));
	}
}

void MineSweeping::initStyle()
{
	ui.tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch); 
	ui.tableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
	ui.tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
	ui.tableWidget->horizontalHeader()->setVisible(false);
	ui.tableWidget->verticalHeader()->setVisible(false);

	if (m_nCellStyle == 1)
	{
		m_brushCell.setColor(QColor(56,136,72));
		m_brushCell.setTexture(m_strImageDir + "CellGreen.png");
		ui.labelTime->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
			"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
			"background-color:rgb(67,161,51);\n"
			"color:rgb(244,244,244);\n"
			"border-radius:5px"));
		ui.labelBombCount->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
			"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
			"background-color:rgb(67,161,51);\n"
			"color:rgb(244,244,244);\n"
			"border-radius:5px"));
	}
	else
	{
		m_brushCell.setColor(QColor(45,79,213));
		m_brushCell.setTexture(m_strImageDir + "CellBlue.png");
		ui.labelTime->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
			"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
			"background-color:rgb(62, 109, 191);\n"
			"color:rgb(244,244,244);\n"
			"border-radius:5px"));
		ui.labelBombCount->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
			"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
			"background-color:rgb(62, 109, 191);\n"
			"color:rgb(244,244,244);\n"
			"border-radius:5px"));
	}
	if (m_nBombStyle == 1)
	{
		m_iconBomb = QIcon(QPixmap(m_strImageDir + "bomb2.png"));
		ui.bombIcon->setStyleSheet("image: url(" + m_strImageDir + "bomb2.png);");
	}
	else
	{
		m_iconBomb = QIcon(QPixmap(m_strImageDir + "bomb.png"));
		ui.bombIcon->setStyleSheet("image: url(" + m_strImageDir + "bomb.png);");
	}
	ui.timeIcon->setStyleSheet("image: url(" + m_strImageDir + "time.png);");
	setWindowIcon(QIcon(QPixmap(m_strImageDir + "bomb.png")));
	setWindowTitle(QString::fromLocal8Bit("扫雷"));
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);

	ui.actionHelp->setShortcut(QKeySequence(tr("F1")));
	ui.actionStart->setShortcut(QKeySequence(tr("F2")));
	ui.actionInfo->setShortcut(QKeySequence(tr("F4")));
	ui.actionSetting->setShortcut(QKeySequence(tr("F5")));
	ui.actionStyle->setShortcut(QKeySequence(tr("F7")));
}

void MineSweeping::initTableWidget()
{
	ui.tableWidget->setMainWindowPtr(this);
	static QIcon iconRedFlag(QPixmap(m_strImageDir + "RedFlag.png")), iconUnknow(QPixmap(m_strImageDir + "unknow.png"));
	if (ui.tableWidget->columnCount() == 0 || m_nCellCount != m_nRows * m_nCols)
	{
		ui.tableWidget->clear();
		ui.tableWidget->setColumnCount(m_nCols);
		ui.tableWidget->setRowCount(m_nRows);
		m_nCellCount = m_nRows * m_nCols;
	}
	//ui.tableWidget->setStyleSheet("background-color:rgb(17,54,3);");
	for (int i = 0; i < m_nRows * m_nCols; i++) // 初始化界面，每个cell填充
	{
		QTableWidgetItem* pItem = ui.tableWidget->item(i / m_nCols, i % m_nCols);
		if (0 == pItem)
		{
			pItem = new QTableWidgetItem();
			ui.tableWidget->setItem(i / m_nCols, i % m_nCols, pItem);
			pItem->setTextAlignment(Qt::AlignCenter); 
			static QSize size(8,16);
			pItem->setSizeHint(size);
			pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
		}
		static QColor colorBlack(0,0,0);
		static QIcon iconNull;
		pItem->setTextColor(colorBlack);
		pItem->setIcon(iconNull);

		if (m_pMapData && m_pMapData[i].t_bClicked == false)
			ui.tableWidget->item(i / m_nCols, i % m_nCols)->setBackground(m_brushCell);
		else if (m_pMapData == NULL)
			ui.tableWidget->item(i / m_nCols, i % m_nCols)->setBackground(m_brushCell);

		if (m_pMapData == NULL)
			continue;

		if (m_pMapData[i].t_bClicked == true && m_pMapData[i].t_nCount > 0)
			pItem->setText(QString::number(m_pMapData[i].t_nCount));
		else if (m_pMapData[i].t_nState == 1)
			//ui.tableWidget->item(i / m_nCols, i % m_nCols)->setText("<|");
			ui.tableWidget->item(i / m_nCols, i % m_nCols)->setIcon(iconRedFlag);
		else if (m_pMapData[i].t_nState == 2)
			//ui.tableWidget->item(i / m_nCols, i % m_nCols)->setText("?");
			ui.tableWidget->item(i / m_nCols, i % m_nCols)->setIcon(iconUnknow);
		else if (m_pMapData[i].t_bClicked == false)
			pItem->setText("");
	}
	reSize();
}

void MineSweeping::reSize()
{
	ui.tableWidget->setMinimumSize(m_nCellSize * m_nCols, m_nCellSize * m_nRows);
	ui.tableWidget->setMaximumSize(m_nCellSize * m_nCols, m_nCellSize * m_nRows);
	//this->setFixedSize(m_nCellSize * m_nCols + 18, m_nCellSize * m_nRows + 72);
	this->setFixedSize(m_nCellSize * m_nCols + 40, m_nCellSize * m_nRows + 83);

	ui.tableWidget->setIconSize(QSize(0.75 * m_nCellSize, 0.75 * m_nCellSize));
}

void MineSweeping::initConnection()
{
	connect(ui.tableWidget, SIGNAL(itemClicked(int, int, int)), this, SLOT(cellClickeSlot(int, int, int)));
	connect(ui.actionStart, SIGNAL(triggered()), this, SLOT(newGame()));
	connect(ui.actionQuit, SIGNAL(triggered()), this, SLOT(close()));
	connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
	connect(ui.actionHelp, SIGNAL(triggered()), this, SLOT(showHelp()));
	connect(ui.actionSetting, SIGNAL(triggered()), this, SLOT(showSetting()));
	connect(ui.actionInfo, SIGNAL(triggered()), this, SLOT(showInfo()));
	connect(ui.actionStyle, SIGNAL(triggered()), this, SLOT(showStyle()));
	connect(ui.tableWidget, SIGNAL(itemHighLight(int, int)), this, SLOT(setHighLight(int, int)));
}


void MineSweeping::initVariable()
{
	m_bIsFirstCell = 1;
	m_bIsFinish = 0;
	m_nBombCount = 10;
	m_nLeftBombCount = 10;
	m_nRows = 9;
	m_nCols = 9;
	m_nTimer = 0;
	m_nRank = 0;
	m_nCellSize = 20;
	m_nBombStyle = 0;
	m_nCellStyle = 0;
	m_nRandomStyle = 0;

	m_strImageDir = QCoreApplication::applicationDirPath() + "/image/";
	m_iconRedFlag = QIcon(QPixmap(m_strImageDir + "RedFlag.png"));
	m_iconUnknow = QIcon(QPixmap(m_strImageDir + "unknow.png"));

	m_pMapData = NULL;
	m_pAbout = NULL;
	m_pWinDialog = NULL;
	m_pGameSetting = NULL;
	m_pGameInfo = NULL;
	m_pStyleSetting = NULL;
	m_pConfirmNew = NULL;

	m_nCellCount = m_nRows * m_nCols;
}

void MineSweeping::newGame()
{
	//if (m_bIsFirstCell && m_bIsFinish == false && m_nRows * m_nCols == m_nCellCount)
	//return;
	if (m_pConfirmNew == NULL)
		m_pConfirmNew = new confirmNew(this);
	if (m_bIsFinish == 0 && m_bIsFirstCell == 0)
	{
		int nRes = m_pConfirmNew->exec();
		if (nRes == 0)
			return;

		addRes(false);
	}
	if(ui.tableWidget->signalsBlocked())
		ui.tableWidget->blockSignals(false);

	m_nTimer = 0;
	m_bIsFinish = 0;
	m_bIsFirstCell = 1;
	checkMemory();
	memset(m_pMapData, 0, sizeof(mapUnit) * m_nRows * m_nCols);

	initTableWidget();
	m_nLeftBombCount = m_nBombCount;
	ui.labelTime->setText(QString::number(m_nTimer));
	ui.labelBombCount->setText(QString::number(m_nLeftBombCount));
}

void MineSweeping::restart()
{
	if (m_pConfirmNew && sender() == m_pConfirmNew)
		addRes(false);
	if(ui.tableWidget->signalsBlocked())
		ui.tableWidget->blockSignals(false);

	m_nTimer = 1;
	m_bIsFinish = 0;
	m_bIsFirstCell = 0;
	m_nLeftBombCount = m_nBombCount;
	m_nTimerID = this->startTimer(1000);
	checkMemory();

	for (int i = 0; i < m_nRows * m_nCols; ++i)
	{
		m_pMapData[i].t_bClicked = false;
		m_pMapData[i].t_nState = 0;
	}
	initTableWidget();

	ui.labelTime->setText(QString::number(m_nTimer));
	ui.labelBombCount->setText(QString::number(m_nLeftBombCount));
}

void MineSweeping::showAbout()
{
	if(m_pAbout == NULL)
	{
		m_pAbout = new About(this);
	}
	m_pAbout->show();
}

void MineSweeping::showHelp()
{
	//QDesktopServices::openUrl(QUrl(QString("https://support.microsoft.com/zh-cn/help/15060/windows-solitaire-minesweeper-hearts")));
	//http://wpa.qq.com/msgrd?v=3&uin=807775327&site=qq&menu=yes
	QDesktopServices::openUrl(QUrl::fromLocalFile(m_strImageDir + "help.chm"));
}

void MineSweeping::showSetting()
{
	if (m_pGameSetting == NULL)
		m_pGameSetting = new GameSetting(this);
	m_pGameSetting->setRank(&m_nRank);
	m_pGameSetting->setRows(&m_nRows);
	m_pGameSetting->setCols(&m_nCols);
	m_pGameSetting->setBombs(&m_nBombCount);
	m_pGameSetting->setCellSize(&m_nCellSize);
	m_pGameSetting->show();
}

void MineSweeping::showInfo()
{
	if (m_pGameInfo == NULL)
		m_pGameInfo = new GameInfo(this);
	m_pGameInfo->show();
}

void MineSweeping::showStyle()
{
	if (m_pStyleSetting== NULL)
		m_pStyleSetting = new StyleSetting(this);
	m_pStyleSetting->setBombStyle(&m_nBombStyle);
	m_pStyleSetting->setCellStyle(&m_nCellStyle);
	m_pStyleSetting->setRandomStyle(&m_nRandomStyle);
	m_pStyleSetting->show();
}

void MineSweeping::setRank()
{
	if(m_nRank == 0)
	{
		m_nRows = m_nCols = 9;
		m_nBombCount = 10;
	}
	else if(m_nRank == 1)
	{
		m_nRows = m_nCols = 16;
		m_nBombCount = 40;
	}
	else if(m_nRank == 2)
	{
		m_nRows = 16;
		m_nCols = 30;
		m_nBombCount = 99;
	}
	m_nLeftBombCount = m_nBombCount;
	newGame();
}

void MineSweeping::addRes(bool bRes)
{
	if (m_pWinDialog == NULL)
		m_pWinDialog = new WinDialog(this);

	m_pWinDialog->addRes(m_nRank, bRes, m_nTimer);
	if (bRes)
		m_pWinDialog->show();
}

void MineSweeping::setCellStyle()
{
	if (m_nCellStyle == 0)
	{
		m_brushCell.setColor(QColor(45,79,213));
		m_brushCell.setTexture(QPixmap(m_strImageDir + "CellBlue.png"));
		ui.labelTime->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
			"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
			"background-color:rgb(62, 109, 191);\n"
			"color:rgb(244,244,244);\n"
			"border-radius:5px"));
		ui.labelBombCount->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
			"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
			"background-color:rgb(62, 109, 191);\n"
			"color:rgb(244,244,244);\n"
			"border-radius:5px"));
	}
	else
	{
		m_brushCell.setColor(QColor(56,136,72));
		m_brushCell.setTexture(m_strImageDir + "CellGreen.png");
		ui.labelTime->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
			"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
			"background-color:rgb(67,161,51);\n"
			"color:rgb(244,244,244);\n"
			"border-radius:5px"));
		ui.labelBombCount->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
			"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
			"background-color:rgb(67,161,51);\n"
			"color:rgb(244,244,244);\n"
			"border-radius:5px"));
	}
	for (int i = 0; i < m_nCellCount; ++i)
		if (m_pMapData == NULL || m_pMapData[i].t_bClicked == false)
			ui.tableWidget->item(i / m_nCols, i % m_nCols)->setBackground(m_brushCell);
}

void MineSweeping::setBombStyle()
{
	if (m_nBombStyle == 0)
	{
		ui.bombIcon->setStyleSheet("image: url(" + m_strImageDir + "bomb.png);");
		m_iconBomb = QIcon(QPixmap(m_strImageDir + "bomb.png"));
	}
	else
	{
		ui.bombIcon->setStyleSheet("image: url(" + m_strImageDir + "bomb2.png);");
		m_iconBomb = QIcon(QPixmap(m_strImageDir + "bomb2.png"));
	}
}

void MineSweeping::setHighLight(int nLast, int nCur)
{
	if (nLast == nCur && nLast > m_nCols && nLast % m_nCols && nLast % m_nCols != m_nCols - 1 && nLast / m_nCols != m_nRows - 1)
		return;

	static QBrush brushBlue(QColor(118, 205, 255), m_strImageDir + "BlueHover.png"), brushGreen(QColor(106, 237, 144), m_strImageDir + "GreenHover.png");
	if (nLast >= 0 && nLast < m_nCellCount && ((m_pMapData == NULL) || m_pMapData && m_pMapData[nLast].t_bClicked == false))
		ui.tableWidget->item(nLast / m_nCols, nLast % m_nCols)->setBackground(m_brushCell);

	if (nLast < 0 || nLast >= m_nCellCount || (m_pMapData && m_pMapData[nCur].t_bClicked))
		return;

	if (m_nCellStyle == 0)
		ui.tableWidget->item(nCur / m_nCols, nCur % m_nCols)->setBackground(brushBlue);
	else
		ui.tableWidget->item(nCur / m_nCols, nCur % m_nCols)->setBackground(brushGreen);
	m_nLastHighLight = nCur;
}

void MineSweeping::cellClickeSlot(int row, int column, int type)
{
	if (m_bIsFinish == 1)
		return;
	if(m_bIsFirstCell)
	{
		if(1 == type)
			return;
		m_bIsFirstCell = 0;
		generateMap(row, column);
		if(m_nTimerID)
		{
			killTimer(m_nTimerID);
			m_nTimerID = 0;
		}
		m_nTimerID = this->startTimer(1000);
	}
	if(1 == type) // right button press
	{
		if (m_pMapData[row * m_nCols + column].t_bClicked == true) // 对有数字的点右键无反应
			return;
		++m_pMapData[row * m_nCols + column].t_nState;
		if (m_pMapData[row * m_nCols + column].t_nState >= 3)
			m_pMapData[row * m_nCols + column].t_nState = 0;
		if(m_pMapData[row * m_nCols + column].t_nState == 1)
		{
			//ui.tableWidget->item(row, column)->setText("|>");
			ui.tableWidget->item(row, column)->setIcon(m_iconRedFlag);
			m_nLeftBombCount-- ;
			ui.labelBombCount->setText(QString::number(m_nLeftBombCount));
		}
		else if(m_pMapData[row * m_nCols + column].t_nState == 2)
		{
			//ui.tableWidget->item(row, column)->setText("?");
			ui.tableWidget->item(row, column)->setIcon(m_iconUnknow);
			m_nLeftBombCount++ ;
			ui.labelBombCount->setText(QString::number(m_nLeftBombCount));
		}
		else
			//ui.tableWidget->item(row, column)->setText("");
			ui.tableWidget->item(row, column)->setIcon(QIcon());

		if(0 == checkFinish())
		{
			m_bIsFirstCell = 1;
			this->killTimer(m_nTimerID);
			m_nTimerID = 0;
			//QMessageBox::information(this, "info", "u win!");
			addRes(1);
			m_bIsFinish = 1;
		}
		return;
	}
	if(m_pMapData[row * m_nCols + column].t_nState > 0) // 对标记炸弹的点左键无反应
		return;
	if(-1 == m_pMapData[row * m_nCols + column].t_nCount) // clicke bomb, failed
	{
		//QMessageBox::warning(this, "errror", "u failed!");
		ui.tableWidget->blockSignals(true);
		for (int i = 0; i < m_nRows * m_nCols; ++i)
		{
			if (m_pMapData[i].t_nCount != -1)
				continue;
			clearCellColor(i / m_nCols, i % m_nCols);
			//ui.tableWidget->item(i / m_nCols, i % m_nCols)->setText("X");
			//ui.tableWidget->item(i / m_nCols, i % m_nCols)->setTextColor(QColor(255,0,0));
			if (i == row * m_nCols + column && m_nBombStyle == 0)
				ui.tableWidget->item(i / m_nCols, i % m_nCols)->setIcon(QIcon(QPixmap(m_strImageDir + "bombed.png")));
			else if (i == row * m_nCols + column && m_nBombStyle == 1)
				ui.tableWidget->item(i / m_nCols, i % m_nCols)->setIcon(QIcon(QPixmap(m_strImageDir + "bombed2.png")));
			else
				ui.tableWidget->item(i / m_nCols, i % m_nCols)->setIcon(m_iconBomb);
		}
		m_bIsFirstCell = 1;
		this->killTimer(m_nTimerID);
		m_nTimerID = 0;
		m_bIsFinish = 1;
		addRes(0);
		m_pWinDialog->show();
		return;
	}
	clearCellColor(row, column);
	if(0 == m_pMapData[row * m_nCols + column].t_nCount)
		check0(row, column);
	else
		ui.tableWidget->item(row, column)->setText(QString::number(m_pMapData[row * m_nCols + column].t_nCount));
	if (m_pMapData[row * m_nCols + column].t_bClicked == false)
		m_pMapData[row * m_nCols + column].t_bClicked = true;
	if(0 == checkFinish())
	{
		m_bIsFirstCell = 1;
		this->killTimer(m_nTimerID);
		m_nTimerID = 0;
		//QMessageBox::warning(this, "info", "u win!");
		addRes(1);
		m_bIsFinish = 1;
	}
}

void MineSweeping::check0(int row, int column) // 递归算法计算相邻的0
{
	if (m_pMapData[row * m_nCols + column].t_bClicked || m_pMapData[row * m_nCols + column].t_nCount == -1)
		return;
	//if (m_pMapData[row * m_nCols + column].t_bClicked == false && m_pMapData[row * m_nCols + column].t_nCount != -1)
	m_pMapData[row * m_nCols + column].t_bClicked = true;

	for(int i = row - 1; i < row + 2; i++)
	{
		if (i < 0 || i >= m_nRows)
			continue;
		for(int j = column - 1; j < column + 2; j++) // 从每个九宫格左上角开始遍历，在0-最大数之间就执行
		{
			if(j < 0 || j >= m_nCols || i == row && j == column || -1 == m_pMapData[i * m_nCols + j].t_nCount || true == m_pMapData[i * m_nCols + j].t_bClicked)
				continue;
			if (m_pMapData[i * m_nCols + j].t_nState > 0)
				continue;
			if(0 != m_pMapData[i * m_nCols + j].t_nCount)
			{
				ui.tableWidget->item(i, j)->setText(QString::number(m_pMapData[i * m_nCols + j].t_nCount));
				if (m_pMapData[i * m_nCols + j].t_bClicked == false)
					m_pMapData[i * m_nCols + j].t_bClicked = true;
				clearCellColor(i, j);
				continue;
			}
			else
			{
				clearCellColor(i, j);
				check0(i, j);
			}
		}
	}
}

int MineSweeping::checkFinish()
{
	int nCount = 0;
	if(0 == m_nLeftBombCount)
	{
		for (int i = 0; i < m_nRows * m_nCols; ++i)
			if (m_pMapData[i].t_bClicked == true)
				++nCount;
		if(nCount + m_nBombCount == m_nRows * m_nCols)
			return 0;
	}
	return -1;
}

int MineSweeping::checkStart()
{
	if(0 == m_bIsFirstCell)
	{
		int nReply = QMessageBox::question(this, QString::fromLocal8Bit("退出游戏"), QString::fromLocal8Bit("游戏正在进行，您希望做什么？"), QApplication::translate("MineSweepingClass", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8)
			, QApplication::translate("MineSweepingClass", "\344\270\215\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8)
			, QApplication::translate("MineSweepingClass", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
		if(nReply == 0) // save
		{
			saveMap();
			return 0;
		}
		else if(nReply == 1) // dont save and exit
			return 0;
		else // ignore
			return -1;
	}
	return 0;
}

void MineSweeping::checkMemory()
{
	if (m_pMapData && m_nRows * m_nCols != m_nCellCount)
	{
		delete[] m_pMapData;
		m_pMapData = new mapUnit[m_nRows * m_nCols]();
	}
	else if (m_pMapData == NULL)
		m_pMapData = new mapUnit[m_nRows * m_nCols]();
}
void MineSweeping::generateMap(int firstRowIndex, int firstColumnIndex)
{
	checkMemory();

	int index = -1;
	srand((unsigned)time(NULL));//根据时间给随机数不同的种子数
	for(int i = 0; i < m_nBombCount; i++)
	{
		index = rand()%(m_nRows * m_nCols);
		while(m_pMapData[index].t_nCount == -1 || index == firstRowIndex * m_nCols + firstColumnIndex)
			index = rand()%(m_nRows * m_nCols);
		m_pMapData[index].t_nCount = -1;
	}
	for(int i = 0; i < m_nRows * m_nCols; i++)
	{
		if(m_pMapData[i].t_nCount == -1)
			continue;
		m_pMapData[i].t_nCount = calculateAroundBombCount(i / m_nCols, i % m_nCols);
	}
}

void MineSweeping::clearCellColor(int row, int column) // 清楚所点击的颜色
{
	const static QColor colorWhite(255, 255, 255);
	ui.tableWidget->item(row, column)->setBackgroundColor(colorWhite); 
	if (row * m_nCols + column == m_nLastHighLight)
		m_nLastHighLight = -1;
}
int MineSweeping::calculateAroundBombCount(int row, int column)
{
	int nResult = 0;
	for (int i = row - 1; i < row + 2; i++)
	{
		if (i < 0 || i >= m_nRows)
			continue;
		for(int j = column - 1; j < column + 2; j++) // 从每个九宫格左上角开始遍历，在0-最大数之间就执行
		{
			if (j < 0 || j >= m_nCols)
				continue;
			if (-1 == m_pMapData[i * m_nCols + j].t_nCount)
				nResult++;
		}
	}
	return nResult;
}
