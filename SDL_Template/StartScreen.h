#ifndef __STARTSCREEN_H
#define __STARTSCREEN_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "Scoreboard.h"

using namespace SDLFramework;

class StartScreen : public GameEntity {

private:
	Timer * mTimer;
	InputManager * mInput;

	// Logo Entities
	Texture * mLogo;

	// Bottom Bar Entities
	GameEntity * mBottomBar;
	Texture * mCopyright1;
	Texture * mCopyright2;
	Texture * mCopyright3;
	Texture* mCreditsLabel;
	Texture* mInsertCoin;

	Scoreboard* mCreditsScoreboard;

	int mCredits;

	// Screen Animation Variables
	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

public:
	StartScreen();
	~StartScreen();

	int Credits();
	void Credits(int value);

	void Update() override;
	void Render() override;
};
#endif