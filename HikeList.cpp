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
#include "HikeList.h"

#include <algorithm>
#include <iostream> 
#include <iomanip>

using namespace std;

HikeList::HikeList()
{

}

void HikeList::addHike(const Hike& hikeInfo, double hikePrice)
{
	hikeListDetail.insert(pair<Hike, double>(hikeInfo, hikePrice));
}

void HikeList::addHike(const string& hikeLocation, const string& hikeName,
	char hikeDifficulty, int hikeDuration, double hikePrice)
{
	Hike newHike(hikeLocation, hikeName, hikeDifficulty, hikeDuration);

	hikeListDetail.insert(pair<Hike, double>(newHike, hikePrice));
}

double HikeList::getPrice(const string& hikeName) const
{
	auto iterSearchName = find_if(
		hikeListDetail.cbegin(), hikeListDetail.cend(),
		[&hikeName](const auto& iter) 
		{ return (hikeName == iter.first.getHikeName()); } );

	return iterSearchName->second;
}

void HikeList::printAllLocations() const
{
	for (auto iter = hikeListDetail.cbegin(), end = hikeListDetail.cend();
		iter != end; iter = hikeListDetail.upper_bound(iter->first))
	{
		cout << "	" << (iter->first).getHikeLocation() << endl;
	}
}

void HikeList::printByLocation(const string& hikeLocation) const
{
	auto iterLocation = find_if(
		hikeListDetail.cbegin(), hikeListDetail.cend(),
		[&hikeLocation](const auto& locationIter)
		{ return (
			hikeLocation == locationIter.first.getHikeLocation()
			); 
		} );

	while (iterLocation != hikeListDetail.cend())
	{
		if ((iterLocation->first).getHikeLocation() == hikeLocation)
		{
			cout << endl 
				<< "	" << (iterLocation->first).getHikeName() << " "
				<< "(" << (iterLocation->first).getHikeLocation() << ")" 
				<< endl
				<< "	  Difficulty: " 
				<< (iterLocation->first).getHikeDifficulty() << endl
				<< "	  Duration: " 
				<< (iterLocation->first).getHikeDuration() << " day(s)" 
				<< endl
				<< "	  Price (per person): $ " 
				<< right << setw(7) << fixed << setprecision(2) 
				<< iterLocation->second << endl;
		}
		++iterLocation;
	}
}

void HikeList::printByDuration() const
{
	multimap<int, string> tempDuration;

	for (const auto& durIter : hikeListDetail)
	{
		tempDuration.insert(pair<int, string>
			(durIter.first.getHikeDuration(),
				durIter.first.getHikeLocation()));
	}

	for_each(tempDuration.cbegin(), tempDuration.cend(),
		[](const auto& temp)
		{ cout << "	(" << temp.first << ") " << temp.second << endl; } );

	tempDuration.clear();
}

void HikeList::printByDuration(int daysSort) const
{
	for (const auto& iterLoop : hikeListDetail)
	{
		if (iterLoop.first.getHikeDuration() == daysSort)
		{
			cout << "	" << iterLoop.first.getHikeName() << " (" 
				<< iterLoop.first.getHikeLocation() << ")" << endl
				<< "		" << "Difficulty: " 
				<< iterLoop.first.getHikeDifficulty() << endl
				<< "		" << "Duration: " 
				<< iterLoop.first.getHikeDuration() << " days(s)" << endl;
		}
	}
}

void HikeList::printByDifficulty(char hikeDifficulty) const
{
	for (const auto& iterDiff : hikeListDetail)
	{
		if (hikeDifficulty == iterDiff.first.getHikeDifficulty())
		{
			cout << "	(" << iterDiff.first.getHikeDifficulty() << ") "
				<< iterDiff.first.getHikeName()
				<< ", " << iterDiff.first.getHikeLocation() << endl;
		}
	}
}

void HikeList::printByPrice() const
{
	multimap<double, pair<string, string>> tempPrice;

	for (const auto& iterPrice : hikeListDetail)
	{
		tempPrice.emplace(iterPrice.second, pair<string, string>
			(iterPrice.first.getHikeName()
				, iterPrice.first.getHikeLocation()));
	}

	for (const auto& iter : tempPrice)
	{
		cout << "	$ " 
			<< right << setw(7) << fixed << setprecision(2) 
			<< iter.first << " - " << iter.second.second 
			<< " (" << iter.second.first << ")" << endl;
	}
}

void HikeList::printByHikeName(const string& hikeName) const
{
	auto iterFindHike = find_if(
		hikeListDetail.cbegin(), hikeListDetail.cend(),
		[&hikeName](const auto& locateHikeInList) 
		{return hikeName == locateHikeInList.first.getHikeName(); });

	cout << "\n	" << (iterFindHike->first).getHikeName() << " "
		<< "(" << (iterFindHike->first).getHikeLocation() << ")" << endl
		<< "	  Difficulty: " 
		<< (iterFindHike->first).getHikeDifficulty() 
		<< endl
		<< "	  Duration: " 
		<< (iterFindHike->first).getHikeDuration() << " day(s)" << endl
		<< "	  $" << right << setw(7) << fixed << setprecision(2)
		<< iterFindHike->second << endl;
}

void HikeList::clearList()
{
	hikeListDetail.clear();
}
