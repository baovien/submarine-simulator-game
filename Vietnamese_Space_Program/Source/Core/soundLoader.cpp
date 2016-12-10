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
 *      I konstruktøren til en state, skriv
 *      machine->soundLoaderPeker.stopMusic();          //Må stoppe musikken for å kunne starte ny musikk
 *      machine->soundLoaderPeker.playMusic(Audio::Music::NAVN_PÅ_MUSIKK);
 *
 *      I updaten til en state skriv
 *      machine->soundLoaderPeker.updateSounds();
 *
 *      Alle steder i staten der det byttes til en ny state, skriv
 *      machine->soundLoaderPeker.stopMusic();
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
    effectsVolume = 50;
    musicVolume = 50;

    //Music
    musicPath[Audio::Music::MAIN_MENU] = ("Audio/Music/menu.ogg");
    musicPath[Audio::Music::ARCADE] = ("Audio/Music/arcade.ogg");
    musicPath[Audio::Music::GAMEOVER] = ("Audio/Music/gameover.ogg");
    musicPath[Audio::Music::CLASSIC] = ("Audio/Music/classic.ogg");

    //SFX
    buffers[Audio::Effect::PLAYER_SHOOT].loadFromFile("Audio/SFX/missileLaunch.ogg");
    buffers[Audio::Effect::ENEMY_SHOOT].loadFromFile("Audio/SFX/pop.ogg");
    buffers[Audio::Effect::BULLET_POP].loadFromFile("Audio/SFX/explosion.ogg");
    buffers[Audio::Effect::REPAIR].loadFromFile("Audio/SFX/repair.ogg");
    buffers[Audio::Effect::WAVEDONE].loadFromFile("Audio/SFX/wavedone.wav");
    buffers[Audio::Effect::OVERHEAT].loadFromFile("Audio/SFX/overheat.wav");
}

/**
 *
 * @param effect
 */
void SoundLoader::playEffect(Audio::Effect effect) {
    if (!*muted) {
        this->sounds.push_back(sf::Sound());
        sf::Sound &sound = sounds.back();

        sound.setBuffer(buffers[effect]);
        sound.setVolume(effectsVolume);
        sound.play();
    }
}
/**
 * Fjerner effects som har blitt spilt av og stoppet i listen sounds.
 * Kalles i updateSounds()
 */
void SoundLoader::removeStoppedEffects(){
    sounds.remove_if([](const sf::Sound& s){
        return s.getStatus() == sf::Sound::Stopped;
    });
}

/**
 * Sjekker om det
 * @param music
 */
void SoundLoader::playMusic(Audio::Music music) {


    if(this->music.getStatus() != this->music.Playing ){
        if (this->music.openFromFile(musicPath[music])) {
            this->music.setVolume(this->musicVolume);
            this->music.setLoop(true);
        }
    }
}

/**
 * Sjekker om muteknappene for musikk eller hele lyden er blitt trykket.
 * Fjerner lyedeffekter som er "ferdigspilt"
 */
void SoundLoader::updateSounds() {
    if (*muted || *mutedMusic) {
        this->music.pause();
    } else if (this->music.getStatus() == this->music.Paused || this->music.getStatus() == this->music.Stopped) {
        this->music.play();
    }
    this->removeStoppedEffects();
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

/**
 * Kalles hvor det skjer et state-bytte som trengs ny musikk. For eksempel fra GameOverState til MainMenu.
 *
 */
void SoundLoader::stopMusic() {
    this->music.stop();
}
