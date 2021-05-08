#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <headers/navwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_loginButton_clicked();

    void on_exitButton_clicked();

    void returnLogin();

private:
    Ui::MainWindow *ui;
    navWindow _navWinForm;
};

#endif // MAINWINDOW_H
