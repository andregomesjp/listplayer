#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <QString>

class Playlist
{
public:
    Playlist(const QString &name, const int &id);
    virtual ~Playlist();
    QString GetName() const;
    int GetId() const;
private:
    QString m_name;
    int m_id;
};
//! [0]

#endif // TREEITEM_H
