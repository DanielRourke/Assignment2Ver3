#pragma once


#include "Ticket.h"


enum direction  { SydneyToTokyo , TokyoToSydney };


class FlightTicket :
	public Ticket
{
protected:
	direction flightDirection;
public:
	FlightTicket();
	FlightTicket(int, direction);
	void printTicket();
	virtual ~FlightTicket();

};



FlightTicket::FlightTicket()
{
}

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

void FlightTicket::printTicket()
{
	cout << "Flight Ticket : " << date;
	if (outBound)
	{
		cout << " Direction : OutBound ";
	}
	else
	{
		cout << " Direction : Inbound ";
	}
	cout << "Price : " << getTicketPrice() << endl;
}


FlightTicket::~FlightTicket()
{
}
