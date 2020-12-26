#ifndef STYLESETTING_H
#define STYLESETTING_H

#include <QDialog>
#include "ui_StyleSetting.h"

class StyleSetting : public QDialog
{
	Q_OBJECT

public:
	StyleSetting(QWidget *parent = 0);
	~StyleSetting();
	void showEvent(QShowEvent *);
	void setCellStyle(int* pCellStyle) {m_pCellStyle = pCellStyle;}
	void setBombStyle(int* pBombStyle) {m_pBombStyle = pBombStyle;}
	void setRandomStyle(int* pRandom) {m_pRandom = pRandom;}
signals:
	void emitCellStyle();
	void emitBombStyle();
private slots:
	void setStyle();
	void setBomb();
	void setRandom(int);
	void confirm();
private:
	Ui::StyleSetting ui;
	int* m_pBombStyle;
	int* m_pCellStyle;
	int* m_pRandom;
	int m_nLastBombStyle;
	int m_nLastCellStyle;
};

#endif // STYLESETTING_H
