#ifndef MAINWINDOWMIDDLETIER_H
#define MAINWINDOWMIDDLETIER_H

#include "IMainWindow.h"


class MainWindowMiddleTier
{
public:
    MainWindowMiddleTier(IMainWindow *dlg);
    void buildUI();
    void checkValidity();

private:
   IMainWindow *dlg;
};

#endif // MAINWINDOWMIDDLETIER_H
