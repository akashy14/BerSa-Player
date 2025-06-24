#include "mainwindow.h"

#include <QtWidgets/QApplication>
#include <QPalette>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(45, 45, 45));
    darkPalette.setColor(QPalette::WindowText, Qt::green);
    darkPalette.setColor(QPalette::Base, QColor(30, 30, 30));
    darkPalette.setColor(QPalette::AlternateBase, QColor(145, 200,255));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(4, 45, 45));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Highlight, QColor(100, 100, 255));
    darkPalette.setColor(QPalette::HighlightedText, QColor(45, 45, 45));
    a.setPalette(darkPalette);

    MainWindow w;
    w.show();
    w.setWindowTitle("BS Player Music");
    w.setWindowIcon(QIcon(":/image/icon1.png"));
    return a.exec();
}
