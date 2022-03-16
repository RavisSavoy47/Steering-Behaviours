#include "WanderDecision.h"
#include "WanderBehaviour.h"
#include "SeekBehaviour.h"
#include "Agent.h"
void WanderDecision::makeDecision(Agent* agent, float deltaTime)
{
	WanderBehaviour* wander = agent->getComponet<WanderBehaviour>();
	SeekBehaviour* seek = agent->getComponet<SeekBehaviour>();

	if (wander)
		wander->setSteeringForce(50);

	if (seek)
		seek->setSteeringForce(0);
}
