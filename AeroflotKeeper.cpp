#include <algorithm>
#include "AeroflotKeeper.h"

AeroflotKeeper::AeroflotKeeper() {
    std::cout << "Object AeroflotKeeper. Call a simple constructor\n\n";
    this->aeroflotKeeper = new AEROFLOT[10];
    this->arraySize = 10;
    this->tempKeep = 0;
}

AeroflotKeeper::~AeroflotKeeper() {
    std::cout << "Object AeroflotKeeper. Call destructor\n";
    delete [] this->aeroflotKeeper;
}

int comparator(AEROFLOT a, AEROFLOT b){
    return a.getFlightNumber() < b.getFlightNumber();
}

void AeroflotKeeper::dataProcessing(int value) {
    switch (value) {
        case 1: {
            AEROFLOT aeroflot;
            std::cin.ignore(32767, '\n');
            std::cout << "Print next data separated by commas: destination, plane number and plane type\n";

            std::cin >> aeroflot;
            addAeroflot(aeroflot);
            std::sort(aeroflotKeeper, aeroflotKeeper + tempKeep, comparator);
            break;
        }
        case 2: {
            if (!tempKeep) {
                std::cout << "You have no aircraft\n";
                return;
            }
            std::cin.ignore(32676, '\n');
            std::cout << "Your Destination:\n";
            std::string aircrafts;
            for (int i = 0; i < tempKeep; i++) {
                if (aircrafts.find(aeroflotKeeper[i].getDestination()) == std::string::npos) {
                    std::cout << "\t" << aeroflotKeeper[i].getDestination() << "\n";
                    aircrafts.append(aeroflotKeeper[i].getDestination());
                }
            }
            int number = 1;
            std::cout << "Enter an destination:\n";
            std::string aircraft;
            std::getline(std::cin, aircraft);
            for (int i = 0; i < tempKeep; i++) {
                if (aeroflotKeeper[i].getDestination() == aircraft) {
                    std::cout << "This aircraft \"" << aeroflotKeeper[i].getDestination() << "\" serves:\n";
                    std::cout << "\t" << number << ": Flight number " << aeroflotKeeper[i].getFlightNumber()
                              << ", AircraftType " << aeroflotKeeper[i].getAircraftType() << "\n";
                    number++;
                }
            }
            if (number == 1) {
                std::cout << "Flights to \"" << aircraft << "\" not planned\n";
            }
            break;
        }
        default:
            throw std::invalid_argument("Wrong number. Number should be from 1 to 3");
    }
}

void AeroflotKeeper::addAeroflot(AEROFLOT aeroflot) {
    if(this->tempKeep == this->arraySize-1){
        this->aeroflotKeeper[this->tempKeep] = aeroflot;
        AEROFLOT* newArray = new AEROFLOT[this->arraySize+10];
        for(int i=0;i<this->arraySize;i++)
            newArray[i] = this->aeroflotKeeper[i];
        delete[] this->aeroflotKeeper;
        this->aeroflotKeeper = newArray;
        this->arraySize += 10;
        this->tempKeep++;
    }
    else{
        this->aeroflotKeeper[this->tempKeep] = aeroflot;
        this->tempKeep++;
    }
}