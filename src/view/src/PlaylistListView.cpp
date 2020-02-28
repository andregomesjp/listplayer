#include "PlaylistListView.h"
#include <QHeaderView>

#include "Defs.h"

PlaylistListView::PlaylistListView(QWidget *parent):
    QWidget(parent),
    m_addPlaylistLayout(nullptr),
    m_verticalLayout(nullptr),
    m_buttonBoxLayout(nullptr),
    m_playlistTable(nullptr),
    m_playlistNameLabel(nullptr),
    m_playlistNameEdit(nullptr),
    m_addPlaylistButton(nullptr),
    m_delPlaylistButton(nullptr),
    m_closeButton(nullptr),
    m_playPlaylistButton(nullptr),
    m_editPlaylistButton(nullptr)
{
    m_CreateAddPlaylistLayout();
    m_CreateButtonBoxLayout();
    m_CreateMainLayout();
    m_ConnectEvents();
    setWindowTitle(tr("Spotify playlist player"));
    resize(800, 600);
}

PlaylistListView::~PlaylistListView()
{}

void PlaylistListView::SetPlaylistList(PlaylistListModel &playlistListModel)
{
    m_playlistTable->setModel(&playlistListModel);
}

QString PlaylistListView::GetNewPlaylistName() const
{
    return m_playlistNameEdit->text();
}

void PlaylistListView::m_ConnectEvents()
{
    connect(m_addPlaylistButton, &QPushButton::released, this,
            &PlaylistListView::OnAddPlaylistEvent);
    connect(m_delPlaylistButton, &QPushButton::released, this,
            &PlaylistListView::OnRemovePlaylistEvent);
    connect(m_editPlaylistButton, &QPushButton::released, this,
            &PlaylistListView::OnEditPlaylistEvent);
    connect(m_playPlaylistButton, &QPushButton::released, this,
            &PlaylistListView::OnPlayPlaylistEvent);
    connect(m_closeButton, &QPushButton::released, this,
            &PlaylistListView::OnCloseEvent);
}

void PlaylistListView::m_CreateAddPlaylistLayout()
{
    m_addPlaylistLayout = new QGridLayout;
    QString iconPath = QString(ICON_PATH);
    QString buttonIconPath = iconPath + "add_icon.jpeg";
    QPixmap pixmap(buttonIconPath);
    QIcon buttonIcon(pixmap);

    m_addPlaylistButton = new QPushButton(buttonIcon, "");
    m_addPlaylistButton->setIconSize(QSize(15, 15));

    m_playlistNameLabel = new QLabel(tr("PlayList Name:"));
    m_playlistNameEdit = new QLineEdit;

    m_addPlaylistLayout->addWidget(m_playlistNameLabel, 0, 0);
    m_addPlaylistLayout->addWidget(m_playlistNameEdit, 0, 1);
    m_addPlaylistLayout->addWidget(m_addPlaylistButton, 0, 2);
    m_addPlaylistLayout->setColumnStretch(0, 2);
    m_addPlaylistLayout->setColumnStretch(1, 8);
    m_addPlaylistLayout->setColumnStretch(2, 1);
}

void PlaylistListView::m_CreateMainLayout()
{
    m_playlistTable = new QTableView(this);
    m_playlistTable->resizeColumnsToContents();
    m_playlistTable->horizontalHeader()->setStretchLastSection(true);
    m_playlistTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_verticalLayout = new QVBoxLayout;
    m_verticalLayout->insertLayout(0, m_addPlaylistLayout);
    m_verticalLayout->insertWidget(1, m_playlistTable);
    m_verticalLayout->insertLayout(2, m_buttonBoxLayout);
    m_verticalLayout->setStretch(0, 1);
    m_verticalLayout->setStretch(1, 2);
    m_verticalLayout->setStretch(2, 1);


    setLayout(m_verticalLayout);
}

void PlaylistListView::m_CreateButtonBoxLayout()
{
    m_buttonBoxLayout = new QHBoxLayout;
    m_closeButton = new QPushButton("Close");
    m_editPlaylistButton = new QPushButton("Edit");
    m_playPlaylistButton = new QPushButton("Play");
    m_delPlaylistButton = new QPushButton("Remove");
    m_buttonBoxLayout->addWidget(m_closeButton);
    m_buttonBoxLayout->addWidget(m_delPlaylistButton);
    m_buttonBoxLayout->addWidget(m_editPlaylistButton);
    m_buttonBoxLayout->addWidget(m_playPlaylistButton);
}
