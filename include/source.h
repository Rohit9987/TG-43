#pragma once

#include "debugdefine.h"

class Source
{
public:
    Source(const double activity, const char* sourceType, const double x, const double y, const double z);
    ~Source();

    double getX() { return m_x;}
    double getY() { return m_y;}
    double getZ() { return m_z;}

    double getActiveLength() const {return m_activeLength;}

private:
    const unsigned short m_numSource;
    const char* m_sourceType;

    double m_x, m_y, m_z;
    double m_activeLength;
    double m_activity;
    double time;
    double m_AKS;           // Air kerma strength
    double m_doseRateConstant;
    void setSourceProperties();

    // change everything to const

};
    /*
    notes

    D (r,theta) = Sk *
                  dose_rate_const *
                  g(r,theta)/g(r,theta0) *
                  g(r) *
                  F(r, theta)


    Sk - Air kerma strength
    unit - cGycm2/h(U) 
    nist wide angle FAIC
    
    dose rate constant - dose rate at 1 cm
    unit cGy/hU

    geometry factor (inverse square law)
    1/cm2
    point source - 1/r2

    radial dose function
    unitless

    anisotropy function

    gl(r, theta) = b/(Lrsin(theta))
                 = 1/(r2 - L2/4) if theta = 0

                 b is the angle subtended by the tips of the line with respect
                 to the calculation point

*/


