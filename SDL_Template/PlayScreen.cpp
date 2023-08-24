#include "PlayScreen.h"



PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	mPlayerScoreboard = new Scoreboard({ 36, 146, 255 });
	mPlayerScoreboard->Parent(this);
	mPlayerScoreboard->Position(Graphics::SCREEN_WIDTH * 0.2f, Graphics::SCREEN_HEIGHT * 0.1f);
	mPlayerScore = 0;

	delete mPlayer;
	mPlayer = new Player();
	mPlayer->Parent(this);
	mPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);
	mPlayer->Active(true);
}

PlayScreen::~PlayScreen() {
	mTimer = nullptr;
	mAudio = nullptr;

	delete mPlayer;
	mPlayer = nullptr;
}
   //keeps updating score by frame rate
void PlayScreen::Update() {
	mPlayer->Update();	
	mPlayerScore++;
	mPlayerScoreboard->Score(mPlayerScore);
}

void PlayScreen::Render() {
	mPlayer->Render();
	mPlayerScoreboard->Render();
}

int PlayScreen::PScore() {
	return mPlayerScore;
}

void PlayScreen::PScore(int value) {
	mPlayerScore = value;
	mPlayerScoreboard->Score(mPlayerScore);
}

