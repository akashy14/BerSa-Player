#ifndef SOUND_H
#define SOUND_H

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>

#include <QString>
#include <QtCore/QObject>

class Sound :public  QObject
{
    Q_OBJECT
public:
    Sound(QAudioOutput * output ,QObject *parent = nullptr);
    ~Sound ();

    void uploadfile(const QUrl &url);
    void play();
    void pause();
    void stop();

    bool refe = false;
    QMediaPlayer* getPlayer() const { return player; }

private:
    QMediaPlayer * player;
    QAudioOutput * output;


};

#endif // SOUND_H
