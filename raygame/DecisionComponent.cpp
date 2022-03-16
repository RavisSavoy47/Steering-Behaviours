#include "DecisionComponent.h"
#include "Decision.h"
#include "Agent.h"

void DecisionComponent::start()
{
	Component::start();
	m_owner = dynamic_cast<Agent*>(getOwner());
}

void DecisionComponent::update(float deltaTime)
{
	Component::update(deltaTime);
	if (m_owner)
		m_root->makeDecision(m_owner, deltaTime);
	else
		throw std::exception("Owner was null. Decision component can only be attached to agents.");
}
