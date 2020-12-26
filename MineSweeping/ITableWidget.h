#ifndef ITABLEWIDGET_H
#define ITABLEWIDGET_H

#include <QMouseEvent>
#include <QTableWidget>

class ITableWidget : public QTableWidget
{
	Q_OBJECT

public:
	ITableWidget(QWidget *parent);
	~ITableWidget();
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent *event);
	void setMainWindowPtr(QWidget* pWidget){m_pMainWindow = pWidget;}
signals:
	void itemClicked(int row, int column, int type);
	void itemHighLight(int nLast, int nCur);
private:
	int m_nIndex;
	QWidget* m_pMainWindow;
};

#endif // ITABLEWIDGET_H
