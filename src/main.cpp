#include <QApplication>
#include <QLabel>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel hello("<center> Nat vou estudar mt <center>");
    hello.setWindowTitle("My first qt program");
    hello.resize(400, 400);
    hello.show();
    return app.exec();
}
