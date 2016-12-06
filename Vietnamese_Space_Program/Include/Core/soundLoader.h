#ifndef VIETNAMESE_SPACE_PROGRAM_SOUNDLOADER_H
#define VIETNAMESE_SPACE_PROGRAM_SOUNDLOADER_H

#include "SFML/Audio.hpp"
#include <map>
#include <vector>
#include <iostream>

class SoundLoader
{
public:
    enum SoundNames{MAIN_MENU, ARCADE, SHOOT};
    SoundLoader();
    ~SoundLoader();

    void loadSounds();
    void playSound(SoundNames soundName);
    void playMusic(SoundNames soundNames);
private:
    std::map<SoundNames, sf::SoundBuffer> Sounds;
    std::vector<sf::Sound> playingSounds;
};

#endif //VIETNAMESE_SPACE_PROGRAM_SOUNDLOADER_H
