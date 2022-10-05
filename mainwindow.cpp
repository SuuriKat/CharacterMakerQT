#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

int points = 20;
int usedPointsPower = 0;
int usedPointsSpeed = 0;
int usedPointsIQ = 0;
int usedPointsLuck = 0;
int usedPointsAll = 0;
int havePoints = 0;
int maximumPower = 10;
int maximumSpeed = 10;
int maximumLuck = 10;
int maximumIQ = 10;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelPoints->setNum(points);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void isThereAnyPoints(Ui::MainWindow * ui, int have)
{
    if (have <= 0)
    {
       ui->boxPower->setMaximum(usedPointsPower);
       ui->boxSpeed->setMaximum(usedPointsSpeed);
       ui->boxIQ->setMaximum(usedPointsIQ);
       ui->boxLuck->setMaximum(usedPointsLuck);
    }
    else
    {
        ui->boxPower->setMaximum(maximumPower);
        ui->boxSpeed->setMaximum(maximumSpeed);
        ui->boxIQ->setMaximum(maximumIQ);
        ui->boxLuck->setMaximum(maximumLuck);
    }
}

//void setColorOfText(Ui::MainWindow * ui, QLabel label, int arg1)
//{
//    if (arg1 == 0)
//        ui->label->setStyleSheet("QLabel { color : black; font-size: 48px }");
//    if (arg1 >= 1)
//        ui->label->setStyleSheet("QLabel { color : green; font-size: 48px }");
//    if (arg1 >= 4)
//        ui->label->setStyleSheet("QLabel { color : blue; font-size: 48px}");
//    if (arg1 >= 7)
//        ui->label->setStyleSheet("QLabel { color : red; font-size: 48px}");
//    if (arg1 >= 11)
//        ui->label->setStyleSheet("QLabel { color : purple; font-size: 48px}");
//}


void MainWindow::on_buttonToSecondary_clicked()
{
    QString name = ui->lineName->text();

    int power = ui->boxPower->value();
    int speed = ui->boxSpeed->value();
    int luck = ui->boxLuck->value();
    int iq = ui->boxIQ->value();

    int health = (4 * power) + (2 * speed) + (1 * iq) + (1 * luck);
    int mana = (3 * power) + (1 * speed) + (4 * iq) + (1 * luck);
    int attack = (5 * power) + (3 * speed) + (1 * iq) + (2 * luck);
    int defence = (1 * power) + (3 * speed) + (4 * iq) + (2 * luck);

    if (name.size() < 3)
        QMessageBox::warning(this, "Внимание!", "Имя должно быть длинной от 3 до 20 символов");

    else if (!ui->genderGuy->isChecked() and !ui->genderGirl->isChecked() and !ui->genderOther->isChecked())
        QMessageBox::warning(this, "Внимание!", "Необходимо выбрать пол вашего персонажа");

    else if (ui->boxPower->value() < 1 or ui->boxLuck->value() < 1 or ui->boxIQ->value() < 1 or ui->boxSpeed->value() < 1)
        QMessageBox::warning(this, "Внимание!", "Характеристики не могут быть меньше 1");

    else
    {
        ui->labelMana->setNum(mana);
        ui->labelHealth->setNum(health);
        ui->labelAttack->setNum(attack);
        ui->labelDefence->setNum(defence);
    }

}

void MainWindow::on_buttonClass_clicked()
{
    if (ui->labelHealth->text() != "0")
    {

    }
}

// Проверка на выбор пола и указание характеристик для каждого
void MainWindow::on_genderGuy_toggled(bool checked)
{
    if (checked)
    {
        maximumPower = 12;
        ui->boxPower->setMaximum(maximumPower);
    }
    else
    {
        maximumPower = 10;
        ui->boxPower->setMaximum(maximumPower);
    }
}
void MainWindow::on_genderGirl_toggled(bool checked)
{
    if (checked)
    {
        maximumSpeed = 12;
        ui->boxSpeed->setMaximum(maximumSpeed);
    }
    else
    {
        maximumSpeed = 10;
        ui->boxSpeed->setMaximum(maximumSpeed);
    }
}
void MainWindow::on_genderOther_toggled(bool checked)
{
    if (checked)
    {
        maximumLuck = 12;
        ui->boxLuck->setMaximum(maximumLuck);
    }
    else
    {
        maximumLuck = 10;
        ui->boxLuck->setMaximum(maximumLuck);
    }
}

