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
    double hotelCommissionRate;
    double eventCommissionRate;
public:
    TravelAgent(double, double);
    virtual ~TravelAgent();
    int proccessRequests(string);
    Package createPackage(ClientRequest*);
    int createPackages();
    double getTotalCommission(Package*);
};

TravelAgent::TravelAgent(double hr = 0.05, double er = 0.1) :
             hotelCommissionRate(hr), eventCommissionRate(er){}

TravelAgent::~TravelAgent() 
{
    for (int i = 0 ; i < requestList.size(); i++)
    {
        delete requestList[i];
    }
    
    for (int i = 0 ; i < packageList.size(); i++)
    {
        delete packageList[i];
    }
}

double TravelAgent::getTotalCommission(Package* package)
{
    return  package->getEventCost() + package->get

}


int TravelAgent::proccessRequests(string r = "requestlist.txt")
{

	if (!requestList.empty())
	{
		requestList.clear();
	}

    char input;
    string details;
    ifstream fin(r);
    
    int counter = 0;

    if (fin.fail())
    {
        cout << "Input file opening failed \n";
        return -1;
    }

    while(!fin.eof())
    {
        fin.get(input);
        
        if (isalnum(input))
        {
            details += input;
            
        }
		else if (input == ']')
		{
			if (!details.empty())
			{
				requestList.push_back(new ClientRequest(details, counter));
				counter++;
			}
            details = "";
        }
        else
        {
            details += ' ';
        }
    }

    cout  << requestList.size() << " Requests Proccesed" << endl;;
    return counter;
}

Package TravelAgent::createPackage(ClientRequest* request)
{

        for (int i = 0 ; i < NUMBEROFEVENTS ; i++)
        {

        }

		Package package(request->earliestEventDate(), request->latestEventDate() + 1);

		
		for (int day = request->earliestEventDate(); day < request->latestEventDate(); day++)
		{
			if (roomAvilable(day, request->hotelType))
			{
				package.addHotel(day, request->hotelType, hotelVacancy(day, star));
			}
		}

		for (int i = 0; i < testclientrequest.getEventTotalSize(); i++)
		{
			EventTicket temp = testclientrequest.getEvent(i);
			int tempId = temp.getId();

			if (eventTicketAvilable(tempId) && tempId != package.getPreviousEventId() && testclientrequest.getBudget() > (package.getTotalCost() + temp.getTicketPrice()))
			{
				package.addEvent(temp);
			}
		}

		

		int validCode = package.isValid(testclientrequest);
		stats[validCode]++;

		finalisedPackages.push_back(package);

		if (validCode == 0)
		{
			profit += finalisedPackages.back().getCommission();
			net += finalisedPackages.back().getTotalCost();
			

			for (int i = 0; i < finalisedPackages.back().getHotelSize(); i++)
			{
				remainingRooms[finalisedPackages.back().getHotelDate(i)][finalisedPackages.back().getHotelType(i) - 3]--;
			}

			for (int i = 0; i < finalisedPackages.back().getEventSize(); i++)
			{
				remainingEvents[finalisedPackages.back().getEventId(i)]--;
			}
		}
}

#endif /* TRAVEL_AGENT_H */