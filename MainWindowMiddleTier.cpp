#include "MainWindowMiddleTier.h"
#include "Temperature.h"

MainWindowMiddleTier::MainWindowMiddleTier(IMainWindow *dlg):dlg(dlg)
{

}

void MainWindowMiddleTier::processFahrenheitInput()
{
    const double value = this->dlg->getFahrenheitValue();
    if (this->checkFahrenheitValidity(value))
    {
        Temperature temp(value, Temperature::Fahrenheit);
        this->dlg->setCelsiusValue(temp.asCelsius());
    }
    else
    {
        this->dlg->toggleFahrenheitValidState(false);
    }
}

void MainWindowMiddleTier::processCelsiusInput()
{
    const double value = this->dlg->getCelsiusValue();
    if (this->checkCelsiusValidity(value))
    {
        Temperature temp(value, Temperature::Celsius);
        this->dlg->setFahrenheitValue(temp.asFahrenheit());
    }
    else
    {
        this->dlg->toggleCelsiusValidState(false);
    }
}

bool MainWindowMiddleTier::checkFahrenheitValidity(const double &value)
{
    return true;
}

bool MainWindowMiddleTier::checkCelsiusValidity(const double &value)
{
    return true;
}

