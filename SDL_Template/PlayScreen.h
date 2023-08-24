#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "Scoreboard.h"
#include "Timer.h"
#include "AudioManager.h"
#include "Player.h"

class PlayScreen : public GameEntity {
private:
	Timer * mTimer;
	AudioManager * mAudio;

	Player * mPlayer;

	Scoreboard* mPlayerScoreboard;
	int mPlayerScore;

public:
	PlayScreen();
	~PlayScreen();

	int PScore();
	void PScore(int value);

	void Update() override;
	void Render() override;
};
#endif