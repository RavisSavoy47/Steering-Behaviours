#include "MainScene.h"
#include "Player.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "SeekBehaviour.h"

void MainScene::start()
{
    Player* player = new Player(50, 50, "Player");
    player->getTransform()->setScale({ 50, 50 });
    player->addComponent(new SpriteComponent("Images/player.png"));
    addActor(player);

    Agent* ai = new Agent(player, 100, 100, "Enemy");
    ai->getTransform()->setScale({ 50,50 });
    ai->addComponent(new SpriteComponent("Images/enemy.png"));
    ai->setMaxForce(500);
    SeekBehaviour* comp = new SeekBehaviour();
    comp->setTarget(player);
    ai->addComponent(comp);
    addActor(ai);
}