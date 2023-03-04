#pragma once

#include "debugdefine.h"
#include "source.h"

#include <vector>


class DosePoint
{
public:
    DosePoint(Source& source, double x, double y, double z);
    ~DosePoint();

    double computeDose();
    
    //void setSource(Source& source) { m_source = &source;}

private:
    const unsigned short m_dosePointid;
    Source* m_source;

    double m_x, m_y, m_z;
    double r, phi, theta;
    void cartesianToPolar();

    double m_radialDoseFactor;
    double m_normalisedRadialDoseFactor;
    const double pi = 3.14159265358979323846;
    void computeRadialDoseFactors();

    double m_radialDoseConst;
    double m_anisotropyConst;

    double dose;

    // for later implementation of multiple sources
    // ignore for now
    std::vector<double> m_doseList;     // list of dose from different sources
    std::vector<Source> m_sourceList;     // list of dose from different sources
};

/*

    gl(r, theta) = b/(Lrsin(theta))
                 = 1/(r2 - L2/4) if theta = 0

                 b is the angle subtended by the tips of the line with respect
                 to the calculation point

*/
