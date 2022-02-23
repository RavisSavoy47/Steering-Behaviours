#include "MainScene.h"
#include "Player.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Agent.h"

void MainScene::start()
{
    Player* player = new Player(50, 50, "Player");
    player->getTransform()->setScale({ 50, 50 });
    addActor(player);

    Agent* ai = new Agent(player, 100, 100, "Enemy");
    ai->getTransform()->setScale({ 50,50 });
    addActor(ai);
}