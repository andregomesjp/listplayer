
#ifndef PLAYLIST_LIST_VIEW_H_
#define PLAYLIST_LIST_VIEW_H_

#include <QWidget>
#include <QObject>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableView>
#include <QHBoxLayout>

#include "PlaylistListModel.h"

/*! Main View screen */
class PlaylistListView : public QWidget
{
    Q_OBJECT

public:
    /*!
      A more elaborate description of the constructor.
    */
    PlaylistListView(QWidget *parent = 0);

    /*!
      A more elaborate description of the constructor.
    */
    ~PlaylistListView();

    QString GetNewPlaylistName() const;

    void SetPlaylistList(PlaylistListModel &playlistList);

signals:
    void OnAddPlaylistEvent();

    void OnEditPlaylistEvent();

    void OnRemovePlaylistEvent();

    void OnPlayPlaylistEvent();

    void OnCloseEvent();
private:
    /*!
      \brief Brief.
      \param a an integer argument.
      \param s a constant character pointer.
      \return The test results
      \sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
    */
    void m_CreateAddPlaylistLayout();
    void m_CreateMainLayout();
    void m_CreateButtonBoxLayout();
    void m_ConnectEvents();

    QGridLayout *m_addPlaylistLayout;
    QVBoxLayout *m_verticalLayout;
    QHBoxLayout *m_buttonBoxLayout;
    QTableView *m_playlistTable;
    QLabel *m_playlistNameLabel;
    QLineEdit *m_playlistNameEdit;
    QPushButton *m_addPlaylistButton;
    QPushButton *m_delPlaylistButton;
    QPushButton *m_closeButton;
    QPushButton *m_playPlaylistButton;
    QPushButton *m_editPlaylistButton;

    // PlaylistListModel m_model;
};

#endif  // PlaylistListView.h
