#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::getFarenheitValue()
{

}

void MainWindow::setFarenheitValue(const double &value)
{

}

void MainWindow::toggleFarenheitValidState(const bool &value)
{

}

double MainWindow::getCelsiusValue()
{

}

void MainWindow::setCelsiusValue(const double &value)
{

}

void MainWindow::toggleCelsiusValidState(const bool &value)
{

}

