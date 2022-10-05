#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonToSecondary_clicked();

    void on_genderGuy_toggled(bool checked);

    void on_genderGirl_toggled(bool checked);

    void on_genderOther_toggled(bool checked);

    void on_boxPower_valueChanged(int arg1);

    void on_boxSpeed_valueChanged(int arg1);

    void on_boxIQ_valueChanged(int arg1);

    void on_boxLuck_valueChanged(int arg1);

    void on_buttonClass_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
