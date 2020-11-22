#include "Temperature.h"

#include <cmath>

const double Temperature::Epsilon = 5.0e-2;


Temperature::Temperature(double celsius)
    : mCelsius(celsius)
{
}

Temperature::Temperature(double temp, Unit unit)
    : mCelsius(from(temp, unit))
{
}

double Temperature::asCelsius() const
{
    return mCelsius;
}

double Temperature::asFahrenheit() const
{
    return mCelsius * 1.8 + 32.0;
}

double Temperature::asKelvin() const
{
    return mCelsius + 273.15;
}


/* private static */

double Temperature::from(double temp, Unit unit)
{
    switch (unit) {
    case Celsius:
        return temp;

    case Fahrenheit:
        return fromFahrenheit(temp);

    case Kelvin:
        return fromKelvin(temp);
    }
}

double Temperature::fromFahrenheit(double f)
{
    return (f - 32.0) / 1.8;
}

double Temperature::fromKelvin(double k)
{
    return k - 273.15;
}


/* Operator overloading */

Temperature operator +(const Temperature &t1, const Temperature &t2)
{
    return Temperature(t1.mCelsius + t2.mCelsius);
}

Temperature operator -(const Temperature &t1, const Temperature &t2)
{
    return Temperature(t1.mCelsius - t2.mCelsius);
}

Temperature operator *(const Temperature &t1, double d)
{
    return Temperature(t1.mCelsius * d);
}

Temperature operator *(double d, const Temperature &t1)
{
    return Temperature(d * t1.mCelsius);
}

Temperature operator /(const Temperature &t1, double d)
{
    return Temperature(t1.mCelsius / d);
}

Temperature& operator +=(Temperature &t1, const Temperature &t2)
{
    t1.mCelsius += t2.mCelsius;

    return t1;
}

Temperature& operator -=(Temperature &t1, const Temperature &t2)
{
    t1.mCelsius -= t2.mCelsius;

    return t1;
}

Temperature& operator *=(Temperature &t1, double d)
{
    t1.mCelsius *= d;

    return t1;
}

Temperature& operator /=(Temperature &t1, double d)
{
    t1.mCelsius /= d;

    return t1;
}

Temperature operator -(const Temperature &t1)
{
    return Temperature(-t1.mCelsius);
}

bool operator< (const Temperature &t1, const Temperature &t2)
{
    return t1.mCelsius < t2.mCelsius;
}

bool operator> (const Temperature &t1, const Temperature &t2)
{
    return t2 < t1;
}

bool operator<=(const Temperature &t1, const Temperature &t2)
{
    return !(t1 > t2);
}

bool operator>=(const Temperature &t1, const Temperature &t2)
{
    return !(t1 < t2);
}

bool operator==(const Temperature &t1, const Temperature &t2)
{
    return std::abs(t1.mCelsius - t2.mCelsius) < Temperature::Epsilon;
}

bool operator!=(const Temperature &t1, const Temperature &t2)
{
    return !(t1 == t2);
}


/* User-defined literals */

Temperature operator "" _C(long double c)
{
    return Temperature(c);
}

Temperature operator "" _F(long double f)
{
    return Temperature(f, Temperature::Fahrenheit);
}

Temperature operator "" _K(long double k)
{
    return Temperature(k, Temperature::Kelvin);
}

Temperature operator "" _C(unsigned long long c)
{
    return Temperature(double(c));
}

Temperature operator "" _F(unsigned long long f)
{
    return Temperature(double(f), Temperature::Fahrenheit);
}

Temperature operator "" _K(unsigned long long k)
{
    return Temperature(double(k), Temperature::Kelvin);
}
