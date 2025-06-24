/********************************************************************************
** Form generated from reading UI file 'playlistdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTDIALOG_H
#define UI_PLAYLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlaylistDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *createButton;
    QPushButton *loadButton;
    QPushButton *deleteButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *newPlaylistName;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *songsListWidget;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *removeMusicButton;
    QPushButton *addMusicButton;

    void setupUi(QDialog *PlaylistDialog)
    {
        if (PlaylistDialog->objectName().isEmpty())
            PlaylistDialog->setObjectName("PlaylistDialog");
        PlaylistDialog->resize(526, 251);
        verticalLayoutWidget = new QWidget(PlaylistDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 9, 501, 53));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        horizontalLayoutWidget = new QWidget(PlaylistDialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(270, 180, 250, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        createButton = new QPushButton(horizontalLayoutWidget);
        createButton->setObjectName("createButton");

        horizontalLayout->addWidget(createButton);

        loadButton = new QPushButton(horizontalLayoutWidget);
        loadButton->setObjectName("loadButton");

        horizontalLayout->addWidget(loadButton);

        deleteButton = new QPushButton(horizontalLayoutWidget);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout->addWidget(deleteButton);

        horizontalLayoutWidget_2 = new QWidget(PlaylistDialog);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 150, 511, 24));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        newPlaylistName = new QLineEdit(horizontalLayoutWidget_2);
        newPlaylistName->setObjectName("newPlaylistName");

        horizontalLayout_2->addWidget(newPlaylistName);

        verticalLayoutWidget_2 = new QWidget(PlaylistDialog);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 60, 501, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        songsListWidget = new QListWidget(verticalLayoutWidget_2);
        songsListWidget->setObjectName("songsListWidget");

        verticalLayout_2->addWidget(songsListWidget);

        horizontalLayoutWidget_3 = new QWidget(PlaylistDialog);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 180, 151, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        removeMusicButton = new QPushButton(horizontalLayoutWidget_3);
        removeMusicButton->setObjectName("removeMusicButton");

        horizontalLayout_3->addWidget(removeMusicButton);

        addMusicButton = new QPushButton(horizontalLayoutWidget_3);
        addMusicButton->setObjectName("addMusicButton");

        horizontalLayout_3->addWidget(addMusicButton);


        retranslateUi(PlaylistDialog);

        QMetaObject::connectSlotsByName(PlaylistDialog);
    } // setupUi

    void retranslateUi(QDialog *PlaylistDialog)
    {
        PlaylistDialog->setWindowTitle(QCoreApplication::translate("PlaylistDialog", "Dialog", nullptr));
        createButton->setText(QCoreApplication::translate("PlaylistDialog", "New", nullptr));
        loadButton->setText(QCoreApplication::translate("PlaylistDialog", "Load", nullptr));
        deleteButton->setText(QCoreApplication::translate("PlaylistDialog", "Delete", nullptr));
        label->setText(QCoreApplication::translate("PlaylistDialog", "New PLay List :", nullptr));
        removeMusicButton->setText(QCoreApplication::translate("PlaylistDialog", "Delete Music", nullptr));
        addMusicButton->setText(QCoreApplication::translate("PlaylistDialog", "Add Music", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaylistDialog: public Ui_PlaylistDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTDIALOG_H
