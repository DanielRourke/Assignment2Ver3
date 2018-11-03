/*
 * FlightTicket.h
 *
 *  Created on: 03  Oct. 2018
 *      Author: Daniel Rourke
 */

#include "Ticket.h"

#ifndef FLIGHT_TICKET_H_
#define FLIGHT_TICKET_H_

class FlightTicket :public Ticket
{
protected:
	direction flightDirection;
public:
	FlightTicket(int, direction);
	direction getDirection();
	void printTicket();
	~FlightTicket();

};

FlightTicket::FlightTicket(int d, direction dir) : Ticket(d, 2000), flightDirection(dir)
{
	if (flightDirection == SydneyToTokyo)
	{
		discount = date * 0.05;
	}
	else if (flightDirection == TokyoToSydney)
	{
		discount = (9 - date) * 0.05;
	}
}

direction FlightTicket::getDirection()
{
	return flightDirection;
}

void FlightTicket::printTicket()
{
	cout << "Flight Ticket : " << date;
		
	if (flightDirection == SydneyToTokyo)
	{
		cout << " Direction : Sydney To Tokyo ";
	}
	else if (flightDirection == TokyoToSydney)
	{
		cout << " Direction : Tokyo To Sydney ";
	}


	cout << "Price : " << getTicketPrice() << endl;
}

FlightTicket::~FlightTicket()
{
}

#endif /* FLIGHT_TICKET_H_ */
