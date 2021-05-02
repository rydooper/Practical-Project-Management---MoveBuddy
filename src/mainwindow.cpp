#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->incorrectLabel->hide();

    ui->stackedWidget->insertWidget(1, &_navWinForm);
    connect(&_navWinForm, SIGNAL(logout()), this, SLOT(returnLogin()));
    ui->passwordInputBox->setEchoMode(QLineEdit::Password);
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
    string usernames;
    string passwords;
    struct userDetails user;

    userDetails.open("userDetails.txt");
    if (userDetails.is_open()) {
        while (getline(userDetails, line)) {
            stringstream ss(line);

            ss >> usernames >> passwords;
            QString userInput = ui->usernameInputBox->text();
            string userInputString = userInput.toLocal8Bit().constData();
            if (userInputString == usernames) {
                QString passInput = ui->passwordInputBox->text();
                string passInputString = passInput.toLocal8Bit().constData();
                if (passInputString == passwords) {
                    ss >> user.username >> user.password >> user.privacy;
                    extern struct userDetails user;

                    ui->stackedWidget->setCurrentIndex(1);
                    ui->usernameInputBox->clear();
                    ui->passwordInputBox->clear();
                    ui->incorrectLabel->hide();
                } else {
                    ui->incorrectLabel->show();
                    break;
                }
            } else {
                continue;
            }
        }
    }

}

void MainWindow::on_exitButton_clicked()
{
    //exit app
    this->close();
}

void MainWindow::returnLogin()
{
    ui->stackedWidget->setCurrentIndex(0);
}
