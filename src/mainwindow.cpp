#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <sstream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->incorrectLabel->hide();
    ui->stackedWidget->insertWidget(1, &_navWinForm);
    connect(&_navWinForm, SIGNAL(logout()), this, SLOT(returnLogin()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//("~/qt-workspace/PPM_coursework/PPM-MoveBuddy/src/usernameFile.txt");

void MainWindow::on_loginButton_clicked()
{
    //login
    //load in text file, test input data against file line until end of file
    //if data = any line, set
    using namespace std;
    ifstream userDetails;
    string line;
    string usernames[3];
    string passwords[3];
    userDetails.open("usernameFile.txt");
    if (userDetails.is_open()) {
        while (getline(userDetails, line)) {
            stringstream ss(line);
            for (int i=0; i < 3; i++) {
                ss >> usernames[i] >> passwords[i];
            }
        }
        QString userInput = ui->usernameInputBox->text();
        string userInputString = userInput.toLocal8Bit().constData();
        for (int i=0; i < 3; i++) {
            if (userInputString == usernames[i]) {
                QString passInput = ui->passwordInputBox->text();
                string passInputString = passInput.toLocal8Bit().constData();
                if (passInputString == passwords[i]) {
                    ui->stackedWidget->setCurrentIndex(1);
                    ui->usernameInputBox->clear();
                    ui->passwordInputBox->clear();
                    ui->incorrectLabel->hide();
                }
            } else {
                ui->incorrectLabel->show();
            }
        }
    }
} //issue: takes chloeDaniels (last username) would be only valid, need to store each username not just last

void MainWindow::on_exitButton_clicked()
{
    //exit app
    this->close();
}

void MainWindow::returnLogin()
{
    ui->stackedWidget->setCurrentIndex(0);
}
