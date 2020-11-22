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

double MainWindow::getFarenheitValue()
{
    return ui->edtFarenheit->text().toDouble();
}

void MainWindow::setFarenheitValue(const double &value)
{
    ui->edtFarenheit->setDisabled(true);
    ui->edtFarenheit->setText(QString::number(value));
    ui->edtFarenheit->setDisabled(false);
}

void MainWindow::toggleFarenheitValidState(const bool &value)
{
    //change color, blink or smth
}

double MainWindow::getCelsiusValue()
{
    return ui->edtCelsius->text().toDouble();
}

void MainWindow::setCelsiusValue(const double &value)
{
    ui->edtCelsius->setDisabled(true);
    ui->edtCelsius->setText(QString::number(value));
    ui->edtCelsius->setDisabled(false);
}

void MainWindow::toggleCelsiusValidState(const bool &value)
{
    //change color, blink or smth
}

void MainWindow::on_edtCelsius_textChanged(const QString &arg1)
{
    this->mwMiddleTier->processCelsiusInput();
}

void MainWindow::on_edtFarenheit_textChanged(const QString &arg1)
{
    this->mwMiddleTier->processFarenheitInput();
}
