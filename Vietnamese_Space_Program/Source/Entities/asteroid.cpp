#include "../../Include/Entities/asteroid.h"

//Initiater asteroid, koden vår er satt opp for flere spillere så case 0 er spiller 1.
AsteroidObject::AsteroidObject(float x, float y)
{
    this->load("Assteroids_brown.png");
    //Scaler opp bildet for å slippe å lage nytt
    this->setScale(2,2);
    this->active = 1;
    this->groupId = 3;
    //Setter origin til midten av astroiden. Må dele på 4 istedenfor 2 pga scalinga
    this->setOrigin(this->getGlobalBounds().height/4, this->getGlobalBounds().height/4);
    //setter en absolutt rotasjon
    this->setRotation(2);

    //Spawner astroides utenfor skjermen slik at det skal se ut som om de kommer fra intet.
    //Gjør også at en astroide ikke kan streife skjermen såvidt men må gå over større deler av skjermen.

    //Spawner tilfeldig fra venstre del av skjermen
    if (randomNumber == 1) {
        this->setPosition(-50, rand() % 600+60);
        if(this->getPosition().y>500)
        {
            this->velocity.x = 3;
            this->velocity.y = rand()%3-4;
        }
        else if(this->getPosition().y<160)
        {
            this->velocity.x = 3;
            this->velocity.y = rand()%3;
        }
        else
        {
            this->velocity.x = 3;
            this->velocity.y = rand() % 4-2;
        }
    }
        //Spawner tilfeldig fra høyre del av skjermen
    else if (randomNumber == 2)
    {
        this->setPosition(1330, rand() % 600+60);
        if(this->getPosition().y > 500)
        {
            this->velocity.x = -3;
            this->velocity.y = rand()%3-4;
        }
        else if(this->getPosition().y < 160)
        {
            this->velocity.x = -3;
            this->velocity.y = rand()%3;
        }
        else
        {
            this->velocity.x = -3;
            this->velocity.y = rand()%4-2;
        }
    }
        //Spawner tilfeldig fra øverst del av skjermen
    else if (randomNumber == 3)
    {
        this->setPosition(rand() % 1160+60, -50);
        if(this->getPosition().x>800)
        {
            this->velocity.y = 3;
            this->velocity.x = rand()% 3-4;
        }
        else if(this->getPosition().x<420)
        {
            this->velocity.y = 3;
            this->velocity.x = rand()%3;
        }
        else
        {
            this->velocity.y = 3;
            this->velocity.x = rand()%4-2;
        }
    }
        //Spawner tilfeldig fra nederste del av skjermen
    else
    {
        this->setPosition(rand() % 1160+60, 770);
        if(this->getPosition().x>800)
        {
            this->velocity.y = -3;
            this->velocity.x = rand()%3-4;
        }
        if(this->getPosition().x<420)
        {
            this->velocity.y = -3;
            this->velocity.x = rand()%3;
        }
        else
        {
            this->velocity.y = -3;
            this->velocity.x = rand()%4-2;
        }
    }
}

//update funksjonen har kontroll på bevegelsen til player.
void AsteroidObject::updateEntity(sf::RenderWindow *window)
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

void AsteroidObject::collision(Entity* entity)
{

}