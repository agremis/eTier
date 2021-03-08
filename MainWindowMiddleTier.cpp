#include "MainWindowMiddleTier.h"
#include "Temperature.h"

MainWindowMiddleTier::MainWindowMiddleTier(IMainWindow *dlg):dlg(dlg)
{

}

void MainWindowMiddleTier::processFahrenheitInput()
{
    const double value = this->dlg->getFahrenheitValue();
    const bool validity = this->checkFahrenheitValidity(value);
    this->dlg->toggleFahrenheitValidState(validity);
    if (validity)
    {
        Temperature temp(value, Temperature::Fahrenheit);
        this->dlg->setCelsiusValue(temp.asCelsius());
    }
    else
        this->dlg->clearCelsiusField();
}

void MainWindowMiddleTier::processCelsiusInput()
{
    const double value = this->dlg->getCelsiusValue();
    const bool validity = this->checkCelsiusValidity(value);

    this->dlg->toggleCelsiusValidState(validity);

    if (validity)
    {
        Temperature temp(value, Temperature::Celsius);
        this->dlg->setFahrenheitValue(temp.asFahrenheit());
    }
    else
        this->dlg->clearFahrenheitField();
}

bool MainWindowMiddleTier::checkFahrenheitValidity(const double &value)
{
    return value >= -459.67;
}

bool MainWindowMiddleTier::checkCelsiusValidity(const double &value)
{
    return value >= -273.15;
}

