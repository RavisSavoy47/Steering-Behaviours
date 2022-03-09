#include "MainScene.h"
#include "Player.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"
#include "FleeBehaviour.h"
#include "StateMachineComponent.h"

void MainScene::start()
{
    Player* player = new Player(50, 50, "Player");
    player->getTransform()->setScale({ 50, 50 });
    player->addComponent(new SpriteComponent("Images/player.png"));
    addActor(player);

    Agent* ai = new Agent(player, 100, 100, "Enemy");
    ai->getTransform()->setScale({ 50,50 });
    ai->addComponent(new SpriteComponent("Images/enemy.png"));
    ai->setMaxForce(200);

    WanderBehaviour* wanderBehaviour = new WanderBehaviour(100, 150, 100);
    ai->addComponent(wanderBehaviour);

    SeekBehaviour* seekBehaviour = new SeekBehaviour();
    seekBehaviour->setTarget(player);
    ai->addComponent(seekBehaviour);
    seekBehaviour->setSteeringForce(50);
    ai->addComponent<StateMachineComponent>();
    addActor(ai);
}