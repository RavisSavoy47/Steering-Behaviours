#pragma once
#include "Actor.h"
class MoveComponent;
class SpriteComponent;
class SeekBehaviour;
class FleeBehaviour;
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
	SeekBehaviour* m_seekComp;
	FleeBehaviour* m_fleeComp;
	Actor* m_target;
};

