#include "../../Header Files/States/stateKeybindings.h"
#include "../../Header Files/States/stateSettings.h"

#include <cstring>
#include <iostream>

/**
 * Init settingsState.
 * @param window
 */
void stateKeybindings::initialize(sf::RenderWindow *window) {

    memset(machine.keyPressed, 0, sizeof(machine.keyPressed)); //For at tastetrykk gjort i andre states ikke skal beholdes

}
/**
 * Update on keyevent, navigation through settings
 * @param window
 */
void stateKeybindings::update(sf::RenderWindow *window) {

}
/**
 *
 * @param window
 */
void stateKeybindings::render(sf::RenderWindow *window) {


}

void stateKeybindings::destroy(sf::RenderWindow *window) {

}

