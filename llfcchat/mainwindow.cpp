#include "mainwindow.h"

#include "logindialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , loginDialog(nullptr)
{
    ui->setupUi(this);

    loginDialog = new LoginDialog(this);
    setCentralWidget(loginDialog);
    loginDialog->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
