#ifndef SUBMARINESIMULATORAPP_H
#define SUBMARINESIMULATORAPP_H

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

    void saveJson();
    void loadJson();
    void validateJson();
};
#endif //SUBMARINESIMULATORAPP_H

