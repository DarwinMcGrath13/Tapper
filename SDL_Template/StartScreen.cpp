#include "StartScreen.h"

StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();

	// logo entities
	mLogo = new Texture("TapperLogo.png");
	mLogo->Parent(this);
	//mLogo->Scale(Vector2(1.75f, 1.75f));
	mLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, 384);
	
	
	// bottom bar entities
	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.77f);
	mCopyright1 = new Texture("©COPYRIGHT MCMLXXXIII", "tapper.ttf", 28, { 36, 146, 255 });
	mCopyright2 = new Texture("BALLY MIDWAY MFG", "tapper.ttf", 28, { 36, 146, 255 });
	mCopyright3 = new Texture("ALL RIGHTS RESERVED", "tapper.ttf", 28, { 36, 146, 255 });
	mCreditsLabel = new Texture("CREDIT", "tapper.ttf", 28, { 36, 146, 255 });
	mInsertCoin = new Texture("INSERT COIN", "tapper.ttf", 28, { 36, 146, 255 });
	mCreditsScoreboard = new Scoreboard({ 36, 146, 255 });

	mBottomBar->Parent(this);
	mCopyright1->Parent(mBottomBar);
	mCopyright2->Parent(mBottomBar);
	mCopyright3->Parent(mBottomBar);
	mCreditsLabel->Parent(mBottomBar);
	mInsertCoin->Parent(mBottomBar);
	mCreditsScoreboard->Parent(mBottomBar);

	mCopyright1->Position(Vec2_Zero);
	mCopyright2->Position(16.0f, 32.0f);
	mCopyright3->Position(0.0f, 64.0f);
	mCreditsLabel->Position(-336.0f, 128.0f);
	mInsertCoin->Position(160.f, 128.0f);
	mCreditsScoreboard->Position(-192.0f, 128.0f);

	mCredits = 0;

}


StartScreen::~StartScreen() {
	
	// logo entities
	delete mLogo;
	mLogo = nullptr;

	// bottom bar entities
	delete mBottomBar;
	mBottomBar = nullptr;
	delete mCopyright1;
	mCopyright1 = nullptr;
	delete mCopyright2;
	mCopyright2 = nullptr;
	delete mCopyright3;
	mCopyright3 = nullptr;

	mTimer = nullptr;
	mInput = nullptr;
}


void StartScreen::Update() {
	if (mInput->KeyPressed(SDL_SCANCODE_UP)) {
		mCredits++;
		mCreditsScoreboard->Score(mCredits);
	}
}

void StartScreen::Render() {
	
	mLogo->Render();


	mCopyright1->Render();
	mCopyright2->Render();
	mCopyright3->Render();

	mCreditsLabel->Render();
	mInsertCoin->Render();

	mCreditsScoreboard->Render();
}

int StartScreen::Credits() {
	return mCredits;
}

void StartScreen::Credits(int value) {
	mCredits = value;
	mCreditsScoreboard->Score(mCredits);
}