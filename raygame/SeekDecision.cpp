#include "SeekDecision.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"
#include"Agent.h"
#include "Enemy.h"
void SeekDecision::makeDecision(Agent* agent, float deltaTime)
{
	SeekBehaviour* seek = agent->getComponet<SeekBehaviour>();
	WanderBehaviour* wander = agent->getComponet<WanderBehaviour>();
	Enemy* enemy = dynamic_cast<Enemy*>(agent);

	if (seek)
		seek->setSteeringForce(52);

	if (wander)
		wander->setSteeringForce(0);

	if (enemy)
		enemy->setIsAggressive(true);
}
