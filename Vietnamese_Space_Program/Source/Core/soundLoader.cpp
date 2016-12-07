#include "../../Include/Core/soundLoader.h"

SoundLoader::SoundLoader() {
    volume = 100;
}

SoundLoader::~SoundLoader() {
}

void SoundLoader::loadSounds() {
    //Music
    Sounds[SoundNames::MAIN_MENU].loadFromFile("Audio/Music/menu.ogg");
    Sounds[SoundNames::ARCADE].loadFromFile("Audio/Music/arcade.ogg");

    //SFX
    Sounds[SoundNames::PLAYER_SHOOT].loadFromFile("Audio/SFX/missileLaunch.ogg");
    Sounds[SoundNames::ENEMY_SHOOT].loadFromFile("Audio/SFX/pop.ogg");
    Sounds[SoundNames::BULLET_POP].loadFromFile("Audio/SFX/explosion.ogg");
    Sounds[SoundNames::REPAIR].loadFromFile("Audio/SFX/repair.ogg");

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
            playingSounds.at(playingSounds.size() - 1).setVolume(volume);
            playingSounds.at(playingSounds.size() - 1).setBuffer(Sounds[soundName]);
            playingSounds.at(playingSounds.size() - 1).play();
        }

    }
}

void SoundLoader::playMusic(SoundNames soundName){}

void SoundLoader::muteMusic(bool mute){

}

void SoundLoader::muteAudio(bool mute){
    if(mute) volume = 0;
    else volume = 100;
}