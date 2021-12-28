#ifndef LAB2_1_AEROFLOT_H
#define LAB2_1_AEROFLOT_H

#include <iostream>
#include <string>

class AEROFLOT {
public:
    AEROFLOT();
    AEROFLOT(std::string _destination, int _flightNumber, std::string _planeType);
    AEROFLOT(const AEROFLOT& aeroflot);
    ~AEROFLOT();
    std::string getDestination();
    void setDestination(std::string value);
    int getFlightNumber();
    void setFlightNumber(int value);
    std::string getAircraftType();
    void setAircraftType(std::string value);
    friend std::ostream& operator<<(std::ostream& ostream, const AEROFLOT& aeroflot);
    friend std::istream& operator>>(std::istream& istream, AEROFLOT& aeroflot);
private:
    std::string destination;
    int flightNumber;
    std::string planeType;
};


#endif //LAB2_1_AEROFLOT_H