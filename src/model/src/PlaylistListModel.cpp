#include "PlaylistListModel.h"

PlaylistListModel::PlaylistListModel(QObject *parent):
    QAbstractTableModel(parent)
{}

int PlaylistListModel::rowCount(const QModelIndex &parent) const
{
    return m_data.count();
}

int PlaylistListModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant PlaylistListModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole && role != Qt::EditRole)
    {
        return {};
    }
    const auto &playlist = m_data[index.row()];
    if (index.column() == 0)
    {
        return playlist.GetId();
    }
    else
    {
        return playlist.GetName();
    }
}

QVariant PlaylistListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
    {
        return {};
    }
    return section == 0 ? "id" : "Playlist Name";
}

void PlaylistListModel::InsertPlaylist(const Playlist &playlist)
{
    beginInsertRows({}, m_data.count(), m_data.count());
    m_data.append(playlist);
    endInsertRows();
}
