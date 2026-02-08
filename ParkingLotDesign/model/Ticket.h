#pragma once
#include <ctime>

class Ticket
{
private:
    int ticketNumber;
    time_t entryTime;
    int spotId;
    int vehicleReg;

public:
    Ticket(int n, int vReg, int sId)
        : ticketNumber(n), vehicleReg(vReg), spotId(sId)
    {
        entryTime = time(NULL);
    }

    int getTicketNumber() { return ticketNumber; }
    int getVehicleReg() { return vehicleReg; }
    int getSpotId() { return spotId; }
    time_t getEntryTime() { return entryTime; }
};
