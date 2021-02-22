#ifndef CRIMESTATSMAIN_H
#define CRIMESTATSMAIN_H

#include <QWidget>

namespace Ui {
class crimeStatsMain;
}

class crimeStatsMain : public QWidget
{
    Q_OBJECT

public:
    explicit crimeStatsMain(QWidget *parent = nullptr);
    ~crimeStatsMain();

private:
    Ui::crimeStatsMain *ui;
};

#endif // CRIMESTATSMAIN_H
