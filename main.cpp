#include "widget.h"
#include <QApplication>
#include "topclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TopClass w;// =new TopClass;


    return a.exec();
}
