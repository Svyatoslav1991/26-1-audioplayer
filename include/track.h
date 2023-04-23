#pragma once
#ifndef TRACK_H
#define TRACK_H

#include <iomanip>
#include <ctime>
#include <sstream>

class Track
{
public:
	Track(std::string singer, std::string song, std::string date, int64_t time);
	std::string getSong() const;
	void printInfo() const;

private:
	std::string m_song;
	std::string m_singer;
	std::tm m_date;
	int64_t m_time;
};



#endif // !TRACK_H
