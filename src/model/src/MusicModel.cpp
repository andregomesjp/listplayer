#include "MusicModel.h"

MusicModel::MusicModel(const QString &musicName, const QString &albumName,
                       const QString &artistName, const QString &spotifyTrackId):
    MusicModel(musicName, albumName, artistName, spotifyTrackId, -1)
{
}

MusicModel::MusicModel(const QString &musicName, const QString &albumName,
                       const QString &artistName, const QString &spotifyTrackId, const int &id):
    m_musicName(musicName),
    m_albumName(albumName),
    m_artistName(artistName),
    m_spotifyTrackId(uri),
    m_id(id)
{
}

QString MusicModel::GetMusicName() const
{
    return m_musicName;
}

QString MusicModel::GetAlbumName() const
{
    return m_albumName;
}

QString MusicModel::GetArtistName() const
{
    return m_artistName;
}

QString MusicModel::GetSpotifyTrackId() const
{
    return m_spotifyTrackId;
}
