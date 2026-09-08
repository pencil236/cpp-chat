#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName(QStringLiteral("llfcchat"));
    app.setWindowIcon(QIcon(QStringLiteral(":/res/icon.ico")));

    QFile qss(QStringLiteral(":/style/stylesheet.qss"));
    if (qss.open(QFile::ReadOnly | QFile::Text)) {
        app.setStyleSheet(QString::fromUtf8(qss.readAll()));
    }

    MainWindow window;
    window.show();

    return app.exec();
}
