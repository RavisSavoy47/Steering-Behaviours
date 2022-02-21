#pragma once
#include "Actor.h"
class MoveComponent;
class SpriteComponent;
class SeekComponent;
class Player;
class Agent :
	public Actor
{
public:
	Agent(Actor* target, float x, float y, const char* name) : Actor(x, y, name) { m_target = target; }

	void start() override;
	void update(float deltaTime) override;

private:
	MoveComponent* m_moveComp;
	SpriteComponent* m_spriteComp;
	SeekComponent* m_seekComp;
	Actor* m_target;
};

