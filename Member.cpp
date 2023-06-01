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

#include <iostream>

using namespace std;

Member::Member()
{
	idMemberNumber = 0;
	points = 0;
}

Member::Member(string firstNamePass, string lastNamePass) 
{
	firstName = firstNamePass;
	lastName = lastNamePass;
	idMemberNumber = 0;
	points = 0;
}

void Member::addPoints(int pointsAdded)
{
	points += pointsAdded;
}

void Member::setID(int idSetNumber)
{
	idMemberNumber = idSetNumber;
}

int Member::getID() const
{
	return idMemberNumber;
}

string Member::getLastName() const
{
	return lastName;
}

int Member::getPoints() const
{
	return points;
}

void Member::printMember() const
{
	cout << "\n	" << lastName << ", " << firstName << endl
		<< "	" << "Points available: " << points << endl;
}
