

/*
 * HotelVoucher.h
 *
 *  Created on: 03  Oct. 2018
 *      Author: Daniel Rourke
 */


#ifndef HOTEL_VOUCHER_H_
#define HOTEL_VOUCHER_H_

#include "Ticket.h"

class HotelVoucher : public Ticket
{

protected:
	int stars;
public:
	HotelVoucher(int date, int star, double vacancy);
	int getHotelType() const;
	void printTicket();
	~HotelVoucher() {}
};

HotelVoucher::HotelVoucher(int date, int star, double vacancy) : stars(star), Ticket(date, hotelPriceMap[star])
{

	if (stars == 4 && vacancy > 0.5)
	{
		discount = 0.2;
	}
	else if (stars == 5)
	{
		if (vacancy > 0.5)
		{
			discount = 0.4;
		}
		else if (vacancy > 0.2)
		{
			discount = 0.2;
		}
	}
}

void HotelVoucher::printTicket()
{
	cout << "Hotel Voucher Date :" << date << " Min Stars : " << stars << " Price :$" << getTicketPrice() <<  endl ;
}

int HotelVoucher::getHotelType() const
{
	return stars;
}


#endif /* HOTEL_VOUCHER_H_ */