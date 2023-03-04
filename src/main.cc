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

    const char* sourceType = "i-125";
    Source source(10.0, sourceType, 0, 0, 0);

    DosePoint dosepoint1(0.0, 10., 0);
    dosepoint1.setSource(source);
    dosepoint1.cartesianToPolar();


    return 0;

}
