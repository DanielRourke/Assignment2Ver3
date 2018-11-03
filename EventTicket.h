 /*
 *
 *  Created on: 4 Oct. 2018
 *      Author: Daniel Rourke
 */

#ifndef EVENT_TICKET_H_
#define EVENT_TICKET_H_

#include "Ticket.h"


class EventTicket : public Ticket
{

protected:
    string eventName;
    int eventId;
public:
	EventTicket(int);
	~EventTicket() {}
    int getEventId();
    string getName();
    bool operator ==( const EventTicket& otherEvent );
    void printTicket();
};

EventTicket::EventTicket(int id) : 
Ticket(eventDateMap[id],eventPriceMap[id]), 
eventId(id),
eventName(nameMap[id])
{}

int EventTicket::getEventId()
{
    return eventId;
}

string EventTicket::getName()
{
    return eventName;
}

bool EventTicket::operator ==( const EventTicket& otherEvent )
{
     return this->eventId == otherEvent.eventId;
}

void EventTicket::printTicket() 
{ 	
    cout << "Event Ticket Date: " << date
         << " Name : " << eventName 
         << " Id : "<< eventId 
         << " Price : $" << getTicketPrice() 
         <<  endl ;
}

#endif /* EVENT_TICKET_H_ */