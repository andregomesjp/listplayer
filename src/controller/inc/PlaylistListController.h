#ifndef PLAYLIST_LIST_CONTROLLER_H_
#define PLAYLIST_LIST_CONTROLLER_H_

#include "PlaylistListView.h"
#include "PlaylistListModel.h"

#include <memory>

#include <QObject>
#include <QVector>

class PlaylistListController : public QObject
{
    Q_OBJECT
public:
    PlaylistListController(std::shared_ptr<PlaylistListModel> model,
                           PlaylistListView *view);
    ~PlaylistListController();

private:
    void m_OnAddPlaylistEvent();
    void m_OnRemovePlaylistEvent();
    void m_OnEditPlaylistEvent();
    void m_OnPlayPlaylistEvent();
    void m_OnCloseEvent();
    std::shared_ptr<PlaylistListModel> m_model;
    PlaylistListView *m_view;
};

#endif
