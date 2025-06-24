#ifndef PLAYLISTDIALOG_H
#define PLAYLISTDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QListWidgetItem>
#include <QMap>

namespace Ui {
class PlaylistDialog;
}

class PlaylistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlaylistDialog(QWidget *parent = nullptr);
    ~PlaylistDialog();

signals:
    void playlistSelected(QMap <QString,QString> fichier);

private slots:
    void on_createButton_clicked();
    void on_loadButton_clicked();
    void on_deleteButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item); // pour afficher les chansons
    void on_addMusicButton_clicked();
    void on_removeMusicButton_clicked();

private:
    Ui::PlaylistDialog *ui;
    QString jsonPath;
    QJsonObject loadJson();
    void saveJson(const QJsonObject &obj);
    void loadPlaylistsToUI();
};

#endif // PLAYLISTDIALOG_H
