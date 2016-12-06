#include "../../Include/Core/soundLoader.h"

SoundLoader::SoundLoader() {
    Sounds[SoundNames::MAIN_MENU].loadFromFile("Audio/Music/menu.ogg");
    Sounds[SoundNames::ARCADE].loadFromFile("Audio/Music/arcade.ogg");
    Sounds[SoundNames::SHOOT].loadFromFile("Audio/SFX/shoot5.ogg");
}

SoundLoader::~SoundLoader() {
    Sounds.clear();
    playingSounds.clear();
}

void SoundLoader::loadSounds() {


}

void SoundLoader::playSound(SoundNames soundName)
{
    if (playingSounds.size() == 0)
    {
        playingSounds.push_back(sf::Sound());
        playingSounds.at(0).setBuffer(Sounds[soundName]);
        playingSounds.at(0).play();
    }
    else
    {
        int location = -1;
        for (int i = 0; i < playingSounds.size(); i++)
        {
            if (playingSounds.at(i).getStatus() != sf::Sound::Playing && location == -1)
            {
                location = i;
            }
        }

        if (location != -1)
        {
            playingSounds.at(location).setBuffer(Sounds[soundName]);
            playingSounds.at(location).play();
        }
        else
        {
            playingSounds.push_back(sf::Sound());
            playingSounds.at(playingSounds.size() - 1).setBuffer(Sounds[soundName]);
            playingSounds.at(playingSounds.size() - 1).play();
        }

    }
}