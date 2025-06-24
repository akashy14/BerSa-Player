/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *liste;
    QPushButton *myPlayListe;
    QPushButton *setting;
    QPushButton *addsound;
    QLineEdit *researchSound;
    QListWidget *listWidget;
    QLabel *labelSound;
    QPushButton *prev;
    QPushButton *pausePlay;
    QPushButton *next;
    QSlider *volumeSlider;
    QSlider *musicSlider;
    QLabel *timeLabel;
    QPushButton *movePlayList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        liste = new QPushButton(centralwidget);
        liste->setObjectName("liste");
        liste->setGeometry(QRect(0, 10, 60, 28));
        liste->setMinimumSize(QSize(60, 28));
        myPlayListe = new QPushButton(centralwidget);
        myPlayListe->setObjectName("myPlayListe");
        myPlayListe->setGeometry(QRect(110, 10, 82, 28));
        myPlayListe->setMaximumSize(QSize(82, 28));
        setting = new QPushButton(centralwidget);
        setting->setObjectName("setting");
        setting->setGeometry(QRect(700, 10, 82, 28));
        setting->setMaximumSize(QSize(82, 28));
        addsound = new QPushButton(centralwidget);
        addsound->setObjectName("addsound");
        addsound->setGeometry(QRect(580, 10, 82, 28));
        addsound->setMaximumSize(QSize(82, 28));
        researchSound = new QLineEdit(centralwidget);
        researchSound->setObjectName("researchSound");
        researchSound->setGeometry(QRect(220, 10, 321, 26));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(5, 41, 781, 471));
        labelSound = new QLabel(centralwidget);
        labelSound->setObjectName("labelSound");
        labelSound->setGeometry(QRect(12, 540, 600, 21));
        labelSound->setMinimumSize(QSize(600, 21));
        labelSound->setMaximumSize(QSize(600, 21));
        prev = new QPushButton(centralwidget);
        prev->setObjectName("prev");
        prev->setGeometry(QRect(470, 530, 31, 28));
        prev->setMaximumSize(QSize(31, 16777215));
        pausePlay = new QPushButton(centralwidget);
        pausePlay->setObjectName("pausePlay");
        pausePlay->setGeometry(QRect(500, 530, 31, 28));
        pausePlay->setMaximumSize(QSize(31, 28));
        next = new QPushButton(centralwidget);
        next->setObjectName("next");
        next->setGeometry(QRect(530, 530, 31, 28));
        next->setMaximumSize(QSize(31, 28));
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(320, 540, 61, 22));
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);
        musicSlider = new QSlider(centralwidget);
        musicSlider->setObjectName("musicSlider");
        musicSlider->setGeometry(QRect(10, 510, 771, 16));
        musicSlider->setOrientation(Qt::Orientation::Horizontal);
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(626, 530, 71, 20));
        movePlayList = new QPushButton(centralwidget);
        movePlayList->setObjectName("movePlayList");
        movePlayList->setGeometry(QRect(420, 530, 31, 28));
        movePlayList->setMaximumSize(QSize(31, 16777215));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        liste->setText(QCoreApplication::translate("MainWindow", "List", nullptr));
        myPlayListe->setText(QCoreApplication::translate("MainWindow", "Play List", nullptr));
        setting->setText(QCoreApplication::translate("MainWindow", "Setting", nullptr));
        addsound->setText(QCoreApplication::translate("MainWindow", "\342\236\225", nullptr));
        labelSound->setText(QString());
        prev->setText(QCoreApplication::translate("MainWindow", "\342\217\256", nullptr));
        pausePlay->setText(QCoreApplication::translate("MainWindow", "\342\217\270", nullptr));
        next->setText(QCoreApplication::translate("MainWindow", "\342\217\255", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "00:00 / 00:00", nullptr));
        movePlayList->setText(QCoreApplication::translate("MainWindow", "\360\237\224\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
