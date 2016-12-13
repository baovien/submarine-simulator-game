#include <iostream>
#include "../../Include/Entities/indestructableObject.h"

//Initiater objektet, koden vår er satt opp for flere spillere så case 0 er spiller 1.
IndestructableObject::IndestructableObject(float x, float y, float directionX, float directionY, float angle, sf::RenderWindow* window)
{
    this->load("asteroid.png");
    //Scaler opp bildet for å slippe å lage nytt

    this->active = 1;
    this->groupId = 3;
    this->health = 1;
    this->maxSpeed = 100.0f;
    //Setter origin til midten av astroiden.
    this->setOrigin(this->getGlobalBounds().width/2.f, this->getGlobalBounds().height/2.f);
    this->setScale(window->getSize().x/1280.f, window->getSize().y/720.f);

    this->setPosition(x,y);
    this->velocity.x = directionX * 100.f;
    this->velocity.y = directionY * 100.f;
    this->setRotation(angle);
}

IndestructableObject::IndestructableObject(sf::RenderWindow* window, int theme) {
    if(theme == 0)
    {
        this->random = rand() % 2;
        if (random == 0)this->load("tincan.png");
        else this->load("tincan2.png");
        this->setOrigin(this->getGlobalBounds().width/1.5f, this->getGlobalBounds().height/2.f);
        this->setScale(window->getSize().x/2560.f,window->getSize().y/1440.f); //skaleres til 0.5, 0.5
    }
    else{
        this->random = rand() % 2;
        if (random == 0)this->load("asteroid.png");
        else this->load("gold.png");
        this->setOrigin(this->getGlobalBounds().width/2.f, this->getGlobalBounds().height/2.f);
        this->setScale(window->getSize().x/1280.f,window->getSize().y/720.f); //skaleres til 0.5, 0.5
    }
    this->theme = theme;
    this->active = 1;
    this->groupId = 9;
    this->health = 1;
    this->randomNumber = rand()%4;
    this->maxSpeed = 125.f;

    //Setter en absolutt rotasjon
    this->setRotation(2);

    //Spawner astroides utenfor skjermen slik at det skal se ut som om de kommer fra intet.
    //Gjør også at en astroide ikke kan streife skjermen såvidt men må gå over større deler av skjermen.

    //Spawner tilfeldig fra venstre del av skjermen
    if (randomNumber == 1) {
        this->setPosition(-this->getGlobalBounds().width, rand() % window->getSize().y);
        if(this->getPosition().y > window->getSize().y/1.5f) {
            this->velocity.x = maxSpeed;
            this->velocity.y = rand()%125-92;
        }
        else if(this->getPosition().y < window->getSize().y/3.f) {
            this->velocity.x = maxSpeed;
            this->velocity.y = rand()%125;
        }
        else {
            this->velocity.x = maxSpeed;
            this->velocity.y = rand() % 125-63;
        }
    }
        //Spawner tilfeldig fra høyre del av skjermen
    else if (randomNumber == 2) {
        this->setPosition(window->getSize().x + this->getGlobalBounds().width, rand() % window->getSize().y + this->getGlobalBounds().height);
        if(this->getPosition().y > window->getSize().y/1.5f) {
            this->velocity.x = -maxSpeed;
            this->velocity.y = rand()%92-125;
        }
        else if(this->getPosition().y < window->getSize().y/3.f) {
            this->velocity.x = -maxSpeed;
            this->velocity.y = rand()%125;
        }
        else {
            this->velocity.x = -maxSpeed;
            this->velocity.y = rand()%125-63;
        }
    }
    //Spawner tilfeldig fra øverst del av skjermen
    else if (randomNumber == 3) {
        this->setPosition(rand() % window->getSize().x + this->getGlobalBounds().width, -this->getGlobalBounds().height);
        if(this->getPosition().x > window->getSize().x/1.5f) {
            this->velocity.y = maxSpeed;
            this->velocity.x = rand()% 92-125;
        }
        else if(this->getPosition().x < window->getSize().x/3.f) {
            this->velocity.y = maxSpeed;
            this->velocity.x = rand()%125;
        }
        else {
            this->velocity.y = maxSpeed;
            this->velocity.x = rand()%125-92;
        }
    }
    //Spawner tilfeldig fra nederste del av skjermen
    else {
        this->setPosition(rand() % window->getSize().x + this->getGlobalBounds().width, window->getSize().y + this->getGlobalBounds().height);
        if(this->getPosition().x > window->getSize().x/1.5f) {
            this->velocity.y = -maxSpeed;
            this->velocity.x = rand()%92-125;
        }
        if(this->getPosition().x < window->getSize().x/3.f) {
            this->velocity.y = -maxSpeed;
            this->velocity.x = rand()%125;
        }
        else {
            this->velocity.y = -maxSpeed;
            this->velocity.x = rand()%125-63;
        }
    }
}

//update funksjonen har kontroll på bevegelsen til player.
void IndestructableObject::updateEntity(sf::RenderWindow *window) {
    //roterer objektet relativ til dens nåværende posisjon rundt sentrum
    this->rotate(2);
    //Sletter objektet fra mappen i entitymanager hvis den går ut av skjermen
    if(this->getPosition().x <= -this->getGlobalBounds().width * 2 ||
            this->getPosition().x >= window->getSize().x + this->getGlobalBounds().width * 2 ||
            this->getPosition().y <=-this->getGlobalBounds().height * 2 ||
            this->getPosition().y >=window->getSize().y + this->getGlobalBounds().height * 2){

                 this->destroyEntity();
    }
    Entity::updateEntity(window);
}

void IndestructableObject::collision(Entity* entity) {
    switch (entity->groupID()) {
        case 4: // Enemy
            break;
        case 9:
            break;
        default:break;
    }
}