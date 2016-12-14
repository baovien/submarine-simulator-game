#ifndef VIETNAMESE_SPACE_PROGRAM_APP_H
#define VIETNAMESE_SPACE_PROGRAM_APP_H

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../Include/Core/state.h"
#include "../States/stateMainMenu.h"
#include "score.h"
#include "playerLives.h"

class App
{
public:
    void run();

    void saveSettings();
    void loadSettings();
};
#endif //VIETNAMESE_SPACE_PROGRAM_APP_H

