#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mwMiddleTier = new MainWindowMiddleTier(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->mwMiddleTier;
}

double MainWindow::getFahrenheitValue()
{
    return ui->edtFahrenheit->text().toDouble();
}

void MainWindow::setFahrenheitValue(const double &value)
{
    ui->edtFahrenheit->setText(QString::number(value));
}

void MainWindow::toggleFahrenheitValidState(const bool &value)
{
    //change color, blink or smth
}

double MainWindow::getCelsiusValue()
{
    return ui->edtCelsius->text().toDouble();
}

void MainWindow::setCelsiusValue(const double &value)
{
    ui->edtCelsius->setText(QString::number(value));
}

void MainWindow::toggleCelsiusValidState(const bool &value)
{
    //change color, blink or smth
}

void MainWindow::on_edtCelsius_textEdited(const QString &arg1)
{
    this->mwMiddleTier->processCelsiusInput();
}

void MainWindow::on_edtFahrenheit_textEdited(const QString &arg1)
{
    this->mwMiddleTier->processFahrenheitInput();
}
