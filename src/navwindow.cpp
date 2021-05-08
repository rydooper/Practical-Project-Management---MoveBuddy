#include "headers/navwindow.h"
#include "ui_navwindow.h"

navWindow::navWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::navWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1, &_crimeStatsForm);
    ui->stackedWidget->insertWidget(2,&_profileForm);
    ui->stackedWidget->insertWidget(3, &_crimeStatsMapForm);
    ui->stackedWidget->insertWidget(4, &_communityPageWindow);

    connect(&_crimeStatsForm, SIGNAL(exit()), this, SLOT(returnNav()));
    connect(&_profileForm, SIGNAL(exit()), this, SLOT(returnNav()));
    connect(&_crimeStatsMapForm, SIGNAL(exit()), this, SLOT(returnNav()));
    connect(&_communityPageWindow, SIGNAL(exit()), this, SLOT(returnNav()));
}

navWindow::~navWindow()
{
    delete ui;
}

void navWindow::on_logoutButton_clicked()
{
    emit logout();
}

void navWindow::on_crimeStatsButton_clicked()
{
    //view stats page
    ui->stackedWidget->setCurrentIndex(1);
}

void navWindow::on_viewProfileButton_clicked()
{
    //view profile page
    ui->stackedWidget->setCurrentIndex(2);
}


void navWindow::on_crimeStatsMapButton_clicked()
{
    //view stats map
    ui->stackedWidget->setCurrentIndex(3);
}

//for returning to this page from other windows
void navWindow::returnNav()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void navWindow::on_communityPageButton_clicked()
{
    //view community page
    ui->stackedWidget->setCurrentIndex(4);
}
