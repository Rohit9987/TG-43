#pragma once

#include "debugdefine.h"

class Source
{
public:
    Source(const double activity, const char* sourceType, const double x, const double y, const double z);
    ~Source();

private:
    const unsigned short m_numSource;
    const char* m_sourceType;

    double x, y, z;
    double m_activeLength;
    double m_activity;
    double time;
    double m_AKS;           // Air kerma strength

    // change everything to const

};
