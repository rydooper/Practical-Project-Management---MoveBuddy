#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>

namespace Ui {
class profile;
}

class profile : public QWidget
{
    Q_OBJECT

public:
    explicit profile(QWidget *parent = nullptr);
    ~profile();

signals:
    void exit();

private slots:
    void on_backMain_clicked();

    void on_setNewButton_clicked();

    void on_viewDetailsButton_clicked();

private:
    Ui::profile *ui;
};

#endif // PROFILE_H
