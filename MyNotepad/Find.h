#pragma once

#include <qdialog.h>
#include <qdebug.h>
#include <QCloseEvent>
#include "ui_Find.h"

#define cout qDebug()<<'['<<__FILE__<<':'<<__LINE__<<']'

class Find : public QWidget
{
	Q_OBJECT
private:
	Ui::Find ui;
public:
	Find(QWidget *parent = Q_NULLPTR);
	void emitFind();
	//²âÊÔ
	void test(QString s);
	void sendCheak(int n);
	void closeEvent(QCloseEvent* event);
	~Find();
signals:
	void findPush(QString s);
	void checkState(int state);
	void isClose();
	void redioState(int n);
	//QString s = ui.lineEdit.text();

};
