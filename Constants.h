/*
 * Constants.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: dongmo
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <set>
#include <numeric>

using namespace std;

const string nameMap[] = { "Opening", "Soccer 1", "Soccer 2", "Soccer 3","Track and Field 1", "Track and Field 2", "Track and Field 3","Track and Field 4", "Swimming 1", "Swimming 2", "Gymnastics 1",
		"Gymnastics 2", "Basketball 1", "Basketball 2", "Closing" };
const int eventPriceMap[] = { 2000, 80, 160, 500, 80, 100, 120, 140, 100, 100, 60, 100,
		150, 300, 800 };

const int eventDateMap[] = { 0, 3, 6, 9, 1, 2, 3, 4, 5, 6, 7, 8, 5, 7, 9 };

const int eventQuota[] = {60, 47, 30, 22, 50, 52, 42, 25, 37, 20, 43, 34, 35, 30, 40};

const int hotelPriceMap[] = {1000,1000, 1000, 160, 210, 320};

const int hotelQuota[] ={0, 0, 0, 20, 25, 30};// per day

const int MAXEVENTS = 10;

const int MAXREQUESTS = 150;

const int NUMBEROFEVENTS = 15;

const int NUMBEROFDAYS = 10;

const int NUMBEROFHOTELS = 5;

enum direction { SydneyToTokyo, TokyoToSydney};

enum error { VALID, INVALID_COST, INVALID_FLIGHTS, INVALID_NO_EVENTS, INVALID_EVENT_DATE,
             INVALID_EVENT_NOT_REQUESTED, INVALID_HOTEL_STAYS, INVALID_HOTEL_RATING,
			 INVALID_EVENT_DUPLICATE };

#endif /* CONSTANTS_H_ */
