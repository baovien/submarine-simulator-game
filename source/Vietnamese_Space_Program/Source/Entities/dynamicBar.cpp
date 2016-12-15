#include "../../Include/Entities/dynamicBar.h"

/**
 * Overheat bar's constructor
 * @param window
 * @return
 */
Bar::Bar(sf::RenderWindow *window)
{
    this->load("overheat.png");
    this->setOrigin(this->getGlobalBounds().width / 2.f, this->getGlobalBounds().height / 2.f);
    this->setPosition(window->getSize().x / 2.f, window->getSize().y - this->getGlobalBounds().height);
    this->setTextureRect(sf::IntRect(0, 0, 12, 20));
    this->setScale(window->getSize().x / 640.f, window->getSize().y / 360.f);
}

/**
 * Boss' health bar's constructor.
 * @param window
 * @param x - x start position
 * @param y - y start position
 * @return
 */
Bar::Bar(sf::RenderWindow *window, float x, float y, float bossHP)
{
    this->load("overheat.png");
    this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
    this->setPosition(x, y);
    this->HP = bossHP; //Faktiske HP til boss
    this->bossHP = 120/bossHP; //decrement for HP baren
    this->setScale(window->getSize().x / 1280.f, window->getSize().y / 720.f);
    this->setTextureRect(sf::IntRect(0, 0, window->getSize().x * 120.f / 1280.f, window->getSize().y * 20.f / 720.f));
}

/**
 * Updates the overheat bar's current progress.
 * @param window
 * @param overHeatValue - Current overheat value.
 */
void Bar::updateEntity(sf::RenderWindow *window, float overHeatValue)
{
    this->overheatcheck = overHeatValue;
    if (overheatcheck >= 10)overheatcheck = 10.3;
    this->setTextureRect(sf::IntRect(0, 0, 12 * overheatcheck, 20));
    Entity::updateEntity(window);
}

/**
 * Updates the boss' health bar's current progress.
 * @param window
 * @param healthValue - Current health of the boss.
 * @param x - Position x
 * @param y - Position y
 */
void Bar::updateEntity2(sf::RenderWindow *window, float healthValue, float x, float y)
{
    if (healthValue == 0)this->destroyEntity();
    this->overheatcheck = HP - healthValue;
    this->setPosition(x, y);
    this->setTextureRect(sf::IntRect(0.0f, 0.0f, 120.f - (this->bossHP * overheatcheck), 20.f));
    Entity::updateEntity(window);
}