#include "logindialog.h"
#include "mainwindow.h"
#include "registerdialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _login_dlg = new LoginDialog();
    setCentralWidget(_login_dlg);
    _login_dlg->show();

    connect(_login_dlg, &LoginDialog::switchRegister,
            this, &MainWindow::SlotSwitchReg);
}

void MainWindow::SlotSwitchReg()
{
    // Create the registration page only when it is first requested.
    if (!_reg_dlg) {
        _reg_dlg = new RegisterDialog(this);
        _reg_dlg->setWindowFlags(Qt::Widget);
    }

    setCentralWidget(_reg_dlg);
    // QMainWindow schedules the old central widget for deletion.
    _login_dlg = nullptr;
    _reg_dlg->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
