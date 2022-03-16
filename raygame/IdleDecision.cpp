#include "IdleDecision.h"
#include "WanderBehaviour.h"
#include "SeekBehaviour.h"
#include "Agent.h"

void IdleDecision::makeDecision(Agent* agent, float deltaTime)
{
	WanderBehaviour* wander = agent->getComponet<WanderBehaviour>();

	if (wander)
		wander->setSteeringForce(0);

	SeekBehaviour* seek =  agent->getComponet<SeekBehaviour>();

	if (seek)
		seek->setSteeringForce(0);
}
