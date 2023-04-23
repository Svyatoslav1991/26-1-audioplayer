#include <iostream>
#include <list>

#include "functions.h"
#include "track.h"
#include "audioplayer.h"


int main() {
	std::cout << "\tTASK 26.1 AUDIOPLAYER\n\n";

	try
	{
		srand(time(NULL));

		std::unique_ptr<Track> track1 = std::make_unique<Track>("QUEEN", "BOHEMIAN RHAPSODY", "1975/10", 355);
		std::unique_ptr<Track> track2 = std::make_unique<Track>("JOHN LENNON", "IMAGINE", "1971/07", 178);
		std::unique_ptr<Track> track3 = std::make_unique<Track>("NIRVANA", "SMELLS LIKE TEEN SPIRIT", "1991/09", 301);
		std::unique_ptr<Track> track4 = std::make_unique<Track>("EMINEM", "LOSE YOURSELF","2002/10", 320);
		std::unique_ptr<Track> track5 = std::make_unique<Track>("M. JACKSON", "BILLIE JEAN", "1983/01", 294);

		std::vector<std::unique_ptr<Track>> lTracks;
		lTracks.push_back(std::move(track1));
		lTracks.push_back(std::move(track2));
		lTracks.push_back(std::move(track3));
		lTracks.push_back(std::move(track4));
		lTracks.push_back(std::move(track5));

		AudioPlayer player(lTracks);
		player.showTracksList();

		std::string action;

		do
		{
			std::cout << "\nEnter \"play\" to play track\n";
			std::cout << "Enter \"pause\" to pause the track\n";
			std::cout << "Enter \"next\" to put another track\n";
			std::cout << "Enter \"stop\" to stop playing the track\n";
			std::cout << "Enter \"exit\" to quit programm\n";
			action = myCin<decltype(action)>();

			if (action == "exit")
			{
				break;
			}
			else if (action == "play")
			{
				player.play();
			}
			else if (action == "pause")
			{
				player.pause();
			}
			else if (action == "next")
			{
				player.next();
			}
			else if (action == "stop")
			{
				player.stop();
			}

		} while (true);
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception caught: " << ex.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Something went wrong\n";
	}
	


	return 0;
}