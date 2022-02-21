#include "SeekComponent.h"
#include "Transform2D.h"
#include "Actor.h"

void SeekComponent::update(float deltaTime)
{
	m_maxVelocity.normalize = getMaxSpeed();
	//Add the new velocity to the old position to get the new position
	m_desiredVelocity = getTarget()->getTransform()->getLocalPosition() - getOwner()->getTransform()->getLocalPosition() * m_maxVelocity.normalize;
	
	m_currentVelocity = getOwner()->getTransform()->getLocalPosition();

	//Set the actors position to be the new position found
	m_steeringForce = m_desiredVelocity - m_currentVelocity;
}
