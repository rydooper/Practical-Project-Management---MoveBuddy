#ifndef NAVWINDOW_H
#define NAVWINDOW_H

#include <QWidget>
#include <headers/profile.h>
#include <headers/crimestatsmain.h>
#include <headers/crimestatsmap.h>
#include <headers/communitypagewindow.h>

namespace Ui {
class navWindow;
}

class navWindow : public QWidget
{
    Q_OBJECT

public:
    explicit navWindow(QWidget *parent = nullptr);
    ~navWindow();

signals:
    void logout();

private slots:
    void on_logoutButton_clicked();

    void on_crimeStatsButton_clicked();

    void returnNav();

    void on_viewProfileButton_clicked();

    void on_crimeStatsMapButton_clicked();

    void on_communityPageButton_clicked();

private:
    Ui::navWindow *ui;
    crimeStatsMain _crimeStatsForm;
    profile _profileForm;
    crimeStatsMap _crimeStatsMapForm;
    communityPageWindow _communityPageWindow;
};

#endif // NAVWINDOW_H
