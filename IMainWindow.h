#ifndef IMAINWINDOW_H
#define IMAINWINDOW_H

class IMainWindow
{
public:
    virtual double getFarenheitValue() = 0;
    virtual void setFarenheitValue(const double &value) = 0;
    virtual void toggleFarenheitValidState(const bool &value) = 0;

    virtual double getCelsiusValue() = 0;
    virtual void setCelsiusValue(const double &value) = 0;
    virtual void toggleCelsiusValidState(const bool &value) = 0;
};

#endif // IMAINWINDOW_H
