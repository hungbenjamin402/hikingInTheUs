/*
	Cookie Army

	Nguyen, Benjamin
	Ramirez, Louis
	Do, Henry

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef HIKELIST_H
#define HIKELIST_H

#include "Hike.h"

#include <map>
#include <string>

class HikeList
{
public:
	HikeList();

	void addHike(const Hike&, double);
	void addHike(const std::string&, const std::string&, char, int, double);

	double getPrice(const std::string&) const;

	void printAllLocations() const;
	void printByLocation(const std::string&) const;
	void printByDuration() const;
	void printByDuration(int) const;
	void printByDifficulty(char) const;
	void printByPrice() const;
	void printByHikeName(const std::string&) const;

	void clearList();

private:
	std::multimap<Hike, double> hikeListDetail;
};

#endif
