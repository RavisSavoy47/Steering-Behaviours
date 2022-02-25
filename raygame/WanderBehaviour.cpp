#include "WanderBehaviour.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Actor.h"
#include <random>
#include <time.h>

WanderBehaviour::WanderBehaviour(MoveComponent* moveComponenet, float force, float radius, float distance)
{
	//sets the start of the time to be 0
	srand(time(0));

	m_moveComponent = moveComponenet;
	m_force = force;
	m_radius = radius;
	m_circleDistance = distance;
}

void WanderBehaviour::update(float deltaTime)
{

}
