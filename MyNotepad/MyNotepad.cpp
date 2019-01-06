#include "MyNotepad.h"

#include <QPushButton>

MyNotepad::MyNotepad(QMainWindow *parent)
	: QMainWindow(parent)
	,findWidget(Q_NULLPTR),replaceWidget(Q_NULLPTR)
{
	//ui.setupUi(this);
	findWidget = new Find();
	//���������е���Ŀ
	QMenuBar* menuBar = new QMenuBar(this);
	fileMenu = new QMenu(u8"�ļ�", this);
	editorMenu = new QMenu(u8"�༭", this);
	aboutMenu = new QMenu(u8"����", this);
	toolBar = new QToolBar(this);
	statusBar = new QStatusBar(this);
	//�����˵����еİ�ť
	newAction = new QAction(QIcon(u8"images/�½�.jpg"),u8"�½�", this);
	openAction = new QAction(QIcon(u8"images/��.jpg"),u8"��", this);
	saveAction = new QAction(QIcon(u8"images/����.png"),u8"����", this);
	saveAsAction = new QAction(u8"���Ϊ", this);
	printAction = new QAction(QIcon(u8"images/��ӡ.png"), u8"��ӡ", this);
	quitAction = new QAction(QIcon(u8"images/�˳�.png"), u8"�˳�", this);
	replaceAction = new QAction(QIcon(u8"images/�滻.png"), u8"�滻",this);
	findAction = new QAction(QIcon(u8"images/����.png"), u8"����", this);
	aboutAction = new QAction(u8"����", this);
	//newAction = new QAction(u8"�½�", this);
	toolReplaceAction = new QAction(QIcon(u8"images/�滻.png"), u8"�滻",this);
	toolFindAction = new QAction(QIcon(u8"images/����.png"), u8"����", this);
	toolPrintAction = new QAction(QIcon(u8"images/��ӡ.png"), u8"��ӡ", this);
	toolNewAction = new QAction(QIcon(u8"images/�½�.png"), u8"�½�", this);
	toolFileAction = new QAction(QIcon(u8"images/��.png"), u8"��", this);
	toolSaveAsAction = new QAction(QIcon(u8"images/���Ϊ.png"), u8"���Ϊ", this);
	toolSaveAction = new QAction(QIcon(u8"images/����.png"), u8"����", this);
	toolQuitAction = new QAction(QIcon(u8"images/�˳�.png"), u8"�˳�", this);
	//�����ı��༭��
	textEdit = new QTextEdit(this);
	//����״̬���еı�ǩ
	introduceLable = new QLabel(u8"�������", this, Qt::Window);
    //�������ҶԻ���



	//���ð�ť֮��Ĺ�ϵ

	//���ô�������
	menuBar = this->menuBar();
	this->setWindowTitle(u8"���±�");
	this->addToolBar(toolBar);
	this->setCentralWidget(textEdit);
	this->resize(800, 600);
	this->setStatusBar(statusBar);
	this->setWindowIcon(QIcon(u8"images/����ͼ��.jpg"));
	//����ťװ��˵���
	fileMenu->addAction(newAction);
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(saveAsAction);
	fileMenu->addAction(printAction);
	fileMenu->addSeparator();
	fileMenu->addAction(quitAction);
	editorMenu->addAction(findAction);
	editorMenu->addAction(replaceAction);
	aboutMenu->addAction(aboutAction);
	//���˵�����˵�����
	menuBar->addMenu(fileMenu);
	menuBar->addMenu(editorMenu);
	menuBar->addMenu(aboutMenu);
	//����ť���ÿ�ݼ�
	newAction->setShortcut(Qt::CTRL | Qt::Key_N);
	openAction->setShortcut(Qt::CTRL | Qt::Key_O);
	saveAction->setShortcut(Qt::CTRL | Qt::Key_S);
	printAction->setShortcut(Qt::CTRL | Qt::Key_P);
	findAction->setShortcut(Qt::CTRL | Qt::Key_F);
	replaceAction->setShortcut(Qt::CTRL | Qt::Key_H);
	//������������ͼ��
	toolBar->addAction(toolNewAction);
	toolBar->addAction(toolFileAction);
	toolBar->addAction(toolSaveAsAction);
	toolBar->addAction(toolSaveAction);
	toolBar->addAction(toolPrintAction);
	toolBar->addAction(toolFindAction);
	toolBar->addAction(toolReplaceAction);
	toolBar->addAction(toolQuitAction);
	//��״̬���ı�ǩ���뵽״̬����
	statusBar->addWidget(introduceLable);
	form = 0;
	check1 = 0;
	checkRedio = 0;
	pos1 = -1;
	//�����ź����
	connect(newAction, &QAction::triggered, [=]()
	{
		qDebug() << u8"�ɹ���";
	}
	);
	connect(openAction, &QAction::triggered, this, &MyNotepad::openShow);
	connect(toolFileAction, &QAction::triggered, this, &MyNotepad::openShow);
	connect(aboutAction, &QAction::triggered, this, &MyNotepad::aboutShow);
	connect(newAction, &QAction::triggered, this, &MyNotepad::newShow);
	connect(toolNewAction, &QAction::triggered, this, &MyNotepad::newShow);
	connect(saveAsAction, &QAction::triggered, this, &MyNotepad::saveAsShow);
	connect(toolSaveAsAction, &QAction::triggered, this, &MyNotepad::saveAsShow);
	connect(saveAction,&QAction::triggered,this,&MyNotepad::saveShow);
	connect(toolSaveAction, &QAction::triggered, this, &MyNotepad::saveShow);
	connect(quitAction, &QAction::triggered, this, &MyNotepad::close); 
	connect(toolQuitAction, &QAction::triggered, this, &MyNotepad::close);
	//connect(toolPrintAction, &QAction::triggered, this, &MyNotepad::printShow);
	//connect(printAction, &QAction::triggered, this, &MyNotepad::printShow);
	connect(findAction, &QAction::triggered, this, &MyNotepad::findShow);
	connect(toolFindAction, &QAction::triggered, this, &MyNotepad::findShow);
	connect(replaceAction, &QAction::triggered, this, &MyNotepad::replaceShow); 
	connect(toolReplaceAction, &QAction::triggered, this, &MyNotepad::replaceShow);
	//�ж����ִ�Сд��û�б�����
	connect(findWidget, &Find::checkState, this, &MyNotepad::recCheck);
	connect(findWidget, &Find::isClose, this, &MyNotepad::recClose);
	connect(findWidget, &Find::checkState, this, &MyNotepad::recRedio);
	
	connect(findWidget, &Find::findPush, this, &MyNotepad::recFind);
	
}

