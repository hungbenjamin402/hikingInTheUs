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

#include <iostream>
#include <algorithm>

using namespace std;

bool operator<(const Member& firstObj, const Member& secondObj)
{
    return (firstObj.getID() < secondObj.getID());
}

MemberList::MemberList()
{
    listOfMember = new set<Member>();
}

void MemberList::addMember(const string& firstName, 
    const string& lastName)
{
    Member newMember(firstName, lastName);
    
    int firstId = FIRST_ID_NUMBER;

    if ((*listOfMember).empty())
    {
        newMember.setID(firstId);
        (*listOfMember).insert(newMember);
    }
    else
    {
        newMember.setID((((*listOfMember).rbegin())->getID()) + 1);
        (*listOfMember).insert(newMember);
    }
}

void MemberList::addMember(const string& firstName, 
    const string& lastName, int points)
{
    Member newMember(firstName, lastName);
    int firstId = FIRST_ID_NUMBER;

    newMember.addPoints(points);
     
    if ((*listOfMember).empty())
    {
        newMember.setID(firstId);
        (*listOfMember).insert(newMember);
    }
    else
    {
        newMember.setID((((*listOfMember).rbegin())->getID())+1);
        (*listOfMember).insert(newMember);
    }
}

int MemberList::getLastID() const
{
    return ((*listOfMember).crbegin())->getID();
}

int MemberList::getPoints(int searchedID) const
{
    auto iterPointsLinkedID = find_if(
        (*listOfMember).cbegin(), (*listOfMember).cend(),
        [&](const auto& elem) { return elem.getID() == searchedID; } );
    return iterPointsLinkedID->getPoints();
}

void MemberList::printMember(int searchedID, 
    const string& seachedLastName)
{
    auto iterFindMember = find_if(
        (*listOfMember).cbegin(), (*listOfMember).cend(),
        [&](const auto& elem) { return elem.getID() == searchedID; } );

    if (iterFindMember->getLastName() == seachedLastName)
    {
        iterFindMember->printMember();
        cout << "        Membership # " << searchedID << endl;
    }
}

void MemberList::clearList()
{
    (*listOfMember).clear();
}

MemberList::~MemberList()
{
    delete listOfMember;
    listOfMember = nullptr;
}

