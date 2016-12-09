#ifndef VIETNAMESE_SPACE_PROGRAM_SOUNDLOADER_H
#define VIETNAMESE_SPACE_PROGRAM_SOUNDLOADER_H

#include "SFML/Audio.hpp"
#include "utilities.h"
#include <map>
#include <list>
#include <iostream>

namespace Audio{
    enum Effect
    {
        PLAYER_SHOOT,
        ENEMY_SHOOT,
        BULLET_POP,
        REPAIR,
        WAVEDONE,
        OVERHEAT
    };

    enum Music
    {
        MAIN_MENU,
        ARCADE,
        GAMEOVER,
        CLASSIC
    };
}

class SoundLoader : sf::NonCopyable
{
public:
    SoundLoader();

    //Effects
    void playEffect(Audio::Effect soundName);

    //Music
    void playMusic(Audio::Music soundName);
    void stopMusic();

    void checkMuteMusic();
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

#endif //VIETNAMESE_SPACE_PROGRAM_SOUNDLOADER_H
