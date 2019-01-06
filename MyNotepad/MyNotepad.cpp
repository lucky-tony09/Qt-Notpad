#include "MyNotepad.h"

#include <QPushButton>

MyNotepad::MyNotepad(QMainWindow *parent)
	: QMainWindow(parent)
	,findWidget(Q_NULLPTR),replaceWidget(Q_NULLPTR)
{
	//ui.setupUi(this);
	findWidget = new Find();
	//声明窗口中的栏目
	QMenuBar* menuBar = new QMenuBar(this);
	fileMenu = new QMenu(u8"文件", this);
	editorMenu = new QMenu(u8"编辑", this);
	aboutMenu = new QMenu(u8"关于", this);
	toolBar = new QToolBar(this);
	statusBar = new QStatusBar(this);
	//声明菜单栏中的按钮
	newAction = new QAction(QIcon(u8"images/新建.jpg"),u8"新建", this);
	openAction = new QAction(QIcon(u8"images/打开.jpg"),u8"打开", this);
	saveAction = new QAction(QIcon(u8"images/保存.png"),u8"保存", this);
	saveAsAction = new QAction(u8"另存为", this);
	printAction = new QAction(QIcon(u8"images/打印.png"), u8"打印", this);
	quitAction = new QAction(QIcon(u8"images/退出.png"), u8"退出", this);
	replaceAction = new QAction(QIcon(u8"images/替换.png"), u8"替换",this);
	findAction = new QAction(QIcon(u8"images/查找.png"), u8"查找", this);
	aboutAction = new QAction(u8"关于", this);
	//newAction = new QAction(u8"新建", this);
	toolReplaceAction = new QAction(QIcon(u8"images/替换.png"), u8"替换",this);
	toolFindAction = new QAction(QIcon(u8"images/查找.png"), u8"查找", this);
	toolPrintAction = new QAction(QIcon(u8"images/打印.png"), u8"打印", this);
	toolNewAction = new QAction(QIcon(u8"images/新建.png"), u8"新建", this);
	toolFileAction = new QAction(QIcon(u8"images/打开.png"), u8"打开", this);
	toolSaveAsAction = new QAction(QIcon(u8"images/另存为.png"), u8"另存为", this);
	toolSaveAction = new QAction(QIcon(u8"images/保存.png"), u8"保存", this);
	toolQuitAction = new QAction(QIcon(u8"images/退出.png"), u8"退出", this);
	//声明文本编辑框
	textEdit = new QTextEdit(this);
	//声明状态栏中的标签
	introduceLable = new QLabel(u8"李浩制作", this, Qt::Window);
    //声明查找对话框



	//设置按钮之间的关系

	//设置窗口属性
	menuBar = this->menuBar();
	this->setWindowTitle(u8"记事本");
	this->addToolBar(toolBar);
	this->setCentralWidget(textEdit);
	this->resize(800, 600);
	this->setStatusBar(statusBar);
	this->setWindowIcon(QIcon(u8"images/窗口图标.jpg"));
	//将按钮装入菜单中
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
	//将菜单加入菜单栏中
	menuBar->addMenu(fileMenu);
	menuBar->addMenu(editorMenu);
	menuBar->addMenu(aboutMenu);
	//给按钮设置快捷键
	newAction->setShortcut(Qt::CTRL | Qt::Key_N);
	openAction->setShortcut(Qt::CTRL | Qt::Key_O);
	saveAction->setShortcut(Qt::CTRL | Qt::Key_S);
	printAction->setShortcut(Qt::CTRL | Qt::Key_P);
	findAction->setShortcut(Qt::CTRL | Qt::Key_F);
	replaceAction->setShortcut(Qt::CTRL | Qt::Key_H);
	//给工具栏设置图标
	toolBar->addAction(toolNewAction);
	toolBar->addAction(toolFileAction);
	toolBar->addAction(toolSaveAsAction);
	toolBar->addAction(toolSaveAction);
	toolBar->addAction(toolPrintAction);
	toolBar->addAction(toolFindAction);
	toolBar->addAction(toolReplaceAction);
	toolBar->addAction(toolQuitAction);
	//将状态栏的标签加入到状态栏中
	statusBar->addWidget(introduceLable);
	form = 0;
	check1 = 0;
	checkRedio = 0;
	pos1 = -1;
	//设置信号与槽
	connect(newAction, &QAction::triggered, [=]()
	{
		qDebug() << u8"成功！";
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
	//判断区分大小写有没有被按下
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
	 fileName = QFileDialog::getOpenFileName(this, u8"打开", u8"C://Users/李浩/Documents", "Text files(*.txt);;c++ files(*.cpp  *.h)");

	if (!fileName.isEmpty())
	{
		QFile* file = new QFile(fileName);
		if (!file->open(QIODevice::Unbuffered | QIODevice::ReadOnly))
		{
			QMessageBox::warning(this, u8"提示", u8"文件打开失败！", QMessageBox::Close | QMessageBox::Ok);
			return;
		}
		QTextStream* textStream = new QTextStream(file);
		textStream->setCodec("UTF - 8");
		textEdit->setText(textStream->readAll());
	}
	else
	{
		//QMessageBox::warning(this, u8"错误", u8"路径为空！", QMessageBox::Close | QMessageBox::Ok);
	}
	judge = true;
}

void MyNotepad::aboutShow()
{
	QMessageBox* aboutMessageBox = new QMessageBox(QMessageBox::NoIcon, u8"关于", u8"version: v1.0\n"
		"author: lihao\n"
		"qq: 944034642\n"
		"Begin Learning The Qt",QMessageBox::Ok,this,Qt::Dialog);
	aboutMessageBox->setIconPixmap(QPixmap(u8"images/关于.jpg"));
	aboutMessageBox->exec();
}

void MyNotepad::newShow()
{
	textEdit->clear();
}

void MyNotepad::saveAsShow()
{
	QString path = QFileDialog::getSaveFileName(this, u8"保存", ".", u8"Text files(*.txt)");
	if (path.isEmpty())
	{
		//QMessageBox::warning(this, u8"错误", u8"路径为空！", QMessageBox::Close | QMessageBox::Ok);
	}
	else
	{
		QFile* file=new QFile(path);
		if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QMessageBox::warning(this, u8"错误", u8"该路径保存失败", QMessageBox::Ok);
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
			QMessageBox::warning(this, u8"错误", u8"该路径保存失败", QMessageBox::Ok);
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
	//设置查找方式
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
		QMessageBox::about(this, u8"提示",u8"搜素到头了！");
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



