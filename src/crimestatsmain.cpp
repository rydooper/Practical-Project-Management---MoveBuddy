#include "headers/crimestatsmain.h"
#include "ui_crimestatsmain.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

struct Stats {
    string areaCode;
    string areaName;
    string totalCrime;
    string violentCrime;
    string sexOffCrime;
    string robCrime;
    string theftCrime;
    string damageCrime;
    string drugCrime;
    string otherCrime;
};

struct Stats NottsStats;
struct Stats DerbyStats;


crimeStatsMain::crimeStatsMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::crimeStatsMain)
{
    ui->setupUi(this);
    string line;

    ifstream allStats;
    allStats.open("crimeStats.txt");
    if (allStats.is_open()) {
        while (getline(allStats, line)) {
            stringstream ss(line);
            if (NottsStats.areaCode.empty()) {
                ss >> NottsStats.areaCode >> NottsStats.areaName >> NottsStats.totalCrime >> NottsStats.violentCrime >> NottsStats.sexOffCrime >> NottsStats.robCrime >> NottsStats.theftCrime >> NottsStats.damageCrime >> NottsStats.drugCrime >> NottsStats.otherCrime;
            } else if ((DerbyStats.areaCode.empty()) || (DerbyStats.areaCode == NottsStats.areaCode))  {
                ss >> DerbyStats.areaCode >> DerbyStats.areaName >> DerbyStats.totalCrime >> DerbyStats.violentCrime >> DerbyStats.sexOffCrime >> DerbyStats.robCrime >> DerbyStats.theftCrime >> DerbyStats.damageCrime >> DerbyStats.drugCrime >> DerbyStats.otherCrime;
            }
        }
    }
    allStats.close();
}


crimeStatsMain::~crimeStatsMain()
{
    delete ui;
}

void crimeStatsMain::on_returnButton_clicked()
{
    //return to nav
    emit exit();
}

void crimeStatsMain::on_crimeTypeDropDown_activated(int index)
{
    int crimeNum =0;
    if (index ==0) {
        //total crimes
        if (ui->locationDropDown->currentIndex() == 0) {
            crimeNum = stoi(NottsStats.totalCrime);
            ui->LCDNum->display(crimeNum);
        } else if(ui->locationDropDown->currentIndex() == 1) {
            crimeNum = stoi(DerbyStats.totalCrime);
            ui->LCDNum->display(crimeNum);
        }
    }
    else if (index ==1) {
        //violent crimes
        if (ui->locationDropDown->currentIndex() == 0) {
            crimeNum = stoi(NottsStats.violentCrime);
            ui->LCDNum->display(crimeNum);
        } else if(ui->locationDropDown->currentIndex() == 1) {
            crimeNum = stoi(DerbyStats.violentCrime);
            ui->LCDNum->display(crimeNum);
        }
    }
    else if (index ==2) {
        //sexual offence crimes
        if (ui->locationDropDown->currentIndex() == 0) {
            crimeNum = stoi(NottsStats.sexOffCrime);
            ui->LCDNum->display(crimeNum);
        } else if(ui->locationDropDown->currentIndex() == 1) {
            crimeNum = stoi(DerbyStats.sexOffCrime);
            ui->LCDNum->display(crimeNum);
        }
    }
    else if (index ==3) {
        //robbery
        if (ui->locationDropDown->currentIndex() == 0) {
            crimeNum = stoi(NottsStats.robCrime);
            ui->LCDNum->display(crimeNum);
        } else if(ui->locationDropDown->currentIndex() == 1) {
            crimeNum = stoi(DerbyStats.robCrime);
            ui->LCDNum->display(crimeNum);
        }
    }
    else if (index ==4) {
        //theft
        if (ui->locationDropDown->currentIndex() == 0) {
            crimeNum = stoi(NottsStats.theftCrime);
            ui->LCDNum->display(crimeNum);
        } else if(ui->locationDropDown->currentIndex() == 1) {
            crimeNum = stoi(DerbyStats.theftCrime);
            ui->LCDNum->display(crimeNum);
        }
    }
    else if (index ==5) {
        //criminal damages
        if (ui->locationDropDown->currentIndex() == 0) {
            crimeNum = stoi(NottsStats.damageCrime);
            ui->LCDNum->display(crimeNum);
        } else if(ui->locationDropDown->currentIndex() == 1) {
            crimeNum = stoi(DerbyStats.damageCrime);
            ui->LCDNum->display(crimeNum);
        }
    }
    else if (index ==6) {
        //drug crimes
        if (ui->locationDropDown->currentIndex() == 0) {
            crimeNum = stoi(NottsStats.drugCrime);
            ui->LCDNum->display(crimeNum);
        } else if(ui->locationDropDown->currentIndex() == 1) {
            crimeNum = stoi(DerbyStats.drugCrime);
            ui->LCDNum->display(crimeNum);
        }
    }
    else if (index ==7) {
        //any other crimes
        if (ui->locationDropDown->currentIndex() == 0) {
            crimeNum = stoi(NottsStats.otherCrime);
            ui->LCDNum->display(crimeNum);
        } else if(ui->locationDropDown->currentIndex() == 1) {
            crimeNum = stoi(DerbyStats.otherCrime);
            ui->LCDNum->display(crimeNum);
        }
    }
}
