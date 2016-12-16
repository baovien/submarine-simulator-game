/*******************************************
 * Alle states har soundloaderen under machine (machine->audioLoaderPeker).
 * For å få lyd til et objekt, f.eks healthPack, må det dependencyinjectes inn.
 * 1. Det gjøres ved å include audioLoader.h i objektets header og lage en peker AudioLoader* soundloader.
 * 2. Deretter tas healthpack konstruktøren inn pekeren. Skriv så this->audioLoader = soundloader
 *    eller audioLoader(audioLoader) etter konstruktøren.
 * 3. Nå kan du bruke this->audioLoader til å kalle en lyd i ønsket klasse.
 *
 * /////Legge til musikk
 *
 *       Legg til en ny enum i headerfilen, deretter skriv følgende i konstruktøren:
 *       musicPath[Audio::Music::NAVN_PÅ_MUSIKK] = ("PATH_TIL_MUSIKK");
 *
 * /////Spille av musikk
 *
 *      I konstruktøren til en state, skriv
 *      machine->audioLoaderPeker.stopMusic();          //Må stoppe musikken for å kunne starte ny musikk
 *      machine->audioLoaderPeker.playMusic(Audio::Music::NAVN_PÅ_MUSIKK);
 *
 *      I updaten til en state skriv
 *      machine->audioLoaderPeker.updateSounds();
 *
 *      Alle steder i staten der det byttes til en ny state, skriv
 *      machine->audioLoaderPeker.stopMusic();
 *
 * /////Legge til lyd
 *
 *      Legg til en ny enum i headerfilen, deretter skriv følgende i konstruktøren:
 *      buffers[Audio::NAVN_PÅ_LYDEFFEKT].loadFromFile("PATH_TIL_LYDEFFEKT");
 *
 * /////Spille av en lyd (DEPENDENCY INJECT)
 *
 *      Kall funksjonen under
 *      audioLoader->playEffect(Audio::NAVN_PÅ_LYDEFFEKT)
 *
 *******************************************/

#include "../../Include/Core/audioLoader.h"

/**
 * Soundloader's constructor
 * @return
 */
AudioLoader::AudioLoader() {
    effectsVolume = 50;
    musicVolume = 50;

    //Music
    musicPath[Audio::Music::MAIN_MENU] = ("Audio/Music/menu.ogg");
    musicPath[Audio::Music::ARCADE] = ("Audio/Music/arcade.ogg");
    musicPath[Audio::Music::GAMEOVER] = ("Audio/Music/gameover.ogg");
    musicPath[Audio::Music::CLASSIC] = ("Audio/Music/classic.ogg");

    //SFX
    buffers[Audio::Effect::PLAYER_SHOOT1].loadFromFile("Audio/SFX/missileLaunch.ogg");
    buffers[Audio::Effect::PLAYER_SHOOT2].loadFromFile("Audio/SFX/shoot2.ogg");
    buffers[Audio::Effect::ENEMY_SHOOT].loadFromFile("Audio/SFX/pop.ogg");
    buffers[Audio::Effect::BULLET_POP].loadFromFile("Audio/SFX/explosion.ogg");
    buffers[Audio::Effect::REPAIR].loadFromFile("Audio/SFX/repair.ogg");
    buffers[Audio::Effect::NEXTWAVE].loadFromFile("Audio/SFX/wavedone.wav");
    buffers[Audio::Effect::OVERHEAT].loadFromFile("Audio/SFX/negative.ogg");
    buffers[Audio::Effect::BOSSWAVE].loadFromFile("Audio/SFX/bossincoming.ogg");
    buffers[Audio::Effect::SHIELD].loadFromFile("Audio/SFX/shield.ogg");
    buffers[Audio::Effect::WAVEDONE].loadFromFile("Audio/SFX/positive.ogg");

}

/**
 * Plays sound if not muted
 * @param effect - Sound to play
 */
void AudioLoader::playEffect(Audio::Effect effect) {
    if (!*muted) {
        this->sounds.push_back(sf::Sound());
        sf::Sound &sound = sounds.back();

        sound.setBuffer(buffers[effect]);
        sound.setVolume(effectsVolume);
        sound.play();
    }
}

/**
 * Removes effects that have been stopped.
 * Called in updateSounds
 */
void AudioLoader::removeStoppedEffects(){
    sounds.remove_if([](const sf::Sound& s){
        return s.getStatus() == sf::Sound::Stopped;
    });
}

/**
 * Prepares the music to be played.
 * @param music - Music to prepare
 */
void AudioLoader::playMusic(Audio::Music music) {


    if(this->music.getStatus() != this->music.Playing ){
        if (this->music.openFromFile(musicPath[music])) {
            this->music.setVolume(this->musicVolume);
            this->music.setLoop(true);
        }
    }
}

/**
 * Plays/pauses music depending on whether it is muted or not
 * Removes sounds that are complete
 */
void AudioLoader::updateSounds() {
    if (*muted || *mutedMusic) {
        this->music.pause();
    } else if (this->music.getStatus() == this->music.Paused || this->music.getStatus() == this->music.Stopped) {
        this->music.play();
    }
    this->removeStoppedEffects();
}

/**
 * Henter mutedPointer og mutedMusicPointer fra machine
 * @param muted - bool to tell if all sounds are muted (Including music)
 * @param mutedMusic - bool to tell if music is muted
 */
void AudioLoader::initSoundPointers(bool *muted, bool *mutedMusic) {
    this->muted = muted;
    this->mutedMusic = mutedMusic;
}

/**
 *  Stops the music.
 */
void AudioLoader::stopMusic() {
    this->music.stop();
}

AudioLoader::~AudioLoader() {

}
