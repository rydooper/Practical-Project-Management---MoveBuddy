#ifndef CRIMESTATSMAP_H
#define CRIMESTATSMAP_H

#include <QWidget>

namespace Ui {
class crimeStatsMap;
}

class crimeStatsMap : public QWidget
{
    Q_OBJECT

public:
    explicit crimeStatsMap(QWidget *parent = nullptr);
    ~crimeStatsMap();

signals:
    void exit();

private slots:
    void on_returnButton_clicked();

    void on_locationDropDown_activated(int index);

private:
    Ui::crimeStatsMap *ui;
};

#endif // CRIMESTATSMAP_H
