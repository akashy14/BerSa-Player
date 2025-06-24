#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sound.h"
#include <QLineEdit>
#include <QWidgetList>
#include <QPushButton>
#include <QLabel>
#include <QListWidgetItem>
#include <QRandomGenerator>
#include <QtWidgets/QMainWindow>
#include <QStackedWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum PlayMode {
        RepeatAll,
        RepeatOne,
        Shuffle
    };

    PlayMode currentMode = RepeatAll;

    MainWindow(QWidget *parent = nullptr);
    void displayList();
    void playNextSong();
    ~MainWindow();

public slots:
    void start();
    void addfiles();
    void onFileClicked(QListWidgetItem *item);
    void updateVolume(int value);
    void on_movePlayList_clicked();

    void on_settingButton_clicked();
    void on_myPlaylistButton_clicked();
    void afficherPlaylist(const QMap <QString,QString> fichier);
    void filtrerListe(const QString &texte);

private:
    QStringList playlistCourante;
    bool isPlayList;


    Ui::MainWindow *ui;

    QAudioOutput * audiooutput;
    Sound * setSound;
    QMap<QString, QString> fileMap; // (nom visible -> chemin complet)

};
#endif // MAINWINDOW_H
