#include "../../Include/Entities/indestructableObject.h"

//Initiater objektet, koden vår er satt opp for flere spillere så case 0 er spiller 1.
IndestructableObject::IndestructableObject(float x, float y, float directionX, float directionY, float angle)
{
    this->load("asteroid.png");
    //Scaler opp bildet for å slippe å lage nytt

    this->active = 1;
    this->groupId = 3;
    this->health = 1;
    this->maxSpeed = 1.5f;
    //Setter origin til midten av astroiden.
    this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);

    //setter en absolutt rotasjon
    this->setRotation(2);

    this->setPosition(x,y);
    this->velocity.x = directionX;
    this->velocity.y = directionY;
    this->setRotation(angle);
}

IndestructableObject::IndestructableObject() {
    int randomNumber = rand() % 2;
    if(randomNumber == 0)this->load("tincan.png");
    else this->load("tincan2.png");

    this->active = 1;
    this->groupId = 9;
    this->health = 1;
    this->randomNumber = rand()%4;
    this->maxSpeed = 1.5f;
    this->setScale(0.5,0.5);

    //Setter origin til midten av asteroiden.
    this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);

    //Setter en absolutt rotasjon
    this->setRotation(2);

    //Spawner astroides utenfor skjermen slik at det skal se ut som om de kommer fra intet.
    //Gjør også at en astroide ikke kan streife skjermen såvidt men må gå over større deler av skjermen.

    //Spawner tilfeldig fra venstre del av skjermen
    if (randomNumber == 1) {
        this->setPosition(-50, rand() % 600+60);
        if(this->getPosition().y>500)
        {
            this->velocity.x = maxSpeed;
            this->velocity.y = rand()%3-4;
        }
        else if(this->getPosition().y<160)
        {
            this->velocity.x = maxSpeed;
            this->velocity.y = rand()%3;
        }
        else
        {
            this->velocity.x = maxSpeed;
            this->velocity.y = rand() % 4-2;
        }
    }
        //Spawner tilfeldig fra høyre del av skjermen
    else if (randomNumber == 2)
    {
        this->setPosition(1330, rand() % 600+60);
        if(this->getPosition().y > 500)
        {
            this->velocity.x = -maxSpeed;
            this->velocity.y = rand()%3-4;
        }
        else if(this->getPosition().y < 160)
        {
            this->velocity.x = -maxSpeed;
            this->velocity.y = rand()%3;
        }
        else
        {
            this->velocity.x = -maxSpeed;
            this->velocity.y = rand()%4-2;
        }
    }
        //Spawner tilfeldig fra øverst del av skjermen
    else if (randomNumber == 3)
    {
        this->setPosition(rand() % 1160+60, -50);
        if(this->getPosition().x>800)
        {
            this->velocity.y = maxSpeed;
            this->velocity.x = rand()% 3-4;
        }
        else if(this->getPosition().x<420)
        {
            this->velocity.y = maxSpeed;
            this->velocity.x = rand()%3;
        }
        else
        {
            this->velocity.y = maxSpeed;
            this->velocity.x = rand()%4-2;
        }
    }
        //Spawner tilfeldig fra nederste del av skjermen
    else
    {
        this->setPosition(rand() % 1160+60, 770);
        if(this->getPosition().x>800)
        {
            this->velocity.y = -maxSpeed;
            this->velocity.x = rand()%3-4;
        }
        if(this->getPosition().x<420)
        {
            this->velocity.y = -maxSpeed;
            this->velocity.x = rand()%3;
        }
        else
        {
            this->velocity.y = -maxSpeed;
            this->velocity.x = rand()%4-2;
        }
    }
}

//update funksjonen har kontroll på bevegelsen til player.
void IndestructableObject::updateEntity(sf::RenderWindow *window)
{
    //roterer objektet relativ til dens nåværende posisjon rundt sentrum
    this->rotate(2);
    //Sletter objektet fra mappen i entitymanager hvis den går ut av skjermen
    if(this->getPosition().x <= -200 || this->getPosition().x >= 1400 || this->getPosition().y <=-200 ||this->getPosition().y >=850)
    {
        this->destroyEntity();
    }

    Entity::updateEntity(window);
}

void IndestructableObject::collision(Entity* entity) {
    switch (entity->groupID()) {
        case 4: // Enemy
            entity->destroyEntity();
            break;
        case 3:
        case 9:
            break;
    }
}