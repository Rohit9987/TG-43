#pragma once

#include "source.h"

#include <iostream>
#include <cstring>

Source::Source(const double activity, const char* sourceType, const double x, const double y, const double z)
    : m_activity(activity), m_sourceType(sourceType), m_numSource(numSources++), m_x(x), m_y(y), m_z(z)
{
#ifdef DEBUG
    std::cout << "*****Source*****" << std::endl;
    std::cout << "Source created: " << m_numSource << std::endl;
    std::cout << "Source type : " << m_sourceType << std::endl;
    std::cout << "Source activity : " << m_activity << " Ci" << std::endl;
    std::cout << "****************" << std::endl;
#endif

    setSourceProperties();

}

void Source::setSourceProperties()
{
    std::cout << m_sourceType << std::endl;
    if(strcmp(m_sourceType,"i-125") == 0)
    {
        m_doseRateConstant = 0.925;   // WAFAC, % unc = 0.20%
        //m_dose_rate_constant = 0.959;   // point, % unc = 0.30%

        m_activeLength = 0.300;
    }

#ifdef DEBUG
    std::cout << "Dose Rate Constant: " << m_doseRateConstant << " cGy/Uh." << std::endl;
    std::cout << "Active Length: " << m_activeLength << " cm." << std::endl;
#endif
}

Source::~Source()
{
    numSources--;

#ifdef DEBUG
    std::cout << "Destroyed source: " << m_numSource << std::endl;
#endif
}
