
#ifndef MAIN_VIEW_H_
#define MAIN_VIEW_H_

#include <QWidget>
#include <QObject>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QPixmap>
#include <QIcon>
#include <QPushButton>
#include <QVBoxLayout>

class MainView : public QWidget
{
    Q_OBJECT

public:
    MainView(QWidget *parent = 0);
    ~MainView();
private:
    void m_CreateGridLayout();
    void m_CreateMainLayout();
    QGridLayout *m_gridLayout;
    QVBoxLayout *m_verticalLayout;

    QLabel *m_playlistNameLabel;
    QLineEdit *m_playlistNameEdit;
    QPushButton *m_addPlaylistButton;
    QPushButton *m_delPlaylistButton;
    QPushButton *m_closeButton;
    QPushButton *m_playPlaylistButton;
    QPushButton *m_editPlaylistButton;
};

#endif  // MainView.h
