/*
	Cookie Army

	Nguyen, Benjamin
	Ramirez, Louis
	Do, Henry

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
public:
	Member(); 
	Member(std::string firstNamePass, std::string lastNamePass);

	void addPoints(int pointsAdded);
	void setID(int idSetNumber);

	int getID() const;
	std::string getLastName() const;
	int getPoints() const;

	void printMember() const;

private:
	int idMemberNumber;
	std::string firstName;
	std::string lastName;
	int points;
};

#endif

