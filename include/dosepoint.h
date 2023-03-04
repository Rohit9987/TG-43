#pragma once

#include "debugdefine.h"
#include "source.h"

#include <vector>

class DosePoint
{
public:
    DosePoint(double x, double y, double z);
    ~DosePoint();

    double computeDose();
    void cartesianToPolar();

private:
    const unsigned short m_dosePointid;
    Source *source;

    double x, y, z;
    double r, phi, theta;

    double m_radialDoseFactor;
    double m_normalisedRadialDoseFactor;
    double m_radialDoseConst;
    double m_anisotropyConst;

    double dose;

    std::vector<double> m_doseList;     // list of dose from different sources
    std::vector<Source> m_sourceList;     // list of dose from different sources
};


