#include "MainWindowMiddleTier.h"
#include "Temperature.h"

MainWindowMiddleTier::MainWindowMiddleTier(IMainWindow *dlg):dlg(dlg)
{

}

void MainWindowMiddleTier::processFarenheitInput()
{
    const double value = this->dlg->getFarenheitValue();
    if (this->checkFarenheitValidity(value))
    {
        Temperature temp(value, Temperature::Fahrenheit);
        this->dlg->setCelsiusValue(temp.asCelsius());
    }
    else
    {
        this->dlg->toggleFarenheitValidState(false);
    }
}

void MainWindowMiddleTier::processCelsiusInput()
{
    const double value = this->dlg->getCelsiusValue();
    if (this->checkCelsiusValidity(value))
    {
        Temperature temp(value, Temperature::Celsius);
        this->dlg->setFarenheitValue(temp.asFahrenheit());
    }
    else
    {
        this->dlg->toggleCelsiusValidState(false);
    }
}

bool MainWindowMiddleTier::checkFarenheitValidity(const double &value)
{
    return true;
}

bool MainWindowMiddleTier::checkCelsiusValidity(const double &value)
{
    return true;
}

