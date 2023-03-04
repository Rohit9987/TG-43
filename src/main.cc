#include <iostream>

#include "source.h"
#include "dosepoint.h"
#include "debugdefine.h"


void header()
{
    std::cout << "*********************************************************************************" << std::endl;
    std::cout << "--------------------------------------TG43---------------------------------------" << std::endl;
    std::cout << "*********************************************************************************" << std::endl << std::endl;

};

int main()
{
    header();

    numSources = 0;

    DosePoint dosepoint1(1.0, 0, 0);
    dosepoint1.cartesianToPolar();

    const char* sourceType = "ir-192";

    Source source(10.0, sourceType, 0, 0, 0);


    return 0;

}
