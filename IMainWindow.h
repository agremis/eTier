#ifndef IMAINWINDOW_H
#define IMAINWINDOW_H

class IMainWindow
{
public:
    virtual double getFahrenheitValue() = 0;
    virtual void setFahrenheitValue(const double &value) = 0;
    virtual void toggleFahrenheitValidState(const bool &value) = 0;

    virtual double getCelsiusValue() = 0;
    virtual void setCelsiusValue(const double &value) = 0;
    virtual void toggleCelsiusValidState(const bool &value) = 0;
};

#endif // IMAINWINDOW_H
