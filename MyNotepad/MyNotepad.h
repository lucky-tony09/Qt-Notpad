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
	//���ܲ��Һ��滻���ź�
	void recFind(QString s);
	void recCheck(int n);
	void recClose();
	void recRedio(int n);
private:
	Ui::MyNotepadClass ui;
	//���ں����Ĺ�������
	bool judge = false;//�ж��ļ��Ƿ��Ǵ򿪵�
	QString fileName;//��¼�ļ��򿪵�λ��
	//���������е���Ŀ

	QMenu* fileMenu ;
	QMenu* editorMenu ;
	QMenu* aboutMenu ;
	QToolBar* toolBar ;
	QStatusBar* statusBar ;
	//�����˵����еİ�ť

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
	//�����ı��༭��
	QTextEdit* textEdit;
	//����״̬���еı�ǩ
	QLabel* introduceLable ;

	Find* findWidget;
	Replace* replaceWidget;

	int check1;//�жϲ��ҵ����ִ�Сд��û�б�����
	int form;//���ҵĳ�ʼλ��
	int checkRedio;//�жϲ�������ǰ������󱻰�����
	int pos1;//���ҵ���ʼλ��
	int check2;//�жϲ��ҵ����ִ�Сд��û�б�����
	int form2;//���ҵĳ�ʼλ��
	int checkRedio2;//�жϲ�������ǰ������󱻰�����
	int pos2;//���ҵ���ʼλ��
	
signals:
	void allContentStr(QString s);

};
