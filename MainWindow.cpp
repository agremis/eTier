#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mwMiddleTier = new MainWindowMiddleTier(this);

    connect(ui->edtCelsius, &QLineEdit::editingFinished, this, &MainWindow::fineshedEditigCelsius);
    connect(ui->edtFahrenheit, &QLineEdit::editingFinished, this, &MainWindow::fineshedEditigFahrenheit);
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
    QPalette palette;
    if (value)
    {
        palette.setColor(QPalette::Base, Qt::white);
        palette.setColor(QPalette::Text, Qt::black);
    }
    else
    {
        palette.setColor(QPalette::Base, Qt::red);
        palette.setColor(QPalette::Text, Qt::yellow);
    }

    ui->edtFahrenheit->setPalette(palette);
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
    QPalette palette;
    if (value)
    {
        palette.setColor(QPalette::Base, Qt::white);
        palette.setColor(QPalette::Text, Qt::black);
    }
    else
    {
        palette.setColor(QPalette::Base, Qt::red);
        palette.setColor(QPalette::Text, Qt::yellow);
    }

    ui->edtCelsius->setPalette(palette);
}

void MainWindow::fineshedEditigCelsius()
{
    this->mwMiddleTier->processCelsiusInput();
}

void MainWindow::fineshedEditigFahrenheit()
{
    this->mwMiddleTier->processFahrenheitInput();
}

void MainWindow::clearFahrenheitField()
{
    this->ui->edtFahrenheit->clear();
}

void MainWindow::clearCelsiusField()
{
    this->ui->edtCelsius->clear();
}
