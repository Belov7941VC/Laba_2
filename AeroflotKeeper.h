#ifndef LAB2_1_AEROFLOTKEEPER_H
#define LAB2_1_AEROFLOTKEEPER_H

#include "AEROFLOT.h"

class AeroflotKeeper {
public:
    AeroflotKeeper();
    ~AeroflotKeeper();
    void addAeroflot(AEROFLOT aeroflot);
    void dataProcessing(int value);
private:
    AEROFLOT* aeroflotKeeper;
    int tempKeep;
    int arraySize;
};


#endif //LAB2_1_AEROFLOTKEEPER_H