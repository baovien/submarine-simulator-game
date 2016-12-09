/*******************************************
 * Alle states har soundloaderen under machine (machine->soundLoaderPeker).
 * For å få lyd til et objekt, f.eks healthPack, må det dependencyinjectes inn.
 * 1. Det gjøres ved å include soundLoader.h i objektets header og lage en peker SoundLoader* soundloader.
 * 2. Deretter tas healthpack konstruktøren inn pekeren. Skriv så this->soundLoader = soundloader
 *    eller soundLoader(soundLoader) etter konstruktøren.
 * 3. Nå kan du bruke this->soundLoader til å kalle en lyd i ønsket klasse.
 *
 * /////Legge til musikk
 *
 *       Legg til en ny enum i headerfilen, deretter skriv følgende i konstruktøren:
 *       musicPath[Audio::Music::NAVN_PÅ_MUSIKK] = ("PATH_TIL_MUSIKK");
 *
 * /////Spille av musikk
 *
 *      kall
 *
 * /////Legge til lyd
 *
 *      Legg til en ny enum i headerfilen, deretter skriv følgende i konstruktøren:
 *      buffers[Audio::NAVN_PÅ_LYDEFFEKT].loadFromFile("PATH_TIL_LYDEFFEKT");
 *
 * /////Spille av en lyd (DEPENDENCY INJECT)
 *
 *      Kall funksjonen under
 *      soundLoader->playEffect(Audio::NAVN_PÅ_LYDEFFEKT)
 *
 *******************************************/

#include "../../Include/Core/soundLoader.h"

SoundLoader::SoundLoader() {
    effectsVolume = 30;
    musicVolume = 20;

    //Music
    musicPath[Audio::Music::MAIN_MENU] = ("Audio/Music/menu.ogg");
    musicPath[Audio::Music::ARCADE] = ("Audio/Music/arcade.ogg");
    musicPath[Audio::Music::GAMEOVER] = ("Audio/Music/gameover.ogg");
    musicPath[Audio::Music::CLASSIC] = ("Audio/Music/gameover.ogg");

    //SFX
    buffers[Audio::Effect::PLAYER_SHOOT].loadFromFile("Audio/SFX/missileLaunch.ogg");
    buffers[Audio::Effect::ENEMY_SHOOT].loadFromFile("Audio/SFX/pop.ogg");
    buffers[Audio::Effect::BULLET_POP].loadFromFile("Audio/SFX/explosion.ogg");
    buffers[Audio::Effect::REPAIR].loadFromFile("Audio/SFX/repair.ogg");
    buffers[Audio::Effect::WAVEDONE].loadFromFile("Audio/SFX/wavedone.wav");
    buffers[Audio::Effect::OVERHEAT].loadFromFile("Audio/SFX/overheat.wav");
}

void SoundLoader::playEffect(Audio::Effect effect) {
    if (!*muted) {
        this->sounds.push_back(sf::Sound());
        sf::Sound &sound = sounds.back();

        sound.setBuffer(buffers[effect]);
        sound.setVolume(effectsVolume);
        sound.play();
    }
}

void SoundLoader::playMusic(Audio::Music music) {

    if(this->music.getStatus() != this->music.Playing){
        if (this->music.openFromFile(musicPath[music])) {
            this->music.setVolume(this->musicVolume);
            this->music.setLoop(true);
        }
    }

}

void SoundLoader::checkMuteMusic() {
    if (*muted || *mutedMusic) {
        this->music.pause();
    } else if (this->music.getStatus() == this->music.Paused || this->music.getStatus() == this->music.Stopped) {
        this->music.play();
    }
}

/**
 * Henter mutedPointer og mutedMusicPointer fra machine
 * @param muted
 * @param mutedMusic
 */
void SoundLoader::initSoundPointers(bool *muted, bool *mutedMusic) {
    this->muted = muted;
    this->mutedMusic = mutedMusic;
}

void SoundLoader::stopMusic() {
    this->music.stop();
}
