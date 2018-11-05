
/*
 * RequestGenorator.h
 *
 *  Created on: 20 Oct 2018
 *      Author: Daniel Rourke
Students who seek distinction or above are required to create a class called
requestGenerator that simulates client requests.The class should implement a member
function which is able to generate randomly 100 - 150 client requests.
Each request consists of :
o A randomly generated hotel category between 3 star to 5 star.
o Randomly generated 1 - 10 different events(at most one for each event).
o Randomly generated budget :
§ If the events include opening ceremony, randomly generate the budget
between 4500 + 150 * number - of - events to 7500 + 150 * number - of - events.
§ If the events include closing ceremony, randomly generate the budget
between 3800 + 150 * number - of - events to 6800 + 150 * number - of - events.
§ Otherwise, randomly generate the budget between 3250 + 150 * number - ofevents
to 5250 + 150 * number - of - events.
The format of each request should be :
budget, hotelType, [event1, event2, …, eventn]

 */
#ifndef REQUEST_GENERATOR_H_
#define REQUEST_GENERATOR_H_

#include "Constants.h"

class RequestGenerator
{
public:
	RequestGenerator();
	~RequestGenerator();
	void generateRequest(int, int);
	
};

void RequestGenerator::generateRequest(int min = 100, int max = 150)
{

	//output the date to a file
	ofstream fout;

	fout.open("RandomRequestList.txt");
	if (fout.fail()) {
		cout << "Output file opening failed.\n";
		exit(1);
	}


	set <int> eventList;
	int requestCount = (rand() % (max - min)) + min;
	int budget = 0;
	
	for (int i = 0; i < requestCount; i++)
	{
		int eventCount = rand() % 10 + 1;

		for (int j = 0; j < eventCount; j++)
		{
			int eventID =  rand() % 15;
			eventList.insert(eventID);
		}

		if (*eventList.begin() == 0)
		{
			budget = (rand() % 3000) + (4500 + (150 * eventCount));
		}
		else if (*eventList.end() == 14)
		{
			budget = (rand() % 3000) + (3800 + (150 * eventCount));
		}
		else
		{
			budget = (rand() % 2000) + (3250 + (150 * eventCount));
		}

		int star = rand() % 3 + 3;
	
		//budget,hotelType[event1,event2, …, eventn]

		fout << budget << "," << star << "[";
       
        set<int>::iterator it;
		for (it = eventList.begin(); it != eventList.end(); it++)
       // for (int e : eventList)
		{
			fout << *it ;
			if (it != --eventList.end() )
			{
				fout << ",";
			}
		}
		fout << "]\n";

		eventList.clear();
	}
}


RequestGenerator::RequestGenerator()
{
	generateRequest();
}


RequestGenerator::~RequestGenerator()
{
}



#endif /*REQUEST_GENERATOR*/