MyNotepad::~MyNotepad()
{
	if (findWidget != Q_NULLPTR)
		delete findWidget;
}

void MyNotepad::openShow()
{
	 fileName = QFileDialog::getOpenFileName(this, u8"��", u8"C://Users/���/Documents", "Text files(*.txt);;c++ files(*.cpp  *.h)");

	if (!fileName.isEmpty())
	{
		QFile* file = new QFile(fileName);
		if (!file->open(QIODevice::Unbuffered | QIODevice::ReadOnly))
		{
			QMessageBox::warning(this, u8"��ʾ", u8"�ļ���ʧ�ܣ�", QMessageBox::Close | QMessageBox::Ok);
			return;
		}
		QTextStream* textStream = new QTextStream(file);
		textStream->setCodec("UTF - 8");
		textEdit->setText(textStream->readAll());
	}
	else
	{
		//QMessageBox::warning(this, u8"����", u8"·��Ϊ�գ�", QMessageBox::Close | QMessageBox::Ok);
	}
	judge = true;
}

void MyNotepad::aboutShow()
{
	QMessageBox* aboutMessageBox = new QMessageBox(QMessageBox::NoIcon, u8"����", u8"version: v1.0\n"
		"author: lihao\n"
		"qq: 944034642\n"
		"Begin Learning The Qt",QMessageBox::Ok,this,Qt::Dialog);
	aboutMessageBox->setIconPixmap(QPixmap(u8"images/����.jpg"));
	aboutMessageBox->exec();
}

