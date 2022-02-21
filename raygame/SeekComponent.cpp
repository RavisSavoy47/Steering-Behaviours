#include "SeekComponent.h"
#include "Transform2D.h"
#include "Actor.h"
#include "MoveComponent.h"

SeekComponent::SeekComponent(Actor* target, const char* name) : Component::Component(name)
{
	m_target = target;
	m_seekForce = 200;
	m_currentVelocity = MathLibrary::Vector2{0,0};
}

void SeekComponent::update(float deltaTime)
{
	//Add the new velocity to the old position to get the new position
	m_desiredVelocity = (getTarget()->getTransform()->getLocalPosition() - getOwner()->getTransform()->getLocalPosition()) * m_seekForce;

	m_steeringForce = m_desiredVelocity - m_currentVelocity;

	m_currentVelocity = m_currentVelocity + (m_steeringForce * deltaTime);

	//Add the new velocity to the old position to get the new position
	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getLocalPosition() + (m_currentVelocity * deltaTime);

	newPosition = newPosition + (m_currentVelocity * deltaTime);

	//Set the actors position to be the new position found
	getOwner()->getTransform()->setLocalPosition(newPosition);
}
