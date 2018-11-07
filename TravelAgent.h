/*
 * TravelAgent.h
 *
 *  Created on: 9 Oct. 2018
 *      Author: Daniel Rourke
 */

//#include "HotelVoucher.h"
//#include "EventTicket.h"
#include "Package.h"
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
    int remainingEvents[NUMBEROFEVENTS];
    int remainingRooms[NUMBEROFDAYS][NUMBEROFHOTELS];
public:
    TravelAgent(double, double);
    virtual ~TravelAgent();
    double getTotalCommission(Package*);
    bool roomAvailable(int, int);
    double hotelVacancy(int, int);
    int proccessRequests(string);
    Package createPackage(ClientRequest*);
    int createPackages();

};

TravelAgent::TravelAgent(double hr = 0.05, double er = 0.1) :
             hotelCommissionRate(hr), eventCommissionRate(er)
{
    for (int i = 0; i < NUMBEROFDAYS; i++)
    {
        for (int j = 0; j < NUMBEROFHOTELS; j++)
        {
            remainingRooms[i][j] = hotelQuota[j];
        }
    }

    for (int i = 0; i < NUMBEROFEVENTS ; i++)
    {
            remainingEvents[i] = eventQuota[i];
    }
}

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
    return  package->getEventsCost() * eventCommissionRate +
            package->getHotelsCost() * hotelCommissionRate +
            package->getFlightsCost() * hotelCommissionRate;
}

bool TravelAgent::roomAvailable(int day, int star)
{
    return remainingRooms[day][star] > 0;
}

double TravelAgent::hotelVacancy(int day, int star)
{
    return 100 / hotelQuota[star] * remainingRooms[day][star];
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
        //sort events by quota

        //pick first valid high quota package and 1 day


        //sort event by dates and quota so the stay in order possibly
        // delete old package
        // purchase highest commision package of 1 then 2 the 3
        //     for (evemt requested ; package events < i && event day < event[total - i] date)


        //sort packages by hotel star rating
        //increase hotel star rating for each day
        //make inverve quota 
        //vancancy can be 100 / quota   -  inver quota
        //avliabe is quota



        //5 start upgrade when they can
        //4 star upgrade where they can
        //3 star buy what they can
        //4 star buy what they can
        //5 star 0.5
        //5 star 0.2

        //loop over the 3 stars
        //loop over the 4 stars
        //loop ove the 4 stars inverse tickets
        //loop over the 

        //add days at max rating
        // Package package;
        // for (int id = 0 , highestQuota = 0; id < NUMBEROFEVENTS ; id++)
        // {
        //     if (request->events[id] && EventTicket.isAvailable(id))
        //     {
        //         Package tempPackage(eventDateMap[id], eventDateMap[id] + 1);
        //         tempPackage.addHotel(request->hotelType);
        //         tempPackage.addEvent(id);

        //         if(highestQuota < EventTicket.getQuota() || highestQuota == EventTicket.getQuota() && package.getCommission() < tempPackage.getCommission() )
        //         {
        //             package = tempPackage;
        //             highestQuota = EventTicket.getQuota(id);
        //         }
        //     }
        // }

		// Package package(request->earliestEventDate(), request->latestEventDate() + 1);

		
		// for (int day = request->earliestEventDate(); day < request->latestEventDate(); day++)
		// {
		// 	if (roomAvailable(day, request->hotelType))
		// 	{
		// 		package.addHotel(day, request->hotelType, hotelVacancy(day, star));
		// 	}
		// }

		// for (int i = 0; i < testclientrequest.getEventTotalSize(); i++)
		// {
		// 	EventTicket temp = testclientrequest.getEvent(i);
		// 	int tempId = temp.getId();

		// 	if (eventTicketAvilable(tempId) && tempId != package.getPreviousEventId() && testclientrequest.getBudget() > (package.getTotalCost() + temp.getTicketPrice()))
		// 	{
		// 		package.addEvent(temp);
		// 	}
		// }

		

		// int validCode = package.isValid(testclientrequest);
		// stats[validCode]++;

		// finalisedPackages.push_back(package);

		// if (validCode == 0)
		// {
		// 	profit += finalisedPackages.back().getCommission();
		// 	net += finalisedPackages.back().getTotalCost();
			

		// 	for (int i = 0; i < finalisedPackages.back().getHotelSize(); i++)
		// 	{
		// 		remainingRooms[finalisedPackages.back().getHotelDate(i)][finalisedPackages.back().getHotelType(i) - 3]--;
		// 	}

		// 	for (int i = 0; i < finalisedPackages.back().getEventSize(); i++)
		// 	{
		// 		remainingEvents[finalisedPackages.back().getEventId(i)]--;
		// 	}
		// }



        //int out = testclientrequest.firstEventDate();
	//int in = testclientrequest.lastEventDate();



	vector <Package> possiblePackages;
	for (int flyOutDay = 0 ; flyOutDay < NUMBEROFDAYS; flyOutDay++)
	{
		Package package(flyOutDay, flyOutDay);

		for (int day = flyOutDay ; day < NUMBEROFDAYS; day++)
		{
			for (int star = request->hotelType; star <= NUMBEROFHOTELS ; star++)
			{
				if (roomAvailable(day, star))
				{
					package.addHotel(day, star, hotelVacancy(day, star));
                    package.changeFlight(day+1, TokyoToSydney);
					break;
				}
			}

			for (int i = 0; i < NUMBEROFEVENTS; i++)
			{
				if (request->events[i] 
                    && eventDateMap[i] == day
                    && remainingEvents[i] > 0 
                    && package.getTotalCost() + eventPriceMap[i] < request->budget)
                {
                    cout << "NAME"<< nameMap[i]<< endl;
                    package.addEvent(i);
                }
			}

            if(package.isValid(request) == VALID)
            {
                possiblePackages.push_back(package);
            }
			
		}
    }

    Package* bestPackage;
    for (int id = 0 ; id < NUMBEROFEVENTS ; id++)
    {
       if (request->events[id] && remainingEvents[id] > 0)
        {   
            Package tempPackage(eventDateMap[id], eventDateMap[id+ 1] );
            tempPackage.addHotel(eventDateMap[id], request->hotelType, hotelVacancy(eventDateMap[id],request->hotelType));
            tempPackage.addEvent(id);
            if (tempPackage.isValid(request) == VALID)
            { 
                bestPackage = &tempPackage;
                break;
            }
        }
    }

	for (Package package : possiblePackages)
	{
		if (package.isValid(request) == VALID && getTotalCommission(&package) > getTotalCommission(bestPackage))
		{
            delete bestPackage;  
			bestPackage = &package;
        }
	}

    packageList.push_back(bestPackage);
    bestPackage->printPackage(bestPackage->isValid(request), -2);
	return *bestPackage;

}

int TravelAgent::createPackages()
{
    for(int i =0 ;i < requestList.size() ; i++)
    {

       createPackage(requestList[i]);

    }
}

#endif /* TRAVEL_AGENT_H */