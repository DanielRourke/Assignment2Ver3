/*
 * test.h
 *
 *  Created on: 18  Oct. 2018
 *      Author: Daniel Rourke
 */

#include "ClientRequest.h"
#include "FlightTicket.h"
#include "HotelVoucher.h"
#include "EventTicket.h"

#ifndef TEST_TRAVEL_AGENT_H_
#define TEST_TRAVEL_AGENT_H_


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

}
#endif /* TEST_H_  */


