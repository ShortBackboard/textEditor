/*
 * A program : TextEditor
 *
 * anthor:2019051604044liChengYang
 * date:2023-4-29
 *
*/

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
