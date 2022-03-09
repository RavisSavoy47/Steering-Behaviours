#pragma once
#include "SteeringComponent.h"
class WanderBehaviour :
	public SteeringComponent
{
public:
	WanderBehaviour() {};
	WanderBehaviour(float circleRadius, float circleDistance, float wanderForce);
	MathLibrary::Vector2 calculateForce() override;

private:
	float m_circleDistance = 0;
	float m_circleRadius = 0;
	float m_wanderAngle = 0;

	MathLibrary::Vector2 m_target;
	MathLibrary::Vector2 m_circlePos;
};

