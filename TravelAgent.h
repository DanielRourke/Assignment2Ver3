/*
 * TravelAgent.h
 *
 *  Created on: 9 Oct. 2018
 *      Author: Daniel Rourke
 */

//#include "HotelVoucher.h"
//#include "EventTicket.h"
#include "Pacakge.h"
#include "ClientRequest.h"
#include "Constants.h"
#include "RequestGenerator.h"



#ifndef TRAVEL_AGENT_H_
#define TRAVEL_AGENT_H_


class TravelAgent
{
protected:
    vector<ClientRequest*> requestList;
    vector<Package*> packageList;

};

#endif /* TRAVEL_AGENT_H */