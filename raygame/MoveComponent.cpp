#include "MoveComponent.h"
#include "Actor.h"
#include"Transform2D.h"
#include "Engine.h"

void MoveComponent::update(float deltaTime)
{
	float xEnd = Engine::getScreenWidth() + 5;
	float yEnd = Engine::getScreenHeight() + 5;

	if (getOwner()->getTransform()->getWorldPosition().x > Engine::getScreenWidth() + 5)
		getOwner()->getTransform()->setWorldPostion({ 0, getOwner()->getTransform()->getWorldPosition().y });
	if (getOwner()->getTransform()->getWorldPosition().x < -10)
		getOwner()->getTransform()->setWorldPostion({ xEnd, getOwner()->getTransform()->getWorldPosition().y });
	if (getOwner()->getTransform()->getWorldPosition().y > Engine::getScreenHeight() + 5)
		getOwner()->getTransform()->setWorldPostion({ getOwner()->getTransform()->getWorldPosition().x, -5 });
	if (getOwner()->getTransform()->getWorldPosition().y < -10)
		getOwner()->getTransform()->setWorldPostion({ getOwner()->getTransform()->getWorldPosition().x, yEnd });

	//Add the new velocity to the old position to get the new position
	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime;

	MathLibrary::Vector2 forward = getOwner()->getTransform()->getForward();
	//Set the actors position to be the new position found
	getOwner()->getTransform()->setLocalPosition(newPosition);
}


