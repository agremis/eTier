#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "IMainWindow.h"
#include "MainWindowMiddleTier.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, IMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MainWindowMiddleTier *mwMiddleTier;

    // IMainWindow interface
public:
    double getFahrenheitValue();
    void setFahrenheitValue(const double &value);
    void toggleFahrenheitValidState(const bool &value);
    double getCelsiusValue();
    void setCelsiusValue(const double &value);
    void toggleCelsiusValidState(const bool &value);
private slots:
    void on_edtCelsius_textEdited(const QString &arg1);
    void on_edtFahrenheit_textEdited(const QString &arg1);
};
#endif // MAINWINDOW_H
