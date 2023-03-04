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

    DosePoint dosepoint1(source, 2.0, 2.0, 0.12);
    //dosepoint1.setSource(source);
    //dosepoint1.cartesianToPolar();


    return 0;

}

/*
TODO
initialize numsources and numdosepoints here
send the ints by reference and modify
from other classes

*/
