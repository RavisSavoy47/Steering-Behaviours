#include "Agent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "SeekComponent.h"
#include "Player.h"
#include "Transform2D.h"

void Agent::start()
{
	Actor::start();

	m_moveComp = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComp->setMaxSpeed(10);
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));
	m_seekComp = dynamic_cast<SeekComponent*>(addComponent(new SeekComponent(m_target)));
}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);

}
