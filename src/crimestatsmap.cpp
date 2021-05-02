#include "headers/crimestatsmap.h"
#include "ui_crimestatsmap.h"
#include <QPixmap>

crimeStatsMap::crimeStatsMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::crimeStatsMap)
{
    ui->setupUi(this);
}

crimeStatsMap::~crimeStatsMap()
{
    delete ui;
}

void crimeStatsMap::on_returnButton_clicked()
{
    emit exit();
}

void crimeStatsMap::on_locationDropDown_activated(int index)
{
    if (index == 0) {
        QPixmap nottsmap("nottsmap.png");
        //int mapHeight = ui->mapImageLabel->height();
        //QPixmap qmapImage = nottsmap::scaledToHeight(mapHeight);
                //scaledToHeight(ui->mapImageLabel->height() Qt::TransformationMode mode = Qt::FastTransformation);
        ui->mapImageLabel->setPixmap(nottsmap);
    } else if (index==1) {
        QPixmap derbymap("derbymap.png");
        ui->mapImageLabel->setPixmap(derbymap);
    }
}
