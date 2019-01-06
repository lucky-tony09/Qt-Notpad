#include "Find.h"

Find::Find(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this); 
	this->setWindowIcon(QIcon(u8"images/窗口图标.jpg"));
	ui.radioGroup->setId(ui.radioButton, 0);//topTubePositionRadio的Id设为0   
	ui.radioGroup->setId(ui.radioButton_2, 1);
	
	connect(ui.pushButton, &QPushButton::clicked, this, &Find::emitFind);
	connect(this, &Find::findPush, this, &Find::test);
	connect(ui.checkBox, &QCheckBox::stateChanged, this, &Find::sendCheak);
}

void Find::test(QString s)
{
	cout << s;
}

void Find::sendCheak(int n)
{
	emit checkState(n);
}

void Find::closeEvent(QCloseEvent * event)
{
	cout << "guan";
	emit isClose();
}

Find::~Find()
{
}

void Find::emitFind()
{
	int n = ui.radioGroup->checkedId();
	if (n == -1)
		n = 0;
	QString s = ui.lineEdit->text();
	emit checkState(n);
	emit findPush (s);
	cout << s;
}
