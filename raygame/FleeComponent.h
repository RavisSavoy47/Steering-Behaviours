#pragma once
#include "Component.h"
#include <Vector2.h>
class FleeComponent :
	public Component
{
public:
	FleeComponent(Actor* target, const char* name = "FleeComponent");

	void setTarget(Actor* target) { m_target = target; }

	Actor* getTarget() { return m_target; }

	void update(float deltaTime) override;

private:
	Actor* m_target;
	MathLibrary::Vector2 m_currentVelocity;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_steeringForce;
	float m_force;
};

