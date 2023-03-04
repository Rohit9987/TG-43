#include "dosepoint.h"

#include <cmath>
#include <math.h>

#include <iostream>

DosePoint::DosePoint(Source& source, double x, double y, double z)
    :m_source(&source), m_dosePointid(numDosePoints++), m_x(x), m_y(y), m_z(z)
{
#ifdef DEBUG
    std::cout << "*****DosePoint*****" << std::endl;
    std::cout << "DosePoint created: " << m_dosePointid << std::endl;
    std::cout << "*******************" << std::endl;
#endif
    cartesianToPolar();
    
    computeRadialDoseFactors();
}

DosePoint::~DosePoint()
{
    std::cout << "DosePoint destroyed: " << m_dosePointid << std::endl;
}

double DosePoint::computeDose()
{

    return 1.0;
}

void DosePoint::cartesianToPolar()
{
    if(!m_source)
    {
        std::cout << "No source set" << std::endl;
        return;
    }
    double x = m_x - m_source->getX();
    double y = m_y - m_source->getY();
    double z = m_z - m_source->getZ();

    double distance = x*x + y*y + z*z;
    r = std::sqrt(distance);

    theta = std::atan(y/x);

    phi = std::acos(z/r);

#ifdef DEBUG
    std::cout << "(x, y, z) :" << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    std::cout << "r is " << r << " cm" << std::endl;
    std::cout << "theta is " << theta << " radian" << std::endl;
    std::cout << "phi is " << phi << " radian" << std::endl;
#endif
}

void DosePoint::computeRadialDoseFactors()
{
    double beta = std::asin(m_source->getActiveLength() * 
                            std::sin(std::atan(r*std::sin(theta)/
                                                (r*std::cos(theta) - 
                                                    m_source->getActiveLength()/2))));
    double L = m_source->getActiveLength();
    double beta1 =  std::atan((r * cos(phi) - L/2)/
                      r * sin(phi));
    double beta2 =  std::atan((r * cos(phi) + L/2)/
                      r * sin(phi));
    beta = beta1 - beta2;

    if(phi == pi/2 || phi == 3/4*pi)
    {
        std::cout << "90 degree case 1 " << std::endl;

    }
    else
        std::cout << "not 90 degree case 2 " << std::endl;


#ifdef DEBUG
    std::cout << "beta1 : " << beta1 << std::endl;
    std::cout << "beta2 : " << beta2 << std::endl;
    std::cout << "beta : " << beta << std::endl;
#endif

}
