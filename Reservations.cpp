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
#include "HikeList.h"
#include "MemberList.h"

#include <iostream>

using namespace std;

int Reservations::addReservation(int memberId, const string& hikeName)
{
	int currentReservedNum = FIRST_RESEVERED_NUM;

	if (countNode == 0)
	{
		firstNode = new Node(currentReservedNum, memberId, 
			hikeName, nullptr, nullptr);
		lastNode = firstNode;
	}
	else
	{
		currentReservedNum += countNode;
		lastNode->setNext(new Node(currentReservedNum, memberId, 
			hikeName, lastNode, nullptr));
		lastNode = lastNode->getNext();
	}

	++countNode;

	return currentReservedNum;
}

Node* Reservations::findReservation(int reservedNum) const
{
	Node* current = firstNode;

	while (current->getReservationNum() != reservedNum)
	{
		current = current->getNext();
		
		if (current == nullptr)
			return nullptr;
	}

	return current;
}

void Reservations::printReservation(int reservedNum, 
	const HikeList& hikeInfo, const MemberList& memberInfo) const
{
	int dollarsOff = 0;

	if (findReservation(reservedNum) != nullptr)
	{
		dollarsOff = (memberInfo.getPoints(
			findReservation(reservedNum)->getMemberId()) / 100);

		hikeInfo.printByHikeName(findReservation(reservedNum)->getHikeName());
		
		if (dollarsOff != 0)
		{
			cout << endl << "	Discounted price using points: $"
				<< hikeInfo.getPrice(
					findReservation(reservedNum)->getHikeName()) - static_cast<double>(dollarsOff)
				<< endl;
		}
	}
	else
		cout << "This reservation does not exist." << endl;
}

void Reservations::clearList()
{
	Node* temp = firstNode;

	while (firstNode != nullptr)
	{
		firstNode = firstNode->getNext();
		delete temp;
		temp = firstNode;
	}

	lastNode = nullptr;

	countNode = 0;
}

Reservations::~Reservations()
{
	clearList();
}

void Reservations::cancelReservation(int reservedNum)
{
	if (findReservation(reservedNum) == firstNode)
	{
		firstNode = firstNode->getNext();
		delete firstNode->getPrev();
		firstNode->setPrev(nullptr);
	}
	else if (findReservation(reservedNum) == lastNode)
	{
		lastNode = lastNode->getPrev();
		delete lastNode->getNext();
		lastNode->setNext(nullptr);
	}
	else
	{
		Node* tempNode = findReservation(reservedNum);

		tempNode->getNext()->setPrev(tempNode->getPrev());
		tempNode->getPrev()->setNext(tempNode->getNext());
		delete tempNode;
	}

	--countNode;
}