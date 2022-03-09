#include "WanderBehaviour.h"
#include "Transform2D.h"
#include "Actor.h"
#include "Agent.h"
#include "MoveComponent.h"
#include <time.h>

WanderBehaviour::WanderBehaviour(float circleRadius, float circleDistance, float wanderForce) : SteeringComponent(nullptr, wanderForce)
{
	m_circleDistance = circleDistance;
	m_circleRadius = circleRadius;
	srand(time(NULL));
}

MathLibrary::Vector2 WanderBehaviour::calculateForce()
{
	//Find the agents position and heading
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 heading = getAgent()->getMoveComponent()->getVelocity().getNormalized();

	//Find the circle position in front of the agent
	m_circlePos = ownerPosition + (heading * m_circleDistance);

	//Find a random vector on the circle
	float randNum = (rand() % 201) - 100;
	MathLibrary::Vector2 randDirection = MathLibrary::Vector2{ (float)cos(randNum), (float)sin(randNum) } * m_circleRadius;

	//Add the random vector to the circle position to get th erandom point on the circle
	m_target = randDirection + m_circlePos;

	//Seek to the random point
	MathLibrary::Vector2 desiredVeloccity = MathLibrary::Vector2::normalize(m_target - ownerPosition) * getSteeringForce();
	MathLibrary::Vector2 force = desiredVeloccity - getAgent()->getMoveComponent()->getVelocity();

	return force;
}