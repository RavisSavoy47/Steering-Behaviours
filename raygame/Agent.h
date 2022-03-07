#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include <Vector2.h>
class SteeringComponent;
class MoveComponent;
class SpriteComponent;
class Agent :
	public Actor
{
public:
	Agent(Actor* target, float x, float y, const char* name) : Actor(x, y, name) { m_target = target; }

	void start() override;
	void update(float deltaTime) override;
	void onAddComponent(Component* component) override;
	float getMaxForce() { return m_maxForce; }
	void setMaxForce(float maxForce) { m_maxForce = maxForce; }
	MoveComponent* getMoveComponent() { return m_moveComp; }

private:
	DynamicArray<SteeringComponent*> m_steeringComponents;
	float m_maxForce;
	MoveComponent* m_moveComp;
	MathLibrary::Vector2 m_force;
	SpriteComponent* m_spriteComp;
	Actor* m_target;
};

