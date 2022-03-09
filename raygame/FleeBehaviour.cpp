#include "FleeBehaviour.h"
#include "Transform2D.h"
#include "Actor.h"
#include "MoveComponent.h"
#include "Agent.h"
#include <Vector2.h>

MathLibrary::Vector2 FleeBehaviour::calculateForce()
{
	if (!getTarget())
		return { 0,0 };

	MathLibrary::Vector2 directionToTarget = getOwner()->getTransform()->getWorldPosition() - getTarget()->getTransform()->getWorldPosition();

	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 seekForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return seekForce;
}
