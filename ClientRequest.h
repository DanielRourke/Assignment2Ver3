/*
 * ClientRequest.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: dongmo
 */
#include "Constants.h"


#ifndef CLIENTREQUEST_H_
#define CLIENTREQUEST_H_

class ClientRequest 
{
public:
	int clientId;
	int hotelType;
	bool events[NUMBEROFEVENTS];
	int budget;
	ClientRequest();
	ClientRequest(string, int);
    int earliestEventDate();
	int latestEventDate();
	int getHotelType();
	void printRequest();
};

ClientRequest::ClientRequest() 
{
	clientId = -1;
	hotelType = -1;
	budget = -1;
	for (int i = 0; i < NUMBEROFEVENTS; i++)
		events[i] = false;
}

ClientRequest::ClientRequest(string s, int id)
{
	clientId = id;
	int next;
	stringstream ss;
	ss.str(s);
	ss >> budget >> hotelType;
	while (ss >> next)
	{
		events[next] = true;
	}
}

int ClientRequest::earliestEventDate() 
{
    int flyout = 9;
    for (int i = 0; i < NUMBEROFEVENTS; i++)
	{
    	if (events[i] && eventDateMap[i] < flyout)
                flyout = eventDateMap[i];
    }

    return flyout;
}

int ClientRequest::latestEventDate() 
{
	int flyin = 0;
	for (int i = 0; i < NUMBEROFEVENTS; i++) 
	{
		if (events[i] && eventDateMap[i] > flyin)
				flyin = eventDateMap[i];
	}
		return flyin;
}

int ClientRequest::getHotelType()
{
	return hotelType;
}

void ClientRequest::printRequest() 
{
	cout << "Client " << clientId << ":" << setw(8) << budget << setw(8) << hotelType;

	for (int i = 0; i < NUMBEROFEVENTS; i++)
	{
		if (events[i])
		cout << setw(8) << i;
	}
		cout << endl;
}

#endif /* CLIENTREQUEST_H_ */
