#ifndef MAINWINDOWMIDDLETIER_H
#define MAINWINDOWMIDDLETIER_H

#include "IMainWindow.h"

class MainWindowMiddleTier
{
public:
    MainWindowMiddleTier(IMainWindow *dlg);
    void processFarenheitInput();
    void processCelsiusInput();


private:
   IMainWindow *dlg;
   bool checkFarenheitValidity(const double &value);
   bool checkCelsiusValidity(const double &value);
};

#endif // MAINWINDOWMIDDLETIER_H
