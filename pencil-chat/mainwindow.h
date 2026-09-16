#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class LoginDialog;
class RegisterDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void SlotSwitchReg();

private:
    Ui::MainWindow *ui;
    LoginDialog *_login_dlg = nullptr;
    RegisterDialog *_reg_dlg = nullptr;
};
#endif // MAINWINDOW_H