// Проверка изменений аргументов основных характеристик
void MainWindow::on_boxPower_valueChanged(int arg1)
{
    usedPointsPower = ui->boxPower->value();
    usedPointsAll = usedPointsPower + usedPointsLuck + usedPointsSpeed + usedPointsIQ;
    havePoints = points - usedPointsAll;

    ui->labelPoints->setNum(havePoints);

    isThereAnyPoints(ui, havePoints);

    if (arg1 == 0)
        ui->labelPower->setStyleSheet("QLabel { color : black; font-size: 48px }");
    if (arg1 >= 1)
        ui->labelPower->setStyleSheet("QLabel { color : green; font-size: 48px }");
    if (arg1 >= 4)
        ui->labelPower->setStyleSheet("QLabel { color : blue; font-size: 48px}");
    if (arg1 >= 7)
        ui->labelPower->setStyleSheet("QLabel { color : red; font-size: 48px}");
    if (arg1 >= 11)
        ui->labelPower->setStyleSheet("QLabel { color : purple; font-size: 48px}");
}

void MainWindow::on_boxSpeed_valueChanged(int arg1)
{
    usedPointsSpeed = ui->boxSpeed->value();
    usedPointsAll = usedPointsPower + usedPointsLuck + usedPointsSpeed + usedPointsIQ;
    havePoints = points - usedPointsAll;

    ui->labelPoints->setNum(havePoints);

    isThereAnyPoints(ui, havePoints);

    if (arg1 == 0)
        ui->labelSpeed->setStyleSheet("QLabel { color : black; font-size: 48px }");
    if (arg1 >= 1)
        ui->labelSpeed->setStyleSheet("QLabel { color : green; font-size: 48px }");
    if (arg1 >= 4)
        ui->labelSpeed->setStyleSheet("QLabel { color : blue; font-size: 48px}");
    if (arg1 >= 7)
        ui->labelSpeed->setStyleSheet("QLabel { color : red; font-size: 48px}");
    if (arg1 >= 11)
        ui->labelSpeed->setStyleSheet("QLabel { color : purple; font-size: 48px}");
}

void MainWindow::on_boxIQ_valueChanged(int arg1)
{
    usedPointsIQ = ui->boxIQ->value();
    usedPointsAll = usedPointsPower + usedPointsLuck + usedPointsSpeed + usedPointsIQ;
    havePoints = points - usedPointsAll;

    ui->labelPoints->setNum(havePoints);

    isThereAnyPoints(ui, havePoints);

    if (arg1 == 0)
        ui->labelIQ->setStyleSheet("QLabel { color : black; font-size: 48px }");
    if (arg1 >= 1)
        ui->labelIQ->setStyleSheet("QLabel { color : green; font-size: 48px }");
    if (arg1 >= 4)
        ui->labelIQ->setStyleSheet("QLabel { color : blue; font-size: 48px}");
    if (arg1 >= 7)
        ui->labelIQ->setStyleSheet("QLabel { color : red; font-size: 48px}");
    if (arg1 >= 11)
        ui->labelIQ->setStyleSheet("QLabel { color : purple; font-size: 48px}");
}

void MainWindow::on_boxLuck_valueChanged(int arg1)
{
    usedPointsLuck = ui->boxLuck->value();
    usedPointsAll = usedPointsPower + usedPointsLuck + usedPointsSpeed + usedPointsIQ;
    havePoints = points - usedPointsAll;

    ui->labelPoints->setNum(havePoints);

    isThereAnyPoints(ui, havePoints);

    if (arg1 == 0)
        ui->labelLuck->setStyleSheet("QLabel { color : black; font-size: 48px }");
    if (arg1 >= 1)
        ui->labelLuck->setStyleSheet("QLabel { color : green; font-size: 48px }");
    if (arg1 >= 4)
        ui->labelLuck->setStyleSheet("QLabel { color : blue; font-size: 48px}");
    if (arg1 >= 7)
        ui->labelLuck->setStyleSheet("QLabel { color : red; font-size: 48px}");
    if (arg1 >= 11)
        ui->labelLuck->setStyleSheet("QLabel { color : purple; font-size: 48px}");
}


