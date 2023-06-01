/*
    Cookie Army

    Nguyen, Benjamin
    Ramirez, Louis
    Do, Henry

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Member.h"

#include <string>
#include <set> 

const int FIRST_ID_NUMBER = 111;

class MemberList
{
public:
    MemberList();

    void addMember(const std::string&, const std::string&);
    void addMember(const std::string&, const std::string&, int);

    int getLastID() const;
    int getPoints(int) const;

    void printMember(int, const std::string&);

    void clearList();
    ~MemberList();

private:
    std::set<Member> *listOfMember;
};

#endif