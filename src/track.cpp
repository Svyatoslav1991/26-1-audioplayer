#include "track.h"

#include <sstream>
#include <iostream>

Track::Track(std::string singer, std::string song,  std::string date, int64_t time)
{
	//check singer
	if (singer.empty())
	{
		throw std::invalid_argument("Track singer is empty");
	}
	else
	{
		m_singer = singer;
	}


	//check song
	if (song.empty())
	{
		throw std::invalid_argument("Track song is empty");
	}
	else
	{
		m_song = song;
	}

	//check date
	std::tm t = {};
	std::istringstream iss(date);
	iss >> std::get_time(&t, "%Y/%m");
	if (iss.fail())
	{
		throw std::invalid_argument("Invalid date format, it is not \"YYYY/MM\"");
	}

	t.tm_mday = 1;
	std::time_t now = std::time(nullptr);

	if (std::difftime(now, std::mktime(&t)) < 0)
	{
		throw std::invalid_argument("Date in the future");
	}

	m_date = t;

	//check time
	if (time < 0)
	{
		throw std::invalid_argument("Time is negative");
	}
	else if (time < 10)
	{
		throw std::invalid_argument("Time is too short");
	}
	else if (time > 9999)
	{
		throw std::invalid_argument("Time is too long");
	}

	m_time = time;
}

//******************************************************************************************************************************************************************************************************

void Track::printInfo() const
{
	std::cout << "Singer: " << m_singer <<  "\tSong: " << m_song << "\tDate: " << std::put_time(&m_date, "%m-%Y") << "\tTime: " << m_time/60 << ":" << std::setw(2) << std::setfill('0') << m_time%60;
}

//******************************************************************************************************************************************************************************************************

std::string Track::getSong() const
{
	return m_song;
}