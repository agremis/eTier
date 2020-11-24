#ifndef MAINWINDOWMIDDLETIER_H
#define MAINWINDOWMIDDLETIER_H

#include "IMainWindow.h"

class MainWindowMiddleTier
{
public:
    MainWindowMiddleTier(IMainWindow *dlg);
    void processFahrenheitInput();
    void processCelsiusInput();


private:
   IMainWindow *dlg;
   bool checkFahrenheitValidity(const double &value);
   bool checkCelsiusValidity(const double &value);
};

#endif // MAINWINDOWMIDDLETIER_H
