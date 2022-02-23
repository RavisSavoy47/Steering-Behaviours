#pragma once
#include "Component.h"
#include <Vector2.h>
class WanderBehaviour :
	public Component
{
public:
	WanderBehaviour(float radius, float distance);

	void setRadius(float radius) { m_radius = radius; }
	void setDistance(float distance) { m_distance = distance; }

	void update(float deltaTime) override;

private:
	float m_radius;
	float m_distance;
	float m_force;
	MathLibrary::Vector2 m_angle;
};

