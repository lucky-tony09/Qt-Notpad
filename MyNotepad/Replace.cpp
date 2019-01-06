#include "Replace.h"
#include "MyNotepad.h"

Replace::Replace(QWidget *parent)
	: QWidget(parent)
{
    inputLable=new QLabel(u8"��������",this);
    replace=new  QLabel(u8"�滻Ϊ ",this);
	lineInput=new QLineEdit(this);
	lineReplace = new QLineEdit(this);
	next1=new QPushButton(u8"������һ��",this);
	rep=new QPushButton(u8"�滻",this);
	repAll=new QPushButton(u8"ȫ���滻",this);
	cancel=new QPushButton(u8"ȡ��",this);
	//�õ�ѡ�����Ҫ��һ��QButtonGroup���ڼӵ������� ��ʱ�����õ�ԭ���Ĵ���
	difference=new QCheckBox(u8"���ִ�Сд",this);

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
	//������м�ĳһ���ǿյģ����Զ�����ϲ�
	grdly->addWidget(difference,2,1);
	grdly->addLayout(vboxly,2,2);

	this->setLayout(grdly);
	this->setWindowIcon( QIcon(u8"images/����ͼ��.jpg"));

	//����
	connect(rep, &QPushButton::clicked, this, &Replace::sendPushReplace);
	//ȡ��
	connect(cancel, &QPushButton::clicked, this, &Replace::close);
	//�滻����
	connect(repAll,&QPushButton::clicked,this,&Replace::sendPushReplaceAll);
	//������һ��
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


