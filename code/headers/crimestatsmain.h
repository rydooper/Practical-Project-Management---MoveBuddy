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

signals:
    void exit();

private slots:

    void on_returnButton_clicked();

    void on_crimeTypeDropDown_activated(int index);

private:
    Ui::crimeStatsMain *ui;
};

#endif // CRIMESTATSMAIN_H
