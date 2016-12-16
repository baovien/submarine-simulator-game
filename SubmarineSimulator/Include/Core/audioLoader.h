#ifndef SUBMARINESIMULATORSOUNDLOADER_H
#define SUBMARINESIMULATORSOUNDLOADER_H

#include "SFML/Audio.hpp"
#include "utilities.h"
#include <map>
#include <list>
#include <iostream>

namespace Audio{
    enum Effect
    {
        PLAYER_SHOOT1,
        PLAYER_SHOOT2,
        ENEMY_SHOOT,
        BULLET_POP,
        REPAIR,
        WAVEDONE,
        OVERHEAT,
        BOSSWAVE,
        NEXTWAVE,
        SHIELD
    };

    enum Music
    {
        MAIN_MENU,
        ARCADE,
        GAMEOVER,
        CLASSIC
    };
}

class AudioLoader
{
public:
    virtual ~AudioLoader();

public:
    AudioLoader();

    //Effects
    void playEffect(Audio::Effect soundName);
    void removeStoppedEffects();
    //Music
    void playMusic(Audio::Music soundName);
    void stopMusic();

    void updateSounds();
    void initSoundPointers(bool *muted, bool *mutedMusic);

private:
    bool* muted;
    bool* mutedMusic;

    //Effects
    std::map<Audio::Effect, sf::SoundBuffer> buffers;
    std::list<sf::Sound> sounds;
    int effectsVolume;

    //Music
    sf::Music music;
    std::map<Audio::Music, std::string> musicPath;
    int musicVolume;

};

#endif //SUBMARINESIMULATORSOUNDLOADER_H
