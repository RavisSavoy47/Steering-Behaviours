#pragma once
#include "Component.h"

enum State
{
	IDLE,
	WANDER,
	SEEK
};

class SeekBehaviour;
class WanderBehaviour;

class StateMachineComponent :
	public Component
{
public:
	void start() override;

	State getCurrentState() { return m_currentState; }
	void setCurrrentState(State state) { m_currentState = state; }

	void update(float deltaTime) override;

private:
	State m_currentState;
	SeekBehaviour* m_seekBehaviour;
	WanderBehaviour* m_wanderBehaviour;
	float m_seekForce;
	float m_wanderForce;
	float m_seekRange = 300;
};

