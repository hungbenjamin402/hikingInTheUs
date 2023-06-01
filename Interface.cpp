/*
	Cookie Army

	Nguyen, Benjamin
	Ramirez, Louis
	Do, Henry

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Member.h"
#include "MemberList.h"
#include "Hike.h"
#include "HikeList.h"
#include "Reservations.h"
#include "Interface.h"

#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu()
{
	cout << string(51, '*') << endl
		<< "		HIKING IN THE US		" << endl
		<< string(51, '*') << endl << endl
		<< "	1. Browse by location" << endl
		<< "	2. Browse by duration" << endl
		<< "	3. Browse by difficulty" << endl
		<< "	4. Browse by price" << endl
		<< "	5. Make a reservation" << endl
		<< "	6. View reservation" << endl
		<< "	7. Cancel reservation" << endl
		<< "	8. Exit" << endl;
}

void processReservation(HikeList& hikeList, 
	MemberList& memberList, Reservations& reservation)
{
	bool programRun = true;
	int selectionNumber = 0;

	while (programRun)
	{
		cout << endl << "Please make a selection: ";
		cin >> selectionNumber;
		cout << endl;
		
		if (selectionNumber != 8)
		{
			if (selectionNumber == 1)
			{
				chooseByLocation(hikeList, memberList, reservation);
			}
			else if (selectionNumber == 2)
			{
				chooseByDuration(hikeList, memberList, reservation);
			}
			else if (selectionNumber == 3)
			{
				chooseByDifficulty(hikeList, memberList, reservation);
			}
			else if (selectionNumber == 4)
			{
				chooseByPrice(hikeList, memberList, reservation);
			}
			else if (selectionNumber == 5)
			{
				makeReservation(hikeList, memberList, reservation);
			}
			else if (selectionNumber == 6)
			{
				viewReservation(hikeList, memberList, reservation);
			}
			else if (selectionNumber == 7)
			{
				cancelReservation(hikeList, memberList, reservation);
			}
			else
			{
				cout << "Invalid selection. Please try again." << endl;
			}

			cout << endl
				<< "( *** Will continue to scheduling and payment. *** )"
				<< endl << endl;

			system("Pause");

			cout << endl;

			displayMenu();
		}
		else
		{
			cout << "Thank you for visiting!" << endl;
			programRun = false;
		}
	}
}

void chooseByLocation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservation)
{
	string userLocationChoice;

	hikeList.printAllLocations();

	cout << endl << "Choose a location: ";
	cin >> userLocationChoice;

	hikeList.printByLocation(userLocationChoice);

	askToReserve(hikeList, memberList, reservation);
}

void chooseByDuration(HikeList& hikeList,
	MemberList& memberList, Reservations& reservation)
{
	int userDurationChoice = 0;

	hikeList.printByDuration();

	cout << endl << "How many days are you considering: ";
	cin >> userDurationChoice;
	cout << endl;

	hikeList.printByDuration(userDurationChoice);

	askToReserve(hikeList, memberList, reservation);
}

void chooseByDifficulty(HikeList& hikeList,
	MemberList& memberList, Reservations& reservation)
{
	char userDifficultyChoice = 'e';

	cout << "Choose difficulty level: " << endl
		<< "	e. easy" << endl
		<< "	m. moderation" << endl
		<< "	s. strenous" << endl
		<< endl << "Your choice: ";
	cin >> userDifficultyChoice;

	cout << endl << "	(difficulty level)" << endl;
	
	hikeList.printByDifficulty(userDifficultyChoice);

	askToReserve(hikeList, memberList, reservation);
}

void chooseByPrice(HikeList& hikeList,
	MemberList& memberList, Reservations& reservation)
{
	hikeList.printByPrice();

	askToReserve(hikeList, memberList, reservation);
}

int askIfMember(MemberList& memberList)
{
	char userMemberStatusConfirm = 'y';
	int userIdConfirm = 0;
	string userLastNameConfirm;

	cout << endl << "Are you a member? (y/n) ";

	cin >> userMemberStatusConfirm;

	if (userMemberStatusConfirm == 'y')
	{
		cout << endl << "What is your member ID number? ";
		cin >> userIdConfirm;
		
		cout << endl << "What is your last name? ";
		cin >> userLastNameConfirm;

		memberList.printMember(userIdConfirm, userLastNameConfirm);

		return userIdConfirm;
	}
	else
	{
		return addNewMember(memberList);
	}
}

int addNewMember(MemberList& memberList)
{
	string newMemberFirstName, newMemberLastName;

	cout << endl << "Let's add you to the member list!" << endl
		<< "	What is your first name? ";
	getline(cin >> ws, newMemberFirstName);

	cout << "	What is your last name? ";
	getline(cin >> ws, newMemberLastName);

	memberList.addMember(newMemberFirstName, newMemberLastName);

	cout << endl << "	Welcome to the club!" << endl
		<< "	Your member ID number is: " << memberList.getLastID()
		<< endl;
	
	return memberList.getLastID();
}

void makeReservation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservation)
{
	string userHikeChoice;
	int memberIdRetrive = 0;
	int reservedNumber = 0;

	memberIdRetrive = askIfMember(memberList);
	
	cout << endl << "Which hike would you like to reserve (hike name)? ";
	getline(cin >> ws, userHikeChoice);
	
	reservedNumber = reservation.addReservation(memberIdRetrive, userHikeChoice);

	reservation.printReservation(reservedNumber, hikeList, memberList);

	cout << endl
		<< "	Before proceeding, please make a note of your reservation number."
		<< endl << "	  Reservation #: " << reservedNumber << endl;
}

void viewReservation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservation)
{
	int userReservationNum = 0;

	cout << "Enter reservation #: ";
	cin >> userReservationNum;

	reservation.printReservation(
		userReservationNum, hikeList, memberList);
}

void cancelReservation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservation)
{
	int userReservationNum = 0;
	char userCancelConfirm = 'n';

	cout << "Enter reservation #: ";
	cin >> userReservationNum;

	reservation.printReservation(userReservationNum, hikeList, memberList);

	cout << "Are you sure you want to cancel this reservation? (y/n) ";
	cin >> userCancelConfirm;

	if (userCancelConfirm == 'y')
	{
		reservation.cancelReservation(userReservationNum);
	}
}

void askToReserve(HikeList& hikeList,
	MemberList& memberList, Reservations& reservation)
{
	char userReserveConfirm = 'n';

	cout << endl << "Would you like to make a reservation? (y/n) ";

	cin >> userReserveConfirm;

	if (userReserveConfirm == 'y')
	{
		makeReservation(hikeList, memberList, reservation);
	}
}