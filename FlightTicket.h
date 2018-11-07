/*
 * FlightTicket.h
 *
 *  Created on: 03  Oct. 2018
 *      Author: Daniel Rourke
 */


#ifndef FLIGHT_TICKET_H_
#define FLIGHT_TICKET_H_

#include "Ticket.h"

class FlightTicket :public Ticket
{
protected:
	direction flightDirection;
public:
	FlightTicket(int, direction);
	direction getDirection();
	direction setDirection(direction);
	void setFlight(int);
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

direction FlightTicket::setDirection(direction flightDirection)
{
	 this->flightDirection = flightDirection;
}

void FlightTicket::setFlight(int day)
{
	this->date = day;
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
