#include "Playlist.h"

Playlist::Playlist(const QString &name, const int &id):
    m_name(name),
    m_id(id)
{
}

QString Playlist::GetName() const
{
    return m_name;
}

Playlist::~Playlist()
{
}

int Playlist::GetId() const
{
    return m_id;
}
