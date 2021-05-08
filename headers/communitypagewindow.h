#ifndef COMMUNITYPAGEWINDOW_H
#define COMMUNITYPAGEWINDOW_H

#include <QWidget>

namespace Ui {
class communityPageWindow;
}

class communityPageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit communityPageWindow(QWidget *parent = nullptr);
    ~communityPageWindow();

signals:
    void exit();

private slots:
    void on_returnMenuButton_clicked();

    void on_locationDropDown_activated(int index);

private:
    Ui::communityPageWindow *ui;
};

#endif // COMMUNITYPAGEWINDOW_H
