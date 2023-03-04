#include "dosepoint.h"

#include <cmath>
#include <math.h>

#include <iostream>

DosePoint::DosePoint(double x, double y, double z)
    :m_dosePointid(numDosePoints++), x(x), y(y), z(z)
{

    cartesianToPolar();



#ifdef DEBUG
    std::cout << "*****DosePoint*****" << std::endl;
    std::cout << "DosePoint created: " << m_dosePointid << std::endl;

    std::cout << "r is " << r << " cm" << std::endl;
    std::cout << "theta is " << theta << " radian" << std::endl;
    std::cout << "phi is " << phi << " radian" << std::endl;
    std::cout << "*******************" << std::endl;
#endif
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
    double distance = x*x + y*y + z*z;
    r = std::sqrt(distance);

    theta = std::atan(y/x);

    phi = std::acos(z/r);


#ifdef DEBUG
#endif


}
