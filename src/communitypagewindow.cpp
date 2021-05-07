#include "headers/communitypagewindow.h"
#include "ui_communitypagewindow.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
//QString usernameQS;

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

void communityPageWindow::on_returnButton_clicked()
{
    emit exit();
}

void communityPageWindow::on_locationDropDown_activated(int index)
{
    //change of dropdown to load users in the area
    //stringstream ss;
    /*if (index == 0) {
        //nottinghamshire
        if (usernameQS == "janetSmith") {
            cout << "welcome to notts!";
        }
    }*/
}
