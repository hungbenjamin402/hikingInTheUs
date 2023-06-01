/*
	Cookie Army

	Nguyen, Benjamin
	Ramirez, Louis
	Do, Henry

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include "HikeList.h"
#include "MemberList.h"

#include <string>

const int FIRST_RESEVERED_NUM = 50001;

class Node
{
public:
	Node(): resNum(0), memberId(0), next(nullptr), prev(nullptr) {}
	Node(int newResNum, int newMemId, std::string newName, 
		Node* prevLink, Node* nextLink): 
		resNum(newResNum), memberId(newMemId), hikeName(newName), 
		prev(prevLink), next(nextLink) {}
	int getReservationNum() const { return resNum; }
	int getMemberId() const { return memberId; }
	std::string getHikeName() const { return hikeName; }
	Node* getNext() const { return next; }
	Node* getPrev() const { return prev; }
	void setReservationNum(int newResNum) { resNum = newResNum; }
	void setMemberId(int newMemId) { memberId = newMemId; }
	void setHikeName(std::string newName) { hikeName = newName; }
	void setPrev(Node* prevLink) { prev = prevLink; }
	void setNext(Node* nextLink) { next = nextLink; }
	~Node() {}

private:
	int resNum;
	int memberId;
	std::string hikeName;
	Node* next;
	Node* prev;
};

class Reservations
{
public:
	Reservations(): firstNode(nullptr), lastNode(nullptr), countNode(0) {}

	int addReservation(int, const std::string&);
	void cancelReservation(int);

	void printReservation(int, const HikeList&, const MemberList&) const;

	void clearList();
	~Reservations();

private:
	Node* findReservation(int) const;
	Node* firstNode;
	Node* lastNode;
	int countNode;
};

#endif