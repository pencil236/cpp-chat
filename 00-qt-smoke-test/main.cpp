#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel window("Qt 5.15.2 environment is ready");
    window.setWindowTitle("Qt environment check");
    window.resize(420, 160);
    window.setAlignment(Qt::AlignCenter);
    window.show();

    return app.exec();
}
