/*
 * ClientRequest.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: dongmo
 */

#ifndef CLIENTREQUEST_H_
#define CLIENTREQUEST_H_

class ClientRequest {
public:
	int cId;
	int hotelType;
	bool events[NUMBEROFEVENTS];
	int budget;
	ClientRequest() {
		cId = -1;
		hotelType = -1;
		budget = -1;
		for (int i = 0; i < NUMBEROFEVENTS; i++)
			events[i] = false;
	}

	int earliestEventDate() {
        int flyin = 9;
        for (int i = 0; i < NUMBEROFEVENTS; i++) {
            if (events[i] && eventDateMap[i] < flyin)
                flyin = eventDateMap[i];
        }
        return flyin;
    }

	int latestEventDate() {
// ADD YOUR CODE HERE!
    }

	void print() {
		cout << "Client " << cId << ":" << setw(8) << budget << setw(8) << hotelType;

		for (int i = 0; i < NUMBEROFEVENTS; i++) {
			if (events[i])
				cout << setw(8) << i;
		}
		cout << endl;
	}
};

#endif /* CLIENTREQUEST_H_ */
