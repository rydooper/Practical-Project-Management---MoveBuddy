#include "headers/profile.h"
#include "src/mainwindow.cpp"
#include "ui_profile.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>

using namespace std;
profile::profile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
    ui->errorLabel->hide();
}

profile::~profile()
{
    delete ui;
}

void profile::on_backMain_clicked()
{
    //return to nav page
    emit exit();
    ui->usernameInputBox->clear();
    ui->passwordInputBox->clear();
    ui->privacyInputBox->clear();
    ui->emailInputBox->clear();
    ui->locationInputBox->clear();
}

void profile::on_setNewButton_clicked()
{
    //set new username + password
    //old data
    QString allData = usernameQS + passwordQS + emailQS + privacyQS + locationQS;
    string usernameStr = usernameQS.toLocal8Bit().constData(), passwordStr = passwordQS.toLocal8Bit().constData(), emailStr = emailQS.toLocal8Bit().constData();
    string privacyStr = privacyQS.toLocal8Bit().constData(), localStr = locationQS.toLocal8Bit().constData();
    string oldDataStr = usernameStr + " " + passwordStr + " " + emailStr + " " + privacyStr + " " + localStr;

    //new changed data
    QString newuser=ui->usernameInputBox->text(), newpass=ui->passwordInputBox->text(), newemail=ui->emailInputBox->text();
    QString newprivacy=ui->privacyInputBox->text(), newlocal=ui->locationInputBox->text();
    string newuserStr = newuser.toLocal8Bit().constData(), newpassStr = newpass.toLocal8Bit().constData(), newemailStr = newemail.toLocal8Bit().constData();
    string newprivacyStr = newprivacy.toLocal8Bit().constData(), newlocalStr = newlocal.toLocal8Bit().constData();
    string newData = newuserStr + " " + newpassStr + " " + newemailStr + " " + newprivacyStr + " " + newlocalStr;

    //loads files to be read from/to
    ifstream filereadin("userDetails.txt"); //File to read from
    ofstream filetempout("tempUserDetails.txt"); //Temporary file
    if(!filereadin || !filetempout) {
        cout << "Error opening files!" << endl;
    }

    string line, userDetails;
    int counter =0;
    while(filereadin >> line) {
        userDetails += line + " ";
        counter += 1;
        if (counter==5) {
            //removes any whitespaces at the end of the file
            string whitespaces (" \t\f\v\n\r");
            size_t found = userDetails.find_last_not_of(whitespaces);
            if (found!=string::npos) {
                userDetails.erase(found+1);
            } else {
                userDetails.clear(); //if string is entirely empty this runs
            }

            //resets userDetails to newData if they match
            if(userDetails == oldDataStr) {
                usernameQS = newuser;
                passwordQS = newpass;
                emailQS = newemail;
                privacyQS = newprivacy;
                locationQS = newlocal;
                userDetails = newData;
            }
            filetempout << userDetails;
            filetempout << "\n";
            counter =0;
            userDetails = "";
        }
    }
    filereadin.close();
    filetempout.close();

    //resets file names
    char file_name[] = "userDetails.txt";
    char new_file_name[] = "temp2.txt";
    if (rename(file_name, new_file_name) != 0) {
        perror("There is an error!");
    } else {
        int status = remove(new_file_name);
        if (status !=0) {
            cout << "error deleting files!" << endl;
        }
    }
    char filename[] = "tempUserDetails.txt";
    char newfilename[] = "userDetails.txt";
    if (rename(filename, newfilename) != 0) {
        perror("There is an error!");
    }
}

void profile::on_viewDetailsButton_clicked() {
    //view details
    //load data from global vars, which were loaded from file
    ui->usernameInputBox->setText(usernameQS);
    ui->passwordInputBox->setText(passwordQS);
    ui->emailInputBox->setText(emailQS);
    ui->privacyInputBox->setText(privacyQS);
    ui->locationInputBox->setText(locationQS);
}
