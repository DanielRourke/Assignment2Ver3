/*
 * test.h
 *
 *  Created on: 18  Oct. 2018
 *      Author: Daniel Rourke
 */

#ifndef TEST_TRAVEL_AGENT_H_
#define TEST_TRAVEL_AGENT_H_


#include "ClientRequest.h"
#include "FlightTicket.h"
#include "HotelVoucher.h"
#include "EventTicket.h"
#include "RequestGenerator.h"
#include "Package.h"
struct Test
{
    void test(); 
};

void Test::test()
{
    ClientRequest client1("12020 4 2 0 5 14 10 4 3 13 1" ,1);
    client1.printRequest();

    FlightTicket Flyout(5, SydneyToTokyo);
    Flyout.printTicket();

    EventTicket event1(14);
    event1.printTicket();

    HotelVoucher room1(4, 5 , 0.2);
    HotelVoucher room2(4, 5 , 0.5);
    HotelVoucher room3(4, 5 , 1.0);

    room1.printTicket(); 
    room2.printTicket();
    room3.printTicket();

    RequestGenerator bob;

    Package p1(7, 9);
	p1.addHotel(7, 5, 1);
	p1.addHotel(8, 5, 1);
	p1.addEvent(14);
	ClientRequest client2("12020 5 14", 2);
	error code = p1.isValid(&client2);
	p1.printPackage(code, -3);
}
#endif /* TEST_H_  */


