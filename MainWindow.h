#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "IMainWindow.h"

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

    // IMainWindow interface
public:
    double getFarenheitValue();
    void setFarenheitValue(const double &value);
    void toggleFarenheitValidState(const bool &value);
    double getCelsiusValue();
    void setCelsiusValue(const double &value);
    void toggleCelsiusValidState(const bool &value);
};
#endif // MAINWINDOW_H
