#pragma once
#include "Component.h"
#include <Vector2.h>
class MoveComponent;
class WanderBehaviour :
	public Component
{
public:
	WanderBehaviour() {};
	WanderBehaviour(float radius, float distance);
	~WanderBehaviour() {};

	void update(float deltaTime) override;
private:
	float m_force;
	float m_distance;
	float m_circleRadius;
	MathLibrary::Vector2 m_circleDistance;
};

