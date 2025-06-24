#include "playlistdialog.h"
#include "ui_playlistdialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>
#include <QListWidgetItem>

PlaylistDialog::PlaylistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlaylistDialog),
    jsonPath("playlists.json")
{
    ui->setupUi(this);
    loadPlaylistsToUI();
}

PlaylistDialog::~PlaylistDialog()
{
    delete ui;
}

QJsonObject PlaylistDialog::loadJson()
{
    QFile file(jsonPath);
    QJsonObject obj;
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        obj = doc.object();
    } else {
        obj["Favoris"] = QJsonArray(); // Initialiser avec Favoris
        saveJson(obj);
    }
    return obj;
}

void PlaylistDialog::saveJson(const QJsonObject &obj)
{
    QFile file(jsonPath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(obj).toJson());
        file.close();
    }
}

void PlaylistDialog::loadPlaylistsToUI()
{
    QJsonObject obj = loadJson();
    ui->listWidget->clear();
    for (const QString &key : obj.keys()) {
        ui->listWidget->addItem(key);
    }
}

void PlaylistDialog::on_createButton_clicked()
{
    QString nom = ui->newPlaylistName->text().trimmed();
    if (nom.isEmpty()) return;

    QJsonObject obj = loadJson();
    if (!obj.contains(nom)) {
        obj[nom] = QJsonArray();
        saveJson(obj);
        loadPlaylistsToUI();
    }
}

void PlaylistDialog::on_loadButton_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (!item) return;

    QString playlistName = item->text();
    QJsonObject obj = loadJson();
    QJsonObject chansonObj = obj.value(playlistName).toObject();



    if (chansonObj.isEmpty()) {
        QStringList fichiers = QFileDialog::getOpenFileNames(this, "Add sounds", "", "Audio (*.mp3 *.wav)");
        QJsonArray newArray;
        for (const QString &chem : fichiers){
            QString titre = QFileInfo(chem).fileName();
            QString cheminComplet = QFileInfo(chem).absoluteFilePath();
            chansonObj[titre]=cheminComplet;
        }
        obj[playlistName] = chansonObj;
        saveJson(obj);
    }

    QMap<QString,QString> fichierMap;
    for (const QString &titre : chansonObj.keys()){
        fichierMap.insert(titre,chansonObj.value(titre).toString());
    }

    emit playlistSelected(fichierMap);
    accept();
}

void PlaylistDialog::on_deleteButton_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (!item) return;

    QString name = item->text();
    if (name == "Favoris") return; // Ne pas supprimer Favoris

    QJsonObject obj = loadJson();
    obj.remove(name);
    saveJson(obj);
    loadPlaylistsToUI();
}

void PlaylistDialog::on_listWidget_itemClicked(QListWidgetItem *item) {
    ui->songsListWidget->clear();
    if (!item) return;

    QString name = item->text();
    QJsonObject obj = loadJson();
    QJsonObject chansonObj = obj.value(name).toObject();

    for (const QJsonValue &val : chansonObj.keys())
        ui->songsListWidget->addItem(QFileInfo(val.toString()).fileName());
}


void PlaylistDialog::on_addMusicButton_clicked() {
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (!item) return;

    QString playlistName = item->text();
    QJsonObject obj = loadJson();
    QJsonObject chansonObj = obj.value(playlistName).toObject();

    QStringList fichiers = QFileDialog::getOpenFileNames(this, "Ajouter fichiers audio", "", "Audio (*.mp3 *.wav *.flac)");
    for (const QString &chem : fichiers){
        QString titre = QFileInfo(chem).fileName();
        QString cheminComplet = QFileInfo(chem).absoluteFilePath();
        chansonObj[titre]=cheminComplet;
    }
    obj[playlistName] = chansonObj;
    saveJson(obj);
    on_listWidget_itemClicked(item); // rafraîchir l’affichage
}

void PlaylistDialog::on_removeMusicButton_clicked() {
    QListWidgetItem *playlistItem = ui->listWidget->currentItem();
    QListWidgetItem *musicItem = ui->songsListWidget->currentItem();
    if (!playlistItem || !musicItem) return;

    QString playlistName = playlistItem->text();
    QString musicName = musicItem->text();

    QJsonObject obj = loadJson();
    QJsonArray array = obj.value(playlistName).toArray();

    QJsonArray updatedArray;
    for (const QJsonValue &val : array) {
        if (QFileInfo(val.toString()).fileName() != musicName)
            updatedArray.append(val);
    }

    obj[playlistName] = updatedArray;
    saveJson(obj);
    on_listWidget_itemClicked(playlistItem); // mise à jour
}
