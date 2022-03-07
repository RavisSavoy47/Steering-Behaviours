#include "WanderBehaviour.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Actor.h"
#include <cmath>

WanderBehaviour::WanderBehaviour(float radius, float distance)
{
	m_force = 150;
	m_distance = distance;
	m_circleRadius = radius;
	m_circleDistance = MathLibrary::Vector2{ 0,0 };;
}

void WanderBehaviour::update(float deltaTime)
{
	MathLibrary::Vector2 circlePos = getOwner()->getTransform()->getWorldPosition() + (getOwner()->getTransform()->getForward() * m_distance);

	float randNum = (rand() % 400) - 200;
	MathLibrary::Vector2 randPos = { cos(randNum), sin(randNum) };

	MathLibrary::Vector2 randomPnt = randPos.getNormalized() * m_circleRadius;
	randomPnt = randomPnt + circlePos;

	MathLibrary::Vector2 circleOffest = (randomPnt - getOwner()->getTransform()->getWorldPosition()).getNormalized() * m_force;
	m_circleDistance = circleOffest;

	getOwner()->getTransform()->setForward(m_circleDistance);


}
