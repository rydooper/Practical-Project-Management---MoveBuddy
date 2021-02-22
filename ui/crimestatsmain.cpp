#include "crimestatsmain.h"
#include "ui_crimestatsmain.h"

crimeStatsMain::crimeStatsMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::crimeStatsMain)
{
    ui->setupUi(this);
}

crimeStatsMain::~crimeStatsMain()
{
    delete ui;
}
