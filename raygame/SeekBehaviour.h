#pragma once
#include "Component.h"
#include <Vector2.h>

class MoveComponet;
class SeekBehaviour :
	public Component
{
public:
	SeekBehaviour(Actor* target, const char* name = "SeekComponent");

	void setTarget(Actor* target) { m_target = target; }

	Actor* getTarget() { return m_target; }

	void update(float deltaTime) override;

private:
	Actor* m_target;
	MathLibrary::Vector2 m_currentVelocity;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_steeringForce;
	float m_seekForce;
};

