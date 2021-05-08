#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <QMessageBox>

QString usernameQS;
QString loggedInUser;
QString passwordQS;
QString emailQS;
QString privacyQS;
QString locationQS;


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

void MainWindow::on_loginButton_clicked()
{
    //login
    //load in text file, test input data against file line until end of file
    using namespace std;
    ifstream userDetails;
    string line;
    string usernames;
    string passwords;
    string email;
    string privacy;
    string location;

    userDetails.open("userDetails.txt");
    if (userDetails.is_open()) {
        while (getline(userDetails, line)) {
            stringstream ss(line);
            ss >> usernames >> passwords >> email >> privacy >> location;
            QString userInput = ui->usernameInputBox->text();
            string userInputString = userInput.toLocal8Bit().constData(); //QString to string is .toLocal8Bit().constData()

            if (userInputString == usernames) {
                QString passInput = ui->passwordInputBox->text();
                string passInputString = passInput.toLocal8Bit().constData();

                if (passInputString == passwords) {

                    ui->stackedWidget->setCurrentIndex(1);
                    ui->usernameInputBox->clear();
                    ui->passwordInputBox->clear();

                    usernameQS = userInput, loggedInUser = userInput, passwordQS = passInput;
                    emailQS = email.c_str(), privacyQS = privacy.c_str(), locationQS = location.c_str();
                    //string to QString is .c_str()
                } else {
                    ui->incorrectLabel->show();
                    break;
                }
            } else {
                continue;
            }
        }
    }
    userDetails.close();
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
