#include <iostream>
#include "../../Include/Core/entityManager.h"


/**
 *
 * Når du lager en ny entity må du definere gruppe ID til entitien.
 *
 * Player       GroupID = 1
 * Bullet       GroupID = 2
 * I-Object     GroupID = 3
 * Enemies      GroupID = 4
 * Boss         GroupID = 5
 *
 *
 * @return
 */


EntityManager::EntityManager() {

}

void EntityManager::addEntity(std::string name, Entity *entity) {
    // uordnet map iterator, denne skal brukes for å lete gjennom alle våre entities.
    std::unordered_map<std::string, Entity *>::const_iterator found = this->entities.find(name);

    //Hvis vi finner entities altså at listen ikke er tom så setter den et "0" bak navnet, dette er praktisk visst vi kaller våre entities for det samme navnet.
    //Dette forhindrer problemer når vi kaller entitiene samme navn, for eks enemy.
    while (found != this->entities.end()) {
        name += "0";
        found = this->entities.find(name);

    }
    //Hvis navnet på entityen er unik så blir de pairet sammen vår entity.
    this->entities.insert(std::make_pair(name, entity));
}

Entity *EntityManager::getEntity(std::string name) {
    std::unordered_map<std::string, Entity *>::const_iterator found = this->entities.find(name);

    if (found == this->entities.end()) {
        return NULL;
    } else {
        return found->second;
    }
}

void EntityManager::updateEntity(sf::RenderWindow *window, float* deltaTime) {
    if(deltaTime != nullptr){
        this->deltaTime = deltaTime;
    }
    std::vector<std::string> toRemove;
    //Denne går gjennom våre enteties og får typen vår entity er, og oppdaterer våre entities.
    for (auto iterator = this->entities.begin(); iterator != this->entities.end(); iterator++) {
        for (auto iterator2 = iterator; iterator2 != this->entities.end(); iterator2++) {
            if (iterator->first != iterator2->first) {
                if (iterator->second->checkCollision(iterator2->second)) {
                    iterator->second->collision(iterator2->second);
                    iterator2->second->collision(iterator->second);
                }
            }
        }

        switch (iterator->second->activeEntity()) {
            case 0:
                toRemove.push_back(iterator->first);
                break;
            default:
                iterator->second->updateEntity(window);
                break;
        }

    }
    for (auto &iterator : toRemove) {
        std::unordered_map<std::string, Entity *>::const_iterator found = this->entities.find(iterator);

        if (found != this->entities.end()) {
            delete found->second;
            this->entities.erase(iterator);
        }
    }
    toRemove.clear();
}

void EntityManager::renderEntity(sf::RenderWindow *window) {
    //Dette tegner alle våre entities
    for (auto &iterator : this->entities) {
        window->draw(*iterator.second);
    }
}

EntityManager::~EntityManager() {
    for (auto &iterator : this->entities) {
        delete iterator.second;
    }
    this->entities.clear();
}

std::vector<Entity*> EntityManager::getEntities(int groupID) {




}