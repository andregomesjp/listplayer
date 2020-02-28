#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <memory>
#include "PlaylistListView.h"
#include "PlaylistListModel.h"
#include "PlaylistListController.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    std::shared_ptr<PlaylistListModel> playlistListModel = std::make_shared<PlaylistListModel>();
    PlaylistListView *view = new PlaylistListView();
    PlaylistListController listController(playlistListModel, view);
    // view.SetPlaylistList(playlistListModel);
    // view.show();
    // QLabel hello("<center> Nat vou estudar mt <center>");
    // hello.setWindowTitle("My first qt program");
    // hello.resize(400, 400);
    // hello.show();
    return app.exec();
}
