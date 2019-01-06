#pragma once

#include <QWidget>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qcheckbox.h>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCloseEvent>
#include<qdebug.h>
#include "ui_Replace.h"

class Replace : public QWidget
{
	Q_OBJECT

public:
	Replace(QWidget *parent = Q_NULLPTR);
	~Replace();
	void inputContent();
	void repalceContent();
	void sendPushFind();
	void sendPushReplace();
	void sendPushReplaceAll();
	void closeEvent(QCloseEvent *event);
private:
	QLabel* inputLable;
	QLabel* replace;
	QLineEdit* lineInput;
	QLineEdit* lineReplace;
	QPushButton* next1;
	QPushButton* rep;
	QPushButton* repAll;
	QPushButton* cancel;
	QCheckBox* difference;
	QString lineContent;
	QString allContent;
	QString replaceContent;

signals:
	void pushFind(QString s);
	void pushReplace(QString s1, QString s2);
	void pushReplaceAll(QString s1, QString s2);
	void isClose();

};