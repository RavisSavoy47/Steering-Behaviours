#include "Agent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include "Player.h"
#include "Transform2D.h"

void Agent::start()
{
	Actor::start();

	m_moveComp = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComp->setMaxSpeed(300);
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));
	m_seekComp = dynamic_cast<SeekBehaviour*>(addComponent(new SeekBehaviour(m_target)));
	//m_wanderComp = dynamic_cast<WanderBehaviour*>(addComponent(new WanderBehaviour()));
	//m_fleeComp = dynamic_cast<FleeBehaviour*>(addComponent(new FleeBehaviour(m_target)));
}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);
}
