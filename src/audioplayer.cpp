#include "audioplayer.h"
#include "..\include\audioplayer.h"
#include <cstdlib>

AudioPlayer::AudioPlayer(std::vector<std::unique_ptr<Track>>& tracks) : m_numberPlayingSong(-1), m_mode(Mode::stop)
{
	for (auto& tr : tracks)
	{
		m_vTracks.emplace_back(std::move(tr));
	}

	if (m_vTracks.empty())
	{
		throw std::out_of_range("Audioplayer is empty!");
	}
}

//**************************************************************************************************************

void AudioPlayer::showTracksList() const
{
	std::cout << "\n";

	int64_t i = 1;
	for (const auto& track : m_vTracks)
	{
		std::cout << i++ << ": ";
		track->printInfo();
		std::cout << "\n";
	}

	std::cout << "\n";
}

//**************************************************************************************************************

void AudioPlayer::play()
{
	if (m_mode == Mode::pause)
	{
		std::cout << "Continue to play track: ";
		m_vTracks[m_numberPlayingSong]->printInfo();
		std::cout << "\n";
		m_mode = Mode::play;
	}
	else if(m_mode == Mode::stop)
	{
		std::string songName;
		while(true)
		{
			std::cout << "Enter the song's name\n";
			std::getline(std::cin, songName);
			for (int64_t i = 0; i < m_vTracks.size(); ++i)
			{
				if (songName == m_vTracks[i]->getSong())
				{
					m_numberPlayingSong = i;
					break;
				}
			}

			if (m_numberPlayingSong == -1)
			{
				std::cout << "You entered something wrong. Try again\n";
			}
			else
			{
				break;
			}
		};

		std::cout << "Now is played ";
		m_vTracks[m_numberPlayingSong]->printInfo();
		std::cout << "\n";
		m_mode = Mode::play;
	}
}

//**************************************************************************************************************

void AudioPlayer::pause()
{
	if (m_mode == Mode::play)
	{
		std::cout << "Track ";
		m_vTracks[m_numberPlayingSong]->printInfo();
		std::cout << " IS PAUSED\n";
		m_mode = Mode::pause;
	}
}

//**************************************************************************************************************

void AudioPlayer::next()
{
	if (m_mode != Mode::stop)
	{
		int64_t value = m_numberPlayingSong;
		do
		{
			value = rand() % m_vTracks.size();
		} while (value == m_numberPlayingSong);

		m_numberPlayingSong = value;
		m_mode = Mode::play;
		
		std::cout << "Now is played ";
		m_vTracks[m_numberPlayingSong]->printInfo();
		std::cout << "\n";
	}
}

//**************************************************************************************************************

void AudioPlayer::stop()
{
	if (m_mode != Mode::stop)
	{
		std::cout << "The audio player has stopped working\n";
		m_mode = Mode::stop;
		m_numberPlayingSong = -1;
	}
	
}