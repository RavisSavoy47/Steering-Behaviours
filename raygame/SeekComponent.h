#pragma once
#include "Component.h"
#include <Vector2.h>
class SeekComponent :
	public Component
{
public:
	SeekComponent(Actor* target, const char* name = "SeekComponent") : Component::Component(name) {}

	Actor* setTarget(Actor* target) { m_target = target; }

	Actor* getTarget() { return m_target; }

	void update(float deltaTime) override;

	/// <summary>
	/// Get the maximum magnitude of this actors velocity vector
	/// </summary>
	/// <returns></returns>
	float getMaxSpeed() { return m_maxSpeed; }

	/// <summary>
	/// Set the maximum magnitude of this actors velocity vector
	/// </summary>
	/// <returns></returns>
	void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }

private:
	Actor* m_target;
	MathLibrary::Vector2 m_currentVelocity;
	MathLibrary::Vector2 m_maxVelocity;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_steeringForce;
	float m_maxSpeed;
};

