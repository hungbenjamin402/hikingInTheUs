/*
	Cookie Army

	Nguyen, Benjamin
	Ramirez, Louis
	Do, Henry

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Hike.h"

using namespace std;

ostream& operator<<(ostream& os, const Hike& myHike)
{
	string fullDifficulty;

	if (myHike.hikeDifficulty == 'e')
		fullDifficulty = "easy";
	else if (myHike.hikeDifficulty == 'm')
		fullDifficulty = "moderate";
	else
		fullDifficulty = "strenuous";

	return os << "	   " << myHike.hikeName << " (" 
		<< myHike.hikeLocation << ")\n	     Difficulty: " 
		<< fullDifficulty << "\n	     Duration: " 
		<< myHike.hikeDuration << " day(s)" << endl;
}

Hike::Hike()
{
	hikeDuration = 0;
	hikeDifficulty = 'e';
}

Hike::Hike(const string& newLocation, const string& newName, 
	int newDuration, char newDifficulty)
{
	hikeLocation = newLocation;
	hikeName = newName;
	hikeDuration = newDuration;
	hikeDifficulty = newDifficulty;
}

string Hike::getHikeLocation() const
{
	return hikeLocation;
}

string Hike::getHikeName() const
{
	return hikeName;
}

int Hike::getHikeDuration() const
{
	return hikeDuration;
}

char Hike::getHikeDifficulty() const
{
	return hikeDifficulty;
}

bool Hike::operator<(const Hike& hikeInfo) const
{
	return this->getHikeLocation() < hikeInfo.getHikeLocation();
}

Hike:: ~Hike()
{

}