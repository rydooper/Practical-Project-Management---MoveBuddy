#include "headers/communitypagewindow.h"
#include "ui_communitypagewindow.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

communityPageWindow::communityPageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::communityPageWindow)
{
    ui->setupUi(this);
}

communityPageWindow::~communityPageWindow()
{
    delete ui;
}

void communityPageWindow::on_returnMenuButton_clicked()
{
    emit exit();
}

void communityPageWindow::on_locationDropDown_activated(int index)
{
    //change of dropdown to load users in the area
    fstream userData;
    string line, usernames, passwords, email, privacy, location, usersInArea, userContact;
    //stringstream ss;
    userData.open("userDetails.txt");
    if (userData.is_open()) {
        while (getline(userData, line)) {
            stringstream ss(line);
            ss >> usernames >> passwords >> email >> privacy >> location;
            if ((privacy == "public") && (location == "Nottinghamshire") && (index==0)) {
                usersInArea += usernames + "\n";
                userContact += email + "\n";
            } else if ((privacy=="public") && (location == "Derbyshire") && (index==1)) {
                usersInArea += usernames + "\n";
                userContact += email + "\n";
            }
        }
        ui->usersInAreaLabel->setText(usersInArea.c_str());
        ui->contactLabel->setText(userContact.c_str());
    } else {
        ui->usersInAreaLabel->setText("Error! Please contact admin!");
    }
    userData.close();
}
