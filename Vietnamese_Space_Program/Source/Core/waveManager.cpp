/*

#include "../../Include/Core/WaveManager.h"
#include <iostream>

WaveManager::WaveManager() {
    enemyCount = 0;
    waveNum = 1;
    waveDone = false;
    inWave = false;
}

void WaveManager::spawnWave(sf::RenderWindow *window, EntityManager *manager, Player *player) {
    manager->updateEntity(window);

    if(!this->isInWave())
    {
        for (int i = 0; i < 10; i++) { //this->enemyCount; this->enemyCount < this->waveNum * this->MAX_ENEMY; this->enemyCount++
            manager->addEntity("Enemy", new EnemyObject(player));
            this->enemyCount++;
        }
        this->setInWave(true);
    }

    std::cout << "enemyCount: " << this->getEnemyCount() << std::endl;
    if (enemyCount < 0) {
        this->setWaveDone(true);
        this->setEnemyCount(0);
        this->setInWave(false);
    }
}

//Getters and setters

int WaveManager::getEnemyCount() const {
    return enemyCount;
}

void WaveManager::setEnemyCount(int enemyCount) {
    this->enemyCount = enemyCount;
}


void WaveManager::incrementEnemyCount() {
    this->enemyCount += 1;
}

void WaveManager::decrementEnemyCount() {
    this->enemyCount -= 1;
}

void WaveManager::incrementWaveNum() {
    this->waveNum += 1;
}

void WaveManager::setWaveNum(int waveNum) {
    this->waveNum = waveNum;
}

bool WaveManager::isWaveDone() const {
    return waveDone;
}

void WaveManager::setWaveDone(bool waveDone) {
    this->waveDone = waveDone;
}

bool WaveManager::isInWave() const {
    return inWave;
}

void WaveManager::setInWave(bool inWave) {
    WaveManager::inWave = inWave;
}

*/