#include "ITableWidget.h"

ITableWidget::ITableWidget(QWidget *parent)
: QTableWidget(parent)
{
	m_nIndex = -1;
	setMouseTracking(true);
}

ITableWidget::~ITableWidget()
{

}

void ITableWidget::mouseReleaseEvent(QMouseEvent* event)
{
	double nItemHeight = 1.0 * size().height() / rowCount(), nItemWidth = 1.0 * size().width() / columnCount();
	double nRow = event->pos().y() / nItemHeight, nCol = event->pos().x() / nItemWidth;

	if (nRow >= 0 && nRow < rowCount() && nCol >= 0 && nCol < columnCount())
	{
		if(event->button() == Qt::LeftButton)
			emit itemClicked((int)nRow, (int)nCol, 0);
		else if(event->button() == Qt::RightButton)
			emit itemClicked((int)nRow, (int)nCol, 1);
		else
			return QTableWidget::mousePressEvent(event);
	}
	else
		return QTableWidget::mousePressEvent(event);
}

void ITableWidget::mouseMoveEvent(QMouseEvent *event)
{
	double nItemHeight = 1.0 * size().height() / rowCount(), nItemWidth = 1.0 * size().width() / columnCount();
	double nRow = event->pos().y() / nItemHeight, nCol = event->pos().x() / nItemWidth;
	//if (event->button() == Qt::NoButton)
	//if(geometry().contains(mapTo(m_pMainWindow, QCursor::pos())))
	if (nRow >= 0 && nRow < rowCount() && nCol >= 0 && nCol < columnCount())
	{
		emit itemHighLight(m_nIndex, (int)nRow * columnCount() + nCol);
		m_nIndex = (int)nRow * columnCount() + nCol;
	}
	//else
	return QTableWidget::mouseMoveEvent(event);
}