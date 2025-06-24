#include "sound.h"


Sound::Sound(QAudioOutput * output,QObject *parent) : QObject(parent), output(output) {
    player = new QMediaPlayer(this);
    player->setAudioOutput(output);
}

void Sound::uploadfile(const QUrl &url) {
    player->setSource(url);
}

void Sound::play() {
    player->play();
    refe = true;
}

void Sound::pause() {
    player->pause();
    refe = false;
}

void Sound::stop() {
    player->stop();
}

Sound::~Sound (){
    delete player;
    delete output;
}
