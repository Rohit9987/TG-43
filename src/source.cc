#pragma once

#include "source.h"

#include <iostream>

Source::Source(const double activity, const char* sourceType, const double x, const double y, const double z)
    : m_activity(activity), m_sourceType(sourceType), m_numSource(numSources++)
{
#ifdef DEBUG
    std::cout << "*****Source*****" << std::endl;
    std::cout << "Source created: " << m_numSource << std::endl;
    std::cout << "Source type : " << m_sourceType << std::endl;
    std::cout << "Source activity : " << m_activity << " Ci" << std::endl;
    std::cout << "****************" << std::endl;
#endif
}

Source::~Source()
{
    numSources--;

#ifdef DEBUG
    std::cout << "Destroyed source: " << m_numSource << std::endl;
#endif
}
