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

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string MEMBERS_FILE = "members_database.txt";

void createMemberList(ifstream& infile, MemberList& memberList)
{
	string memberFirstName,
		   memberLastName;
	int memberId = 0;

	while (!infile.eof())
	{
		infile >> memberFirstName >> memberLastName >> memberId;
		memberList.addMember(memberFirstName, memberLastName, memberId);
	}
}

void getMemberData(MemberList& memberList)
{
	ifstream infile;

	infile.open(MEMBERS_FILE);

	if (!infile)
	{
		cerr << MEMBERS_FILE << " does not exist." << endl;
		exit(1);
	}

	createMemberList(infile, memberList);

	infile.close();
}