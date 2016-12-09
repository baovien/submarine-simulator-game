#ifndef VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H
#define VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H

#include "../Core/state.h"
#include "../Core/machine.h"
#include "../Core/utilities.h"
#include <fstream>
#include <vector>

class StateHighscore : public States
{
public:
    void initialize(sf::RenderWindow *window);

    void update(sf::RenderWindow *window);

    void render(sf::RenderWindow *window);

    void destroy(sf::RenderWindow *window);

    void handleEvent(sf::RenderWindow *window, sf::Event event);

    void reinitialize(sf::RenderWindow *window);

private:

    sf::Text *title;
    sf::Text *titleArcade;
    sf::Text *titleClassic;
    //std::vector<int, std::string> er;
   // sf::Texture *backTexture;
    sf::Sprite *back;

/*    std::vector<std::tuple<sf::Text, std::string, std::string>> Scoretable1 =
            {{std::make_tuple("#", "Player", "Score")},
             {std::make_tuple("1", BestArcade[0].first, std::to_string(BestArcade[0].second))},
             {std::make_tuple("2", BestArcade[1].first, std::to_string(BestArcade[1].second))},
             {std::make_tuple("3", BestArcade[2].first, std::to_string(BestArcade[2].second))}};
*/
    struct textstruct
    {
        sf::Text *Number;
        sf::Text *Player;
        sf::Text *Score;
    };
    textstruct Texturetext[4];

    struct menuTextureStruct
    {
        sf::Texture* buttonNormal;
        sf::Texture* buttonMouseOver;
        sf::Texture* buttonClicked;
    };
    menuTextureStruct PictureTexture[1];
    sf::Sprite* PictureButtons[1];


    sf::Texture *bgTexture;
    sf::Texture *TableTexture;

    sf::Sprite *TableArcade;
    sf::Sprite *TableClassic;
    sf::Sprite *background;

    Utilities util;
    int selected;
};

#endif //VIETNAMESE_SPACE_PROGRAM_HIGHSCORESTATE_H
