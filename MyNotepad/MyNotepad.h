#pragma once

#include <QtWidgets/QMainWindow>
#include<qmenu.h>
#include<qmenubar.h>
#include<qstatusbar.h>
#include<qaction.h>
#include<qtextedit.h>
#include<qdebug.h>
#include<qtoolbar.h>
#include<qicon.h>
#include<qlabel.h>
#include<qdialog.h>
#include<qstring.h>
#include<qfiledialog.h>
#include<qfile.h>
#include<qmessagebox.h>
#include<qpixmap.h>
#include<iostream>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QtPrintSupport/QPageSetupDialog>
#include <QTextDocument>
#include <QTextCursor>
#include <qmessagebox.h>
#include"Find.h"
#include"Replace.h"
#include "ui_MyNotepad.h"



class MyNotepad : public QMainWindow
{
	Q_OBJECT

public:
	MyNotepad(QMainWindow *parent = Q_NULLPTR);
	virtual ~MyNotepad();
	void openShow();


	void aboutShow();
	void newShow();
	void saveAsShow();
	void saveShow();
	//void printShow();
	void findShow();
	void replaceShow();
	void sendAllContent();
	//接受查找和替换的信号
	void recFind(QString s);
	void recCheck(int n);
	void recClose();
	void recRedio(int n);
private:
	Ui::MyNotepadClass ui;
	//对于函数的公共变量
	bool judge = false;//判断文件是否是打开的
	QString fileName;//记录文件打开的位置
	//声明窗口中的栏目

	QMenu* fileMenu ;
	QMenu* editorMenu ;
	QMenu* aboutMenu ;
	QToolBar* toolBar ;
	QStatusBar* statusBar ;
	//声明菜单栏中的按钮

	QAction* newAction ;
	QAction* openAction ;
	QAction* saveAction ;
	QAction* saveAsAction ;
	QAction* printAction ;
	QAction* quitAction;
	QAction* findAction;
	QAction* replaceAction;
	QAction* aboutAction;
	QAction* toolFindAction;
	QAction* toolReplaceAction;
	QAction* toolPrintAction;
	QAction* toolNewAction;
	QAction* toolFileAction ;
	QAction* toolSaveAsAction ;
	QAction* toolSaveAction ;
	QAction* toolQuitAction;
	//声明文本编辑框
	QTextEdit* textEdit;
	//声明状态栏中的标签
	QLabel* introduceLable ;

	Find* findWidget;
	Replace* replaceWidget;

	int check1;//判断查找的区分大小写有没有被按下
	int form;//查找的初始位置
	int checkRedio;//判断查找是向前还是向后被按下了
	int pos1;//查找的起始位置
	int check2;//判断查找的区分大小写有没有被按下
	int form2;//查找的初始位置
	int checkRedio2;//判断查找是向前还是向后被按下了
	int pos2;//查找的起始位置
	
signals:
	void allContentStr(QString s);

};
