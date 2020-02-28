
#ifndef MUSIC_MODEL_H
#define MUSIC_MODEL_H

#include <QJsonObject>
#include <QString>

class MusicModel
{
public:
    MusicModel(const QString &musicName, const QString &albumName,
                        const QString &artistName, const QString &spotifyTrackId);
    MusicModel(const QString &musicName, const QString &albumName, const QString &artistName,
               const QString &spotifyTrackId, const int &id);
    virtual ~MusicModel();

    QString GetMusicName() const;
    QString GetAlbumName() const;
    QString GetArtistName() const;
    QString GetSpotifyTrackId() const;
    int GetId() const;
private:
    QString m_musicName;
    QString m_albumName;
    QString m_artistName;
    QString m_spotifyTrackId;
    const int m_id;
};

#endif
