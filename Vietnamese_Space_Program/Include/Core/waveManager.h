/*
#ifndef VIETNAMESE_SPACE_PROGRAM_ENEMYSPAWN_H
#define VIETNAMESE_SPACE_PROGRAM_ENEMYSPAWN_H

#include "../Entities/enemy.h"
#include "../Entities/player.h"

class WaveManager
{
public:

    WaveManager();
    void spawnWave(sf::RenderWindow* window, EntityManager* manager, Player* player);

    int getEnemyCount() const;
    void setEnemyCount(int enemyCount);
    void incrementEnemyCount();
    void decrementEnemyCount();

    void incrementWaveNum();
    void setWaveNum(int waveNum);

    bool isWaveDone() const;
    void setWaveDone(bool waveDone);

    bool isInWave() const;

    void setInWave(bool inWave);

    int enemyCount;
    int waveNum;
    bool waveDone;
    bool inWave;
    int MAX_ENEMY = 4;

};

#endif //VIETNAMESE_SPACE_PROGRAM_ENEMYSPAWN_H
*/
