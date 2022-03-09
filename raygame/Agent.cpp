#include "Agent.h"
#include "MoveComponent.h"
#include "SteeringComponent.h"
#include "SpriteComponent.h"

void Agent::start()
{
	Actor::start();

	m_moveComp = addComponent<MoveComponent>();
	m_moveComp->setMaxSpeed(300);
	m_moveComp->setUpdateFacing(true);
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));
}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);

	//Get all force being applied from the steering behaviours
	for (int i = 0; i < m_steeringComponents.getLength(); i++)
	{
		m_force = m_force + m_steeringComponents[i]->calculateForce();
	}

	//Clamps force if it exceeds the maximum scale
	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = m_force.getNormalized() * getMaxForce();
	}

	//Apply force to veocity
	getMoveComponent()->setVelocity(getMoveComponent()->getVelocity() + m_force * deltaTime);
}

void Agent::onAddComponent(Component* component)
{
	SteeringComponent* steeringComponent = dynamic_cast<SteeringComponent*>(component);
	if (steeringComponent)
		m_steeringComponents.addItem(steeringComponent);
}

