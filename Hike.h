/*
	Cookie Army

	Nguyen, Benjamin
	Ramirez, Louis
	Do, Henry

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef HIKE_H
#define HIKE_H

#include <iostream>
#include <string>

class Hike
{
public:
	friend std::ostream& operator<<(std::ostream&, const Hike&);
	Hike();
	Hike(const std::string&, const std::string&, int, char);
	
	std::string getHikeLocation() const;
	std::string getHikeName() const;
	int getHikeDuration() const;
	char getHikeDifficulty() const;

	bool operator<(const Hike&) const;

	~Hike();

private:
	std::string hikeLocation;
	std::string hikeName;
	int hikeDuration;
	char hikeDifficulty;
};

#endif