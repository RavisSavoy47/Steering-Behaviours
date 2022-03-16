#include "MainScene.h"
#include "Player.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "Enemy.h"

void MainScene::start()
{
    Player* player = new Player(50, 50, "Player");
    player->getTransform()->setScale({ 50, 50 });
    player->addComponent(new SpriteComponent("Images/player.png"));
    addActor(player);

    Enemy* enemy = new Enemy(100, 100, "Enemy", 100, 100, player);

    addActor(enemy);
}