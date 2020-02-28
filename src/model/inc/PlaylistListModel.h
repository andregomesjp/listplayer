#ifndef PLAYLIST_LIST_MODEL_H_
#define PLAYLIST_LIST_MODEL_H_

#include "Playlist.h"

#include <QAbstractTableModel>
#include <QVariant>
#include <QList>

class PlaylistListModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit PlaylistListModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    void InsertPlaylist(const Playlist &playlist);
private:
    QList<Playlist> m_data;
};

#endif