void MyNotepad::newShow()
{
	textEdit->clear();
}

void MyNotepad::saveAsShow()
{
	QString path = QFileDialog::getSaveFileName(this, u8"����", ".", u8"Text files(*.txt)");
	if (path.isEmpty())
	{
		//QMessageBox::warning(this, u8"����", u8"·��Ϊ�գ�", QMessageBox::Close | QMessageBox::Ok);
	}
	else
	{
		QFile* file=new QFile(path);
		if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QMessageBox::warning(this, u8"����", u8"��·������ʧ��", QMessageBox::Ok);
		}
		else
		{
			QTextStream* in = new QTextStream(file);
			*in << textEdit->toPlainText();
			file->close();
		}
	}
}

void MyNotepad::saveShow()
{
	
	{
		QFile* file = new QFile(fileName);
		if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QMessageBox::warning(this, u8"����", u8"��·������ʧ��", QMessageBox::Ok);
		}
		else
		{
			QTextStream* in = new QTextStream(file);
			in->setCodec("UTF - 8");
			*in << textEdit->toPlainText();
			file->close();
		}
	}
	
}

void MyNotepad::findShow()
{
	
	if (findWidget == Q_NULLPTR)
	{


	}
	findWidget->show();
	qDebug() << u8"fsda";
}

void MyNotepad::replaceShow()
{
	if (replaceWidget == Q_NULLPTR)
	{
		replaceWidget = new Replace();
	}
	replaceWidget->show();
	qDebug() << u8"fsda";
}

void MyNotepad::sendAllContent()
{
	emit allContentStr(textEdit->toPlainText());
}

void MyNotepad::recFind(QString s)
{
	QString mainS = textEdit->toPlainText();
	if(checkRedio==0&&pos1==-1)form = 0;
	else if(checkRedio == 1 && pos1 == -1)form =  mainS.length()-1;
	else if (checkRedio == 0 && pos1 != -1) form = pos1 + s.length();
	else if (checkRedio == 1 && pos1 != -1)form = pos1 - s.length();
	cout << form;
	cout << pos1;
	cout << checkRedio;
	//���ò��ҷ�ʽ
	if (check1 == 0)
	{
		if (checkRedio == 0)
			pos1 = mainS.indexOf(s, form, Qt::CaseInsensitive);
		else
			pos1 = mainS.lastIndexOf(s, form, Qt::CaseInsensitive);
	}
	else if (check1 == 1)
	{
		if (checkRedio == 0)
			pos1 = mainS.indexOf(s, form, Qt::CaseSensitive);
		else
			pos1 = mainS.lastIndexOf(s, form, Qt::CaseSensitive);
	}
    cout << pos1;
	if (pos1 == -1||form==-1)
	{
		QMessageBox::about(this, u8"��ʾ",u8"���ص�ͷ�ˣ�");
		return;
	}
	QString replaceS = QString("<font style='font-size:16px; background-color:white; color:blue;'>%1</font>").arg(s);
	mainS= mainS.replace(pos1, s.length(), replaceS);
	textEdit->setText(mainS);
	
}

void MyNotepad::recCheck(int n)
{
	check1 = n;
}

void MyNotepad::recClose()
{
	cout << "rrqwe";
	QString mainS = textEdit->toPlainText();
	mainS = QString(("<font style = 'font-size:12px; background-color:white; color:black;'> %1< / font>")).arg(mainS);
	textEdit->setText(mainS);
	form = 0;
	check1 = 0;
	checkRedio = 0;
	pos1 = -1;
}

void MyNotepad::recRedio(int n)
{
	checkRedio = n;
}

//void MyNotepad::printShow()
//{
//	QPrinter printer;
//	QString printer_name = printer.printerName();
//	if (printer_name.size() == 0)
//	{
//		return;
//	}
//	QPrintDialog dlg(&printer, this);
//	if (textEdit->textCursor().hasSelection())
//	{
//		dlg.addEnabledOption(QAbstractPrintDialog::PrintSelection);
//	}
//	if (dlg.exec() == QDialog::Accepted)
//	{
//		textEdit->print(&printer);
//	}
//}



