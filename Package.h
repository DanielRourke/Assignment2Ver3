/*
 * Package.h
 *
 *  Created on: 4 Oct. 2018
 *      Author: Daniel Rourke
 */


#ifndef PACKAGE_H_
#define PACKAGE_H_

#include "ClientRequest.h"
#include "FlightTicket.h"
#include "HotelVoucher.h"
#include "EventTicket.h"

class Package
{
protected:
    FlightTicket* outBound;
    FlightTicket* inBound;
    vector <EventTicket> eventList;
    vector <HotelVoucher> hotelList;
    double currentCost;
public:
    Package();
    Package(int , int);
    ~Package();
    void addEvent(int);
    void addHotel(int, int, double);
    error isValid(ClientRequest*);
    void printPackage(error, int);
    void printError(error);
    void printPackageDetails();
};

Package::Package() : currentCost(0.0)
{

}

Package::Package(int out, int in) : currentCost(0.0)
{
    outBound = new FlightTicket(out, SydneyToTokyo);
    inBound = new FlightTicket(in, TokyoToSydney);
    currentCost = outBound->getTicketPrice() + inBound->getTicketPrice();
}

Package::~Package()
{
    delete outBound;
    delete inBound;
    // for (int i = 0 ; i < eventList.size(); i++)
    // {
    //     delete eventList[i];
    // }
    // for (int i = 0 ; i < hotelList.size(); i++)
    // {
    //     delete hotelList[i];
    // }
}

void Package::addEvent(int eventID)
{
    eventList.push_back(EventTicket(eventID)); 
    currentCost += eventPriceMap[eventID];
}

void Package::addHotel(int date, int star, double vacancy)
{
    hotelList.push_back(HotelVoucher(date, star, vacancy)); 
    currentCost += hotelPriceMap[star];
}

error Package::isValid(ClientRequest* request)
{
    sort(hotelList.begin(), hotelList.end());
    sort(eventList.begin(), eventList.end());


    // o The total costs should not exceed client’s budget. 
    if (currentCost > request->budget)
    {
        return INVALID_COST;
    }

    // o The date of fly-in ticket is earlier than the date of fly-out ticket.
    if (inBound < outBound || *outBound < 0 || *inBound > 9)
    {
        return INVALID_FLIGHTS;
    }

    // They can be less but each package must contain at least one event.
    if (eventList.size() < 1)
    {
        return INVALID_NO_EVENTS;
    }

    // o All the event tickets should be in the dates between fly-in and fly-out (can be in the
    // same day of arrival or departure).
    // o Only the events a client requests can be included in the travel package to the client.
    vector<EventTicket>::iterator event;
    for (event = eventList.begin() ; event != eventList.end(); event++)
    {
        if( *event < outBound || *event > inBound )
        {   
            return INVALID_EVENT_DATE;
        }

        if (!request->events[event->getEventId() ] )
        {
            return INVALID_EVENT_NOT_REQUESTED;
        }
    }

    //One event one ticket
    for (event = eventList.begin() + 1 ; event != eventList.end(); event++ )
    {
        if (event->getEventId() == (event - 1)->getEventId())
        {
            return INVALID_EVENT_DUPLICATE;
        }
    }

    // o The hotel rooms cover every night between the arrival and departure dates (not
    // include the fly-out day).
    if( hotelList.size() == 0  )
    {   
        return INVALID_HOTEL_STAYS;
    }
    else if((inBound->getDate() - outBound->getDate() ) !=  hotelList.size() )
    {
        return INVALID_HOTEL_STAYS;
    }
    else if(hotelList.front() < outBound )
    {
        return INVALID_HOTEL_STAYS;
    }
    else if(hotelList.back() > inBound )
    {
        return INVALID_HOTEL_STAYS;
    }

    // o The hotel types should be the same or above the client’s desired hotel type.
   // vector<HotelVoucher>:: iterator hotel;
    for (HotelVoucher hotel : hotelList )
    {
        if( !(hotel.getHotelType() >= request->hotelType ))
        {
            return INVALID_HOTEL_RATING;
        }
    }

    return VALID;
}

void Package::printError(error code)
{
     if (code == 0)
    {
        cout << "Package is Valid" << endl;
    }
    else if (code > 0)
    {
        cout << "Package is Invalid ";
    }
    else
    {
        cout << "Error Code Not Supported" << endl;
    }

    switch (code)
    {
    case 1:
        cout << "The total costs should not exceed client's budget. " << endl;
        break;
    case 2:
        cout << "The date of fly-in ticket is earlier than the date of fly-out ticket." << endl;
        break;
    case 3:
        cout << "They can be less but each package must contain at least one event." << endl;
        break;
    case 4:
        cout << "All the event tickets should be in the dates between fly-in and fly-out "<< endl
        << " (can be in the same day of arrival or departure)" << endl;
        break;
    case 5:
        cout << "Only the events a client requests can be included in the travel package to the client."
        << endl << "One event one ticket." <<  endl;
        break;
    case 6:
        cout << "The hotel rooms cover every night between the arrival and departure dates" << endl 
        << "(not include the fly-out day)." << endl;
        break;
    case 7:
        cout << "The hotel types should be the same or above the client’s desired hotel type" << endl;
        break;
    case 8:
        cout << "One Ticket One event " << endl;
    }
}


void Package::printPackage(error code, int option)
{
 
        if (code == option || option == -1)
        {
            printPackageDetails();
        }
        else if ( option == -2)
        {
            printError(code);
        }
        else if (option == -3)
        {
            printPackageDetails();
            printError(code);
        }
}

void Package::printPackageDetails()
{

    outBound->printTicket();
    inBound->printTicket();
    for (int i = 0; i < eventList.size(); i++)
    {
        eventList[i].printTicket();
    }

    for (int i = 0 ; i < hotelList.size(); i++)
    {
        hotelList[i].printTicket();
    }
    cout << "Total Cost : " <<  currentCost << endl;
}

#endif /* PACKAGE_H_ */