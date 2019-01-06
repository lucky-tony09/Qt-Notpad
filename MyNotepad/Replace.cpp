#include "Replace.h"
#include "MyNotepad.h"

Replace::Replace(QWidget *parent)
	: QWidget(parent)
{
    inputLable=new QLabel(u8"查找内容",this);
    replace=new  QLabel(u8"替换为 ",this);
	lineInput=new QLineEdit(this);
	lineReplace = new QLineEdit(this);
	next1=new QPushButton(u8"查找下一个",this);
	rep=new QPushButton(u8"替换",this);
	repAll=new QPushButton(u8"全部替换",this);
	cancel=new QPushButton(u8"取消",this);
	//用单选框必须要有一个QButtonGroup，在加到窗口中 的时候还是用的原来的窗口
	difference=new QCheckBox(u8"区分大小写",this);

	QGridLayout* grdly = new QGridLayout(this);
	QVBoxLayout* vboxly = new QVBoxLayout(this);

	vboxly->addWidget(repAll);
	vboxly->addWidget(cancel);
	grdly->addWidget(inputLable, 0, 0);
	grdly->addWidget(lineInput,0,1);
	grdly->addWidget(next1, 0, 2);
	grdly->addWidget(replace, 1, 0);
	grdly->addWidget(lineReplace, 1, 1);
	grdly->addWidget(rep, 1, 2);
	//如果有中间某一格是空的，会自动将其合并
	grdly->addWidget(difference,2,1);
	grdly->addLayout(vboxly,2,2);

	this->setLayout(grdly);
	this->setWindowIcon( QIcon(u8"images/窗口图标.jpg"));

	//代替
	connect(rep, &QPushButton::clicked, this, &Replace::sendPushReplace);
	//取消
	connect(cancel, &QPushButton::clicked, this, &Replace::close);
	//替换所有
	connect(repAll,&QPushButton::clicked,this,&Replace::sendPushReplaceAll);
	//查找下一个
	connect(next1, &QPushButton::clicked, this, &Replace::sendPushFind);
	


}

Replace::~Replace()
{
}

void Replace::inputContent()
{
	lineContent = lineInput->text();


}

void Replace::repalceContent()
{

}

void Replace::sendPushFind()
{
	QString s1 = lineInput->text();
	emit pushFind(s1);
}

void Replace::sendPushReplace()
{
	QString s1 = lineInput->text();
	QString s2 = lineReplace->text();
	emit pushReplace(s1, s2);
}

void Replace::sendPushReplaceAll()
{
	QString s1 = lineInput->text();
	QString s2 = lineReplace->text();
	emit pushReplaceAll(s1,s2);
}

void Replace::closeEvent(QCloseEvent * event)
{
	emit isClose();
}


