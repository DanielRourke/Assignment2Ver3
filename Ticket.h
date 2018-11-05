/*
 * Ticket.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: dongmo
 */

#include "Constants.h"

#ifndef TICKET_H_
#define TICKET_H_

class Ticket {
protected:
	int date;
	int fullPrice;
	double discount;
public:
	Ticket(int d, int f) :
			date(d), fullPrice(f) {
		discount = 0.0;
	}

	int getDate() {
		return date;
	}

	double getTicketPrice() {
		return (1.0-discount) * fullPrice;
	}

	virtual void printTicket() = 0;

	virtual ~Ticket() {
	}
	
	bool operator<(const Ticket &otherdate) const {
		return this->date < otherdate.date;
    }

	bool operator<(Ticket* otherdate) const {
		return this->date < otherdate.date;
    }

	bool operator<(int otherdate) const  {
		return this->date < otherdate;
	}
	
	bool operator>(const Ticket &otherdate) const {
		  return this->date > otherdate.date;
	}

	bool operator>(Ticket* otherdate) const {
		return this->date > otherdate.date;
    }

	bool operator>(int otherdate) const  {
			return this->date > otherdate;
	}

};

#endif /* TICKET_H_ */
