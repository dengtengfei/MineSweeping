#include "About.h"
#include <QClipboard>
#include <QMessageBox>

About::About(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("关于扫雷"));
	setModal(true);
	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
	connect(ui.btnClose, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.btnContact, SIGNAL(clicked()), this, SLOT(contactByQQ()));
	m_pCopyDialog = NULL;
	m_pTimer = new QTimer(this);
	m_pTimer->setSingleShot(true);
	ui.labelIcon->setStyleSheet("image: url(" + QApplication::applicationDirPath() + "/image/mine.png);\n");
	ui.btnContact->setStyleSheet("border-image: url(" + QApplication::applicationDirPath() + "/image/ContactByQQ.png);\n");
}

About::~About()
{

}

void About::onButtonClicked()
{
	QString strAddr = ui.pushButton->text();
	QClipboard *pClipboard = QApplication::clipboard();
	pClipboard->setText(strAddr);
	//QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("邮箱地址已复制"));
	if (m_pCopyDialog == NULL)
	{
		m_pCopyDialog = new QDialog(this);
		m_pCopyDialog->resize(137,50);
		m_pCopyDialog->move(geometry().x() + (width() - 137.5) / 2, geometry().y() + (height() - 50) / 2);
		m_pCopyDialog->setModal(true);
		m_pCopyDialog->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
		m_pCopyDialog->setStyleSheet("image: url(" + QApplication::applicationDirPath() + "/image/copy.png);\n"
			"border-radius:5px;");
		connect(m_pTimer, SIGNAL(timeout()), m_pCopyDialog, SLOT(close()));
	}
	m_pCopyDialog->show();
	m_pTimer->start(1000);
}

void About::contactByQQ()
{
	//QDesktopServices::openUrl(QUrl(QString("https://support.microsoft.com/zh-cn/help/15060/windows-solitaire-minesweeper-hearts")));
	QDesktopServices::openUrl(QUrl(QString("http://wpa.qq.com/msgrd?v=3&uin=807775327&site=qq&menu=yes")));
}