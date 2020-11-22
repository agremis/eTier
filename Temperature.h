#pragma once

class Temperature
{
    friend Temperature operator +(const Temperature &t1, const Temperature &t2);
    friend Temperature operator -(const Temperature &t1, const Temperature &t2);

    friend Temperature operator *(const Temperature &t1, double d);
    friend Temperature operator *(double d, const Temperature &t1);

    friend Temperature operator /(const Temperature &t1, double d);

    friend Temperature& operator +=(Temperature &t1, const Temperature &t2);
    friend Temperature& operator -=(Temperature &t1, const Temperature &t2);
    friend Temperature& operator *=(Temperature &t1, double d);
    friend Temperature& operator /=(Temperature &t1, double d);

    friend Temperature operator -(const Temperature &t1);

    friend bool operator < (const Temperature &t1, const Temperature &t2);
    friend bool operator > (const Temperature &t1, const Temperature &t2);
    friend bool operator <=(const Temperature &t1, const Temperature &t2);
    friend bool operator >=(const Temperature &t1, const Temperature &t2);

    friend bool operator ==(const Temperature &t1, const Temperature &t2);
    friend bool operator !=(const Temperature &t1, const Temperature &t2);

public:
    enum Unit
    {
        Celsius,
        Fahrenheit,
        Kelvin
    };

    Temperature(double celsius = 0.0);
    Temperature(double temp, Unit unit);

    double asCelsius() const;
    double asFahrenheit() const;
    double asKelvin() const;

private:
    double mCelsius;


    static const double Epsilon;

    static double from(double temp, Unit unit);
    static double fromFahrenheit(double f);
    static double fromKelvin(double k);
};



Temperature operator "" _C(long double c);
Temperature operator "" _F(long double f);
Temperature operator "" _K(long double k);

Temperature operator "" _C(unsigned long long c);
Temperature operator "" _F(unsigned long long f);
Temperature operator "" _K(unsigned long long k);
