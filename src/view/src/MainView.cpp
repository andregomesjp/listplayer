#include "MainView.h"

MainView::MainView(QWidget *parent):
    QWidget(parent),
    m_gridLayout(nullptr),
    m_playlistNameLabel(nullptr),
    m_playlistNameEdit(nullptr),
    m_addPlaylistButton(nullptr),
    m_delPlaylistButton(nullptr),
    m_closeButton(nullptr),
    m_playPlaylistButton(nullptr),
    m_editPlaylistButton(nullptr)
{
    m_CreateGridLayout();
    m_CreateMainLayout();
    setWindowTitle(tr("Screenshot"));
    resize(800, 600);
}

MainView::~MainView()
{}

void MainView::m_CreateGridLayout()
{
    m_gridLayout = new QGridLayout;

    QPixmap pixmap("../resources/icons/add_icon.jpeg");
    QIcon buttonIcon(pixmap);

    m_addPlaylistButton = new QPushButton(buttonIcon, "");
    m_addPlaylistButton->setIconSize(QSize(15, 15));

    m_playlistNameLabel = new QLabel(tr("PlayList Name:"));
    m_playlistNameEdit = new QLineEdit;

    m_gridLayout->addWidget(m_playlistNameLabel, 0, 0);
    m_gridLayout->addWidget(m_playlistNameEdit, 0, 1);
    m_gridLayout->addWidget(m_addPlaylistButton, 0, 2);
    m_gridLayout->setColumnStretch(0, 2);
    m_gridLayout->setColumnStretch(1, 8);
    m_gridLayout->setColumnStretch(2, 1);
}

void MainView::m_CreateMainLayout()
{
    m_verticalLayout = new QVBoxLayout(this);
    
}
