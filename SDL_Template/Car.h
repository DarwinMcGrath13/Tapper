#ifndef __CAR_H
#define __CAR_H
#include "AnimatedTexture.h"
#include "PhysEntity.h"

using namespace SDLFramework;

class Car : public PhysEntity {
private:
	Timer* mTimer;
	
	bool mVisible;
	bool mWasHit;

	Texture* mCar;

	float mMoveSpeed;
	Vector2 mMoveBounds;

private:
	void HandleMovement();

public:
	Car();
	~Car();

	void Visible(bool visible);


	// Inherited from PhysEntity
	bool IgnoreCollisions() override;
	void Hit(PhysEntity* other) override;

	bool WasHit();

	void Update() override;
	void Render() override;
};
#endif