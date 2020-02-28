#include "PlaylistListController.h"

PlaylistListController::PlaylistListController(std::shared_ptr<PlaylistListModel> model,
                                               PlaylistListView *view):
    m_model(model),
    m_view(view)
{
    connect(m_view, &PlaylistListView::OnAddPlaylistEvent, this,
            &PlaylistListController::m_OnAddPlaylistEvent);
    connect(m_view, &PlaylistListView::OnRemovePlaylistEvent, this,
        &PlaylistListController::m_OnRemovePlaylistEvent);
    connect(m_view, &PlaylistListView::OnEditPlaylistEvent, this,
            &PlaylistListController::m_OnEditPlaylistEvent);
    connect(m_view, &PlaylistListView::OnPlayPlaylistEvent, this,
            &PlaylistListController::m_OnPlayPlaylistEvent);
    connect(m_view, &PlaylistListView::OnCloseEvent, this,
            &PlaylistListController::m_OnCloseEvent);
    m_view->show();
    m_view->SetPlaylistList(*m_model.get());
}

PlaylistListController::~PlaylistListController()
{
    m_OnCloseEvent();
}

void PlaylistListController::m_OnRemovePlaylistEvent()
{

}

void PlaylistListController::m_OnEditPlaylistEvent()
{

}

void PlaylistListController::m_OnPlayPlaylistEvent()
{

}

void PlaylistListController::m_OnCloseEvent()
{
    if (m_model)
    {
        m_model.reset();
    }
    if (m_view)
    {
        delete m_view;
        m_view = nullptr;
    }
}

void PlaylistListController::m_OnAddPlaylistEvent()
{
    QString playlistName = m_view->GetNewPlaylistName();
    m_model->InsertPlaylist(Playlist(playlistName, 0));
}
