#ifndef VIETNAMESE_SPACE_PROGRAM_SOUNDLOADER_H
#define VIETNAMESE_SPACE_PROGRAM_SOUNDLOADER_H

#include "SFML/Audio.hpp"
#include <map>
#include <vector>
#include <iostream>

class SoundLoader : private sf::NonCopyable
{
public:
    enum SoundNames{MAIN_MENU, ARCADE, PLAYER_SHOOT, ENEMY_SHOOT, BULLET_POP, REPAIR};
    SoundLoader();
    ~SoundLoader();

    void loadSounds();
    void playSound(SoundNames soundName);
    void stopSound();
    void playMusic(SoundNames soundName);

    void muteMusic(bool mute);
    void muteAudio(bool mute);
private:
    std::map<SoundNames, sf::SoundBuffer> Sounds;
    std::vector<sf::Sound> playingSounds;
    int volume;
};

#endif //VIETNAMESE_SPACE_PROGRAM_SOUNDLOADER_H
