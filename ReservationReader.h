/*
	Cookie Army

	Nguyen, Benjamin
	Ramirez, Louis
	Do, Henry

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Reservations.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATIONS_FILE = "reservations_database.txt";

void createReservationList(ifstream& infile, Reservations& reservations)
{
	string hikeReserved;
	int reservedNumber = 0;

	while (!infile.eof())
	{
		infile >> reservedNumber >> hikeReserved;
		reservations.addReservation(reservedNumber, hikeReserved);
	}
}

void getReservationData(Reservations& reservations)
{
	ifstream infile;

	infile.open(RESERVATIONS_FILE);

	if (!infile)
	{
		cerr << RESERVATIONS_FILE << " does not exist." << endl;
		exit(1);
	}

	createReservationList(infile, reservations);

	infile.close();
}