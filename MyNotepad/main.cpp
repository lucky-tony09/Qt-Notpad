#include "MyNotepad.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyNotepad w;
	w.show();
	return a.exec();
}
