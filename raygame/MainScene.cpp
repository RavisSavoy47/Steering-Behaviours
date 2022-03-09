#include "MainScene.h"
#include "Player.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"
#include "FleeBehaviour.h"

void MainScene::start()
{
    Player* player = new Player(50, 50, "Player");
    player->getTransform()->setScale({ 50, 50 });
    player->addComponent(new SpriteComponent("Images/player.png"));
    addActor(player);

    Agent* ai = new Agent(player, 100, 100, "Enemy");
    ai->getTransform()->setScale({ 50,50 });
    ai->addComponent(new SpriteComponent("Images/enemy.png"));
    WanderBehaviour* comp = new WanderBehaviour(100, 70, 500);
    //comp->setTarget(player);
    ai->setMaxForce(1000);
    //comp->setSteeringForce(100);
    ai->addComponent(comp);
    addActor(ai);
}