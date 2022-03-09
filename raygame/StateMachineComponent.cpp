#include "StateMachineComponent.h"
#include "Actor.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"
#include "Transform2D.h"

void StateMachineComponent::start()
{
	Component::start();

	m_seekBehaviour = getOwner()->getComponet<SeekBehaviour>();
	m_seekForce = m_seekBehaviour->getSteeringForce();

	m_wanderBehaviour = getOwner()->addComponent<WanderBehaviour>();
	m_wanderForce = m_wanderBehaviour->getSteeringForce();

	m_currentState = IDLE;
}

void StateMachineComponent::update(float deltaTime)
{
	Component::update(deltaTime);

	MathLibrary::Vector2 targetPos = m_seekBehaviour->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();

	bool targetInRange = distanceFromTarget <= m_seekRange;
	switch (m_currentState)
	{
	case IDLE:
		m_seekBehaviour->setSteeringForce(0);
		m_wanderBehaviour->setSteeringForce(0);

		if (targetInRange)
			setCurrrentState(SEEK);

		break;
	case WANDER:
		m_seekBehaviour->setSteeringForce(0);
		m_wanderBehaviour->setSteeringForce(m_wanderForce);

		if (targetInRange)
			setCurrrentState(SEEK);

		break;
	case SEEK:
		m_seekBehaviour->setSteeringForce(m_seekForce);
		m_wanderBehaviour->setSteeringForce(0);

		if (!targetInRange)
			setCurrrentState(WANDER);
		break;
	}
}
