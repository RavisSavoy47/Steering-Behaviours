#include "SeekBehaviour.h"
#include "Transform2D.h"
#include "Actor.h"
#include "MoveComponent.h"
#include "Agent.h"
#include <Vector2.h>

MathLibrary::Vector2 SeekBehaviour::calculateForce()
{
	if (!getTarget())
		return { 0,0 };

	setSteeringForce(1000);

	MathLibrary::Vector2 directionToTarget = getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition();

	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 seekForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return seekForce;
}

//void SeekBehaviour::update(float deltaTime)
//{
//	//Add the new velocity to the old position to get the new position
//	m_desiredVelocity = MathLibrary::Vector2::normalize(getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()) * m_force;
//
//	m_steeringForce = m_desiredVelocity - m_currentVelocity;
//
//	m_currentVelocity = m_currentVelocity + (m_steeringForce * deltaTime);
//
//	//Add the new velocity to the old position to get the new position
//	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getWorldPosition() + (m_currentVelocity * deltaTime);
//
//	newPosition = newPosition + (m_currentVelocity * deltaTime);
//
//	//Set the actors position to be the new position found
//	getOwner()->getTransform()->setWorldPostion(newPosition);
//}

