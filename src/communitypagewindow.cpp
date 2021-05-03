#include "headers/communitypagewindow.h"
#include "ui_communitypagewindow.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
stringstream ss;

communityPageWindow::communityPageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::communityPageWindow)
{
    ui->setupUi(this);

    string line;
    ifstream usersDetails;
    usersDetails.open(".txt");
    if (usersDetails.is_open()) {
        while (getline(usersDetails, line)) {
            stringstream ss(line);
            //ss << user.username << user.password
        }
    }
    usersDetails.close();
}

communityPageWindow::~communityPageWindow()
{
    delete ui;
}

void communityPageWindow::on_returnButton_clicked()
{
    emit exit();
}

void communityPageWindow::on_locationDropDown_activated(int index)
{
    //change of dropdown to load users in the area
    //if ((index == 0) && ()) {
    stringstream ss;
    if (index == 0) {
        if (ss[index] == "Nottinghamshire") {
            cout << "notts! \n";
        }
    }
}
