/*
	Cookie Army

	Nguyen, Benjamin
	Ramirez, Louis
	Do, Henry

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "MemberList.h"
#include "HikeList.h"
#include "Reservations.h"
#include "Interface.h"
#include "HikeReader.h"
#include "ReservationReader.h"
#include "MemberReader.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	MemberList memberList;
	HikeList hikeList;
	Reservations reservations;

	getMemberData(memberList);
	getHikeData(hikeList);
	getReservationData(reservations);
	
	displayMenu();
	processReservation(hikeList, memberList, reservations);

	return 0;
}
