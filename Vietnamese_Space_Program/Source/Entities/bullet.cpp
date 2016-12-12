#include "../../Include/Entities/bullet.h"
#include <iostream>

Bullet::Bullet(Score* score, float x, float y, float direction, float direction2, float angle, SoundLoader* soundLoader, sf::RenderWindow* window)
        : soundLoader(soundLoader)
{
    this->active = 1;
    this->groupId = 2;
    this->load("missile.png");
    this->velocity.y = direction * 640;
    this->velocity.x = direction2 * 640;
    this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);
    this->setPosition(x, y);
    this->setRotation(angle);
    this->score = score;
    this->setScale(window->getSize().x/3840.0f, window->getSize().y/2160.0f);


}
Bullet::Bullet(float x, float y, float direction, float direction2, float angle , sf::RenderWindow* window)
{
    this->active = 1;
    this->groupId = 6;
    this->load("bubble4.png");
    this->velocity.y = direction * 640;
    this->velocity.x = direction2 * 640;
    this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);
    this->setPosition(x, y);
    this->setRotation(angle);
    this->setScale(window->getSize().x/3840.0f, window->getSize().y/2160.0f);
}
void Bullet::updateEntity(sf::RenderWindow *window)
{
        if (this->getPosition().x + this->getGlobalBounds().width / 2 < 0 ||
            this->getPosition().x - this->getGlobalBounds().width / 2 > window->getSize().x ||
            this->getPosition().y + this->getGlobalBounds().height / 2 < 0 ||
            this->getPosition().y - this->getGlobalBounds().height / 2 > window->getSize().y) {
            this->destroyEntity();
    }
    Entity::updateEntity(window);
}

void Bullet::collision(Entity *entity) {
    if (this->groupId == 2) {

        switch (entity->groupID()) {
            case 3: // IndestructableObject nr 1
                this->destroyEntity();
                this->soundLoader->playEffect(Audio::BULLET_POP);
                break;

            case 4: // Enemy
                this->destroyEntity();
                this->score->incrementScore();
                this->soundLoader->playEffect(Audio::BULLET_POP);
                break;

            case 5: // Boss
                this->destroyEntity();
                this->score->incrementScore();
                this->soundLoader->playEffect(Audio::BULLET_POP);
                break;

            case 9: // IndestructableObject nr 2
                this->destroyEntity();
                this->soundLoader->playEffect(Audio::BULLET_POP);
                break;

            default:
                break;
        }
    }
}





