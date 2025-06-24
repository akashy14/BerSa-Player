#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QSlider>
#include <QDebug>
#include <QTimer>

#include "settingdialog.h"
#include "playlistdialog.h"

#include <QStackedWidget>

// 🎵🎶➕▪◼◼🔈🔇🔉🔊▶⏸⏯⏭⏮🔀🔁🔂

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //#121212;
    QString darkStyle = R"(
    QWidget {
        background-color:rgb(45, 45, 45);
        color: #ffffff;
    }

    QPushButton {
        background-color: #1e1e1e;
        border-radius: 15px;
        border: 1px solid #3c3c3c;
        padding: 5px;
    }

    QPushButton:hover {
        background-color: #2a2a2a;
    }

    QLineEdit, QTextEdit, QPlainTextEdit, QComboBox {
        background-color: #1e1e1e;
        color: #ffffff;
        border: 1px solid #3c3 ;
    }

    QListWidget {
        background-color: #1e1e1e;
        color: #ffffff;
        border: 1px solid #3c3c3c;
    }

    QScrollBar:vertical {
        background-color: #1e1e1e;
        width: 10px;
    }
    )";
    this->setStyleSheet(darkStyle);

    ui->musicSlider->setStyleSheet(R"(
    QSlider::groove:horizontal {
        border: 1px solid #444;
        height: 8px;
        background: #222;
        margin: 0 0;
        border-radius: 4px;
    }

    QSlider::handle:horizontal {
        background: #00BFFF;
        border: 1px solid #00BFFF;
        width: 14px;
        height: 14px;
        margin: -3px 0;
        border-radius: 7px;
    }

    QSlider::sub-page:horizontal {
        background: #00BFFF;
        border: 1px solid #444;
        height: 8px;
        border-radius: 4px;
    }

    QSlider::add-page:horizontal {
        background: #555;
        border: 1px solid #444;
        height: 8px;
        border-radius: 4px;
    }
    )");

    ui->volumeSlider->setStyleSheet(R"(
    QSlider::groove:horizontal {
        border: 1px solid #444;
        height: 6px;
        background: #2c2c2c;
        margin: 0 0;
        border-radius: 3px;
    }

    QSlider::handle:horizontal {
        background: #00BFFF;
        border: 1px solid #00BFFF;
        width: 12px;
        height: 12px;
        margin: -4px 0;
        border-radius: 6px;
    }

    QSlider::sub-page:horizontal {
        background: #00BFFF;
        border: 1px solid #00BFFF;
        height: 6px;
        border-radius: 3px;
    }

    QSlider::add-page:horizontal {
        background: #444;
        border: 1px solid #222;
        height: 6px;
        border-radius: 3px;
    }
    )");

    ui->liste->setStyleSheet(R"(
    QPushButton {
        background-color: #1e1e1e;
        border-radius: 20px;
        border: 1px solid #3c3c3c;
        padding: 5px;
    }

    QPushButton:hover {
        background-color: #2a2222;
    }

    )");

    start();
}

void MainWindow::start(){
    QWidget *central = new QWidget(this);
    setCentralWidget(central);




    // Top layout
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(ui->liste);
    topLayout->addWidget(ui->myPlayListe);
    topLayout->addWidget(ui->researchSound);
    topLayout->addWidget(ui->addsound);
    topLayout->addWidget(ui->setting);

    // Center

    QWidget *centerWidget = ui->listWidget;
    QWidget *nextWidegt = ui->musicSlider;

    // Bottom layout
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(ui->labelSound);
    bottomLayout->addWidget(ui->volumeSlider);
    bottomLayout->addWidget(ui->movePlayList);
    bottomLayout->addWidget(ui->prev);
    bottomLayout->addWidget(ui->pausePlay);
    bottomLayout->addWidget(ui->next);
    bottomLayout->addWidget(ui->timeLabel);

    // Main vertical layout

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(centerWidget);
    mainLayout->addWidget(nextWidegt);
    mainLayout->addLayout(bottomLayout);

    central->setLayout(mainLayout);

    ui->volumeSlider->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    ui->volumeSlider->setFixedWidth(100);


    audiooutput = new QAudioOutput(this);
    setSound = new Sound(audiooutput, this);

    // Configuration du volume
    ui->volumeSlider->setRange(0, 100);
    audiooutput->setVolume(0);
    connect(ui->volumeSlider, &QSlider::valueChanged, this, &MainWindow::updateVolume);


    // Textes UI
    ui->liste->setText("List");
    ui->myPlayListe->setText("Play List");
    ui->researchSound->setPlaceholderText("Search sound...");
    ui->setting->setText("Settings");
    ui->addsound->setText("➕");

    isPlayList = false;
    // Connexions

    connect(ui->researchSound, &QLineEdit::textChanged, this, &MainWindow::filtrerListe);
    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::onFileClicked);
    connect(ui->addsound, &QPushButton::clicked, this, &MainWindow::addfiles);
    connect(ui->liste, &QPushButton::clicked, this, &MainWindow::displayList);
    connect(ui->setting,&QPushButton::clicked,this,&MainWindow::on_settingButton_clicked);
    connect(ui->myPlayListe,&QPushButton::clicked,this,&MainWindow::on_myPlaylistButton_clicked);

    connect(ui->movePlayList,&QPushButton::clicked,this,&MainWindow::on_movePlayList_clicked);

    connect(ui->next, &QPushButton::clicked, this, [this]() {
        int currentRow = ui->listWidget->currentRow();
        if (currentRow < ui->listWidget->count() - 1) {
            ui->listWidget->setCurrentRow(currentRow + 1);
            onFileClicked(ui->listWidget->currentItem());
        }
    });

    connect(ui->prev, &QPushButton::clicked, this, [this]() {
        ui->musicSlider->setValue(0);
        ui->musicSlider->setMaximum(0);
        int currentRow = ui->listWidget->currentRow();

        if (currentRow > 0) {
            QListWidgetItem *prevItem = ui->listWidget->item(currentRow - 1);
            ui->listWidget->setCurrentItem(prevItem);
            onFileClicked(prevItem);
        }
    });

    connect(ui->pausePlay, &QPushButton::clicked, [this]() {
        if (ui->pausePlay->text() == "⏸") {
            ui->pausePlay->setText("▶");
            setSound->play();
        } else {
            ui->pausePlay->setText("⏸");
            setSound->pause();
        }
    });



}

void MainWindow::addfiles() {
    isPlayList = false;
    QStringList fichiers = QFileDialog::getOpenFileNames(this, "Add files", "", "Audio (*.mp3 *.wav)");
    for (const QString &chemin : fichiers) {
        QString nomFichier = QFileInfo(chemin).fileName();
        if (!fileMap.contains(nomFichier)) {
            ui->listWidget->addItem(nomFichier);
            playlistCourante.append(chemin);
            fileMap[nomFichier] = chemin;
        }
    }
}

void MainWindow::onFileClicked(QListWidgetItem *item) {
    QMediaPlayer *player = setSound->getPlayer();

    disconnect(player, nullptr, nullptr, nullptr); // éviter les connexions multiples
    disconnect(ui->musicSlider, nullptr, nullptr, nullptr);
    if (!item) return;
    if (!setSound) {
        setSound = new Sound(audiooutput, this);
    }
    QString nomFichier = item->text();
    if (isPlayList){
        QString chemin = item->data(Qt::UserRole).toString();
        if (chemin.isEmpty())return;
        setSound->uploadfile(QUrl::fromLocalFile(chemin));
        setSound->play();
        ui->labelSound->setText(nomFichier);
        ui->pausePlay->setText("▶");
        setSound->play();

        // Connexions
        connect(player, &QMediaPlayer::positionChanged, this, [this, player](qint64 pos) {
            ui->musicSlider->setValue(pos);
            ui->timeLabel->setText(
                QTime::fromMSecsSinceStartOfDay(pos).toString("mm:ss") + " / " +
                QTime::fromMSecsSinceStartOfDay(player->duration()).toString("mm:ss")
                );
        });

        connect(player, &QMediaPlayer::durationChanged, this, [this](qint64 dur) {
            ui->musicSlider->setMaximum(dur);
        });

        connect(ui->musicSlider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);

        connect(player, &QMediaPlayer::mediaStatusChanged, this, [this, player](QMediaPlayer::MediaStatus status) {
            if (status == QMediaPlayer::EndOfMedia) {
                qDebug() << "Lancement next... ";
                ui->pausePlay->setText("⏸");
                playNextSong();  // notre nouvelle fonction
            }
        });
    }

    if (!fileMap.contains(nomFichier)) return;

    QString chemin = fileMap[nomFichier];
    if (!QFile::exists(chemin)) return;
    else {
        setSound->stop();  // ou méthode personnalisée pour réinitialiser
    }

    setSound->uploadfile(QUrl::fromLocalFile(chemin));
    ui->labelSound->setText(nomFichier);
    ui->pausePlay->setText("▶");
    setSound->play();

    // Connexions
    connect(player, &QMediaPlayer::positionChanged, this, [this, player](qint64 pos) {
        ui->musicSlider->setValue(pos);
        ui->timeLabel->setText(
            QTime::fromMSecsSinceStartOfDay(pos).toString("mm:ss") + " / " +
            QTime::fromMSecsSinceStartOfDay(player->duration()).toString("mm:ss")
            );
    });

    connect(player, &QMediaPlayer::durationChanged, this, [this](qint64 dur) {
        ui->musicSlider->setMaximum(dur);
    });

    connect(ui->musicSlider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);

    connect(player, &QMediaPlayer::mediaStatusChanged, this, [this, player](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            ui->pausePlay->setText("⏸");
            playNextSong();  // notre nouvelle fonction
        }
    });
}

void MainWindow::updateVolume(int value) {
    audiooutput->setVolume(value / 100.0);
}

void MainWindow::displayList() {
    ui->listWidget->clear();
    isPlayList = false;
    playlistCourante.clear();
    for (const auto &titre : fileMap.keys()) {
        ui->listWidget->addItem(titre);
        playlistCourante.append(titre);
    }
}

void MainWindow::on_myPlaylistButton_clicked()
{
    PlaylistDialog dlg(this);
    dlg.setWindowTitle("Play Lists");
    connect(&dlg, &PlaylistDialog::playlistSelected, this, &MainWindow::afficherPlaylist);
    dlg.exec(); // Ouvre la boîte de dialogue
}

void MainWindow::afficherPlaylist(const QMap <QString,QString> fichier)
{
    ui->listWidget->clear();
    playlistCourante.clear();
    isPlayList = true;
    for (const QString &titre : fichier.keys()){
        QListWidgetItem * item= new QListWidgetItem (titre);
        item->setData(Qt::UserRole,fichier.value(titre));
        ui->listWidget->addItem(item);
        playlistCourante.append(titre);
    }
}

void MainWindow::on_settingButton_clicked()
{
    SettingDialog dlg(this);
    dlg.setWindowTitle("Setting");
    dlg.exec(); // Ouvre la boîte de dialogue
    // Tu peux recharger les réglages ici si besoin
}

void MainWindow::on_movePlayList_clicked()
{
    switch (currentMode) {
    case RepeatAll:
        currentMode = RepeatOne;
        ui->movePlayList->setText("🔂");
        break;
    case RepeatOne:
        currentMode = Shuffle;
        ui->movePlayList->setText("🔀");
        break;
    case Shuffle:
        currentMode = RepeatAll;
        ui->movePlayList->setText("🔁");
        break;
    }
}

void MainWindow::playNextSong()
{
    qDebug() << "Not Current Mode" << currentMode;
    if (playlistCourante.isEmpty()){
        qDebug() << "Play List courante est vide......";
        return;

    }
    int total = playlistCourante.size();

    if (currentMode == 0){
        qDebug() << "Passe All";
        int currentRow = ui->listWidget->currentRow();
        if (currentRow < ui->listWidget->count() - 1) {
            qDebug() << "Argument All";
            ui->listWidget->setCurrentRow(currentRow + 1);
            onFileClicked(ui->listWidget->currentItem());
        }
        else {
            ui->listWidget->setCurrentRow(0);
            onFileClicked(ui->listWidget->currentItem());
        }
    }
    if (currentMode == 1) {
        // Relancer la même chanson
        onFileClicked(ui->listWidget->currentItem());
    }

    int nextIndex;

    if (currentMode == 2) {
        // Choisir une chanson aléatoire
        nextIndex = QRandomGenerator::global()->bounded(total);
        ui->listWidget->setCurrentRow(nextIndex);
        onFileClicked(ui->listWidget->currentItem());

    }
}

void MainWindow::filtrerListe(const QString &texte) {
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        bool correspond = item->text().contains(texte, Qt::CaseInsensitive);
        item->setHidden(!correspond); // cacher les éléments qui ne correspondent pas
    }
}

MainWindow::~MainWindow() {
    delete ui;
    delete setSound;
}
