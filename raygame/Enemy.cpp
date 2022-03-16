#include "Enemy.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "IsAggressiveDecision.h"
#include "SeekDecision.h"
#include "WanderDecision.h"
#include "IdleDecision.h"
#include "InRangeDecision.h"
#include "DecisionComponent.h"
Enemy::Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target): Agent(x, y, name, maxForce, maxSpeed)
{
    m_target = target;
}

void Enemy::start()
{
    Agent::start();

    IdleDecision* idle = new IdleDecision();
    WanderDecision* wander = new WanderDecision();
    SeekDecision* seek = new SeekDecision();

    IsAggressiveDecision* aggressive = new IsAggressiveDecision(idle, wander);
    InRangeDecision* inRange = new InRangeDecision(aggressive, seek);

    addComponent(new DecisionComponent(inRange));

    //Add the sprite component
    getTransform()->setScale({ 50,50 });

    addComponent(new SpriteComponent("Images/enemy.png"));

    //Initialized and added the wander component
    WanderBehaviour* wanderBehaviour = new WanderBehaviour(100, 150, 100);
    addComponent(wanderBehaviour);

    //Initialized and added the seek component
    SeekBehaviour* seekBehaviour = new SeekBehaviour();
    seekBehaviour->setTarget(m_target);
    seekBehaviour->setSteeringForce(50);
    addComponent(seekBehaviour);
}

bool Enemy::getTargetInRange()
{
    float distance = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();
    return distance <= 300;
};
