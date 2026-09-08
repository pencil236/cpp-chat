#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QLabel>
#include <QLineEdit>
#include <QPixmap>
#include <QPushButton>
#include <QStringList>
#include <QWidget>

namespace {

bool require(bool condition, const QString &message)
{
    if (!condition) {
        qCritical("Smoke test failed: %s", qPrintable(message));
    }
    return condition;
}

} // namespace

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile qss(QStringLiteral(":/style/stylesheet.qss"));
    if (qss.open(QFile::ReadOnly | QFile::Text)) {
        app.setStyleSheet(QString::fromUtf8(qss.readAll()));
    }

    MainWindow window;
    window.show();
    app.processEvents();

    bool passed = true;
    passed &= require(window.size() == QSize(300, 500), QStringLiteral("window must be 300x500"));
    passed &= require(window.windowTitle() == QStringLiteral("llfcchat"), QStringLiteral("window title mismatch"));
    passed &= require(window.centralWidget() != nullptr
                          && window.centralWidget()->objectName() == QStringLiteral("LoginDialog"),
                      QStringLiteral("LoginDialog must be the central widget"));
    passed &= require(window.centralWidget() != nullptr && !window.centralWidget()->isWindow(),
                      QStringLiteral("LoginDialog must not remain a separate top-level window"));

    const auto *userEdit = window.findChild<QLineEdit *>(QStringLiteral("user_edit"));
    const auto *passEdit = window.findChild<QLineEdit *>(QStringLiteral("pass_edit"));
    const auto *loginButton = window.findChild<QPushButton *>(QStringLiteral("login_btn"));
    const auto *registerButton = window.findChild<QPushButton *>(QStringLiteral("reg_btn"));
    const auto *headLabel = window.findChild<QLabel *>(QStringLiteral("head_label"));

    passed &= require(userEdit != nullptr, QStringLiteral("user_edit is missing"));
    passed &= require(passEdit != nullptr, QStringLiteral("pass_edit is missing"));
    passed &= require(loginButton != nullptr, QStringLiteral("login_btn is missing"));
    passed &= require(registerButton != nullptr, QStringLiteral("reg_btn is missing"));
    passed &= require(headLabel != nullptr && !headLabel->pixmap(Qt::ReturnByValue).isNull(),
                      QStringLiteral("head image resource is missing"));
    passed &= require(passEdit != nullptr && passEdit->echoMode() == QLineEdit::Password,
                      QStringLiteral("password input is not masked"));

    if (argc > 1) {
        const QPixmap screenshot = window.centralWidget()->grab();
        passed &= require(screenshot.save(QString::fromLocal8Bit(argv[1])),
                          QStringLiteral("could not save screenshot"));
    }

    return passed ? 0 : 1;
}
