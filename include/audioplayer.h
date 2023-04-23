#pragma once
#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include"track.h"
#include "functions.h"

#include <vector>
#include <memory>

class AudioPlayer {
	std::vector<std::unique_ptr<Track>> m_vTracks;
	int64_t m_numberPlayingSong;
	Mode m_mode;

public:
	AudioPlayer(std::vector<std::unique_ptr<Track>>& tracks);

	void showTracksList() const;
	void play();
	void pause();
	void next();
	void stop();
};

#endif //AUDIOPLAYER_H