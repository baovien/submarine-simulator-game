#ifndef VIETNAMESE_SPACE_PROGRAM_UTIL_H
#define VIETNAMESE_SPACE_PROGRAM_UTIL_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Utilities {
private:
    sf::Font *font;
    sf::Sprite *muteButton;

    struct muteTextureStruct{
        sf::Texture* buttonNormal;
        sf::Texture* buttonMouseOver;
        sf::Texture* buttonClicked;
    };
    muteTextureStruct muteTextures[2];

    std::map<const sf::String, std::tuple<sf::String, sf::String, sf::String>> languageMap =
            {{"submarine simulator", std::make_tuple(L"Ubåtsimulator", "podmornica simulator", "Simulateur de sous-marin")},
             {"wave: ",              std::make_tuple(L"Bølge: ", "talas: ", "vague: ")},
             {"boss",                std::make_tuple("Sjef", "gazda", "patron")},
             {"settings",            std::make_tuple("Innstillinger", "podesavanja", "parametres")},
             {"music",               std::make_tuple("Musikk", "muzika", "la musique")},
             {"controls",            std::make_tuple("Kontroller", "kontrole", "controles")},
             {"reset highscore",     std::make_tuple("Reset poengliste", "reset high score ", "Reinitialiser les scores")},
             {"reset controls",      std::make_tuple("Reset kontroller", "reset kontrole ", "Reinitialiser les controles")},
             {"movement",            std::make_tuple("Bevegelse", "pokret", "mouvement")},
             {"menu navigation",     std::make_tuple("Menynavigering", "navigacioni meni ", "Navigation menu")},
             {"up",                  std::make_tuple("Opp", "gore", "Up")},
             {"down",                std::make_tuple("Ned", "dole", "en bas")},
             {"left",                std::make_tuple("Venstre", "ljevo", "a gauche")},
             {"right",               std::make_tuple(L"Høyre", "desno", "droite")},
             {"back",                std::make_tuple("Tilbake", "nazad", "arriere")},
             {"select",              std::make_tuple("Velg", "odaberi", "selectionner")},
             {"pause",               std::make_tuple("Pause", "pauza", "pause")},
             {"shoot",               std::make_tuple("Skyt", "pucati", "tirer")},
             {"key already bound",   std::make_tuple("Tast allerede bundet", "kljuc vec vezan", "Cle deja reliee")},
             {"highscore",           std::make_tuple("Poengliste", "Najbolji Skor", "Score")},
             {"arcade",              std::make_tuple("Arcade", "arkada", "Arcade")},
             {"classic",             std::make_tuple("Klassisk", "klasik", "classique")},
             {"player",              std::make_tuple("Spiller", "igrac", "joueur")},
             {"how to play",         std::make_tuple("Hvordan spille", "kako igrati", "comment jouer")},
             {"select theme",        std::make_tuple("Velg tema", "Izaberi temu", "selectionne un theme")},
             {"select gamemode",     std::make_tuple("Velg spillmodus", "izaberite igra rezim", "Selectionner le mode")},
             {"select fighter",      std::make_tuple("Velg kjemper", "izaberite borac", "Choisir un combattant")},
             {"space",               std::make_tuple("Rommet", "nebo", "espace")},
             {"water",               std::make_tuple("Vann", "voda", "eau")},
             {"submarine",           std::make_tuple(L"Ubåt", "podmornica", "Sous-marin")},
             {"spaceship",           std::make_tuple("Romskip", "svemirski brod", "vaisseau spatial")},
             {"lives: ",             std::make_tuple("Liv: ", "zivoti: ", "vies: ")},
             {"score: ",             std::make_tuple("Poeng: ", "skor: ", "But: ")},
             {"game over",           std::make_tuple("Spill over", "kraj igre", "jeu termine")},
             {"lives",               std::make_tuple("Liv", "zivoti", "Vies")},
             {"score",               std::make_tuple("Poeng", "skor", "But")},
             {"paused. press",       std::make_tuple("Pauset. Trykk", "Pauziranje. presni", "En Pause. Appuyez sur")},
             {" to quit",            std::make_tuple(" for menyen", " da se vratis", " pour quitter")},
             {"gameplay",            std::make_tuple("Spill", "igraj", "Jeu")},
             {"are you sure?",       std::make_tuple("Er du sikker?", "da li ste sigurni?", "etes-vous sur?")},
             {"score",               std::make_tuple("1", "2", "3")},
             {"score",               std::make_tuple("1", "2", "3")},
             {"score",               std::make_tuple("1", "2", "3")},
             {"congratulations, after your striking performance",
                                     std::make_tuple("Gratulerer, etter dine fantastiske prestasjoner",
                                                     "Cestitam, nakon upecatljive performanse",
                                                     "Felicitations, apres votre performance remarquable")},
             {"you have been placed on the leaderboard",
                                     std::make_tuple(L"har du blitt satt på pallen",
                                                     "ste stavljeni na leaderboard",
                                                     "vous aves ette place sur le classement")},
             {"you did not manage to enter the leaderboard this time"
                      "\nmaybe you will next time. good luck!",
                                     std::make_tuple(L"Du klarte ikke å nå pallen denne gangen\nkanskje du klarer det neste gang.\nLykke til!",
                                                     "Niste uspeli da udu leaderboard ovaj put\nMozda cete sledeci put.\nSrecno!",
                                                     "Vois n'avez pas reussi a entrer dans\nle classement cette fois, Peut-etre la prochaine fois.\nBonne chance!")},
             {"this is the classic arcade space shooter game where the player only can move horizontally at the bottom of the screen.\n"
                      "the goal is to defeat the enemies by shooting them, while they move horizontally back and forth across the screen as\n"
                      "they advance towards the bottom of the screen."
                      " the enemies can kill the player by either shooting it \nor by colliding into it."
                      " the default keybind for shooting is space.",
                                     std::make_tuple(L"Dette er den klassiske arcade space shooter spillet hvor spilleren bare kan bevege seg horisontalt på bunnen av skjermen.\n"
                                                             "Målet er å overvinne fiendene ved å skyte de, mens de beveger seg horisontalt fram og tilbake over skjermen mens\n"
                                                             "de kommer nedover mot bunnen av skjermen."
                                                             " Fiendene kan drepe spilleren enten ved å skyte på den \neller ved å kollidere med den."
                                                             " Standardknappen for å skyte er mellomromstasten.",
                                                     "Ovo je klasicna arkada prostor strelac igra u kojoj igrac jedini moze da se krece horizontalno na dnu ekrana.\n"
                                                             "Cilj je da pobedi svoje neprijatelje pucaju, a kretanje po horizontali i nazad preko ekrana dok dodu dole prema dnu ekrana.\n"
                                                             "Neprijatelji mogu ubiti plejer ili pucajuci u njega ili sudara sa njom.\n"
                                                             "Standard dugme za snimanje je razmak.",
                                                     L"Ceci est l'espace d'arcade jeu de tir classique où le joueur ne peut se déplacer horizontalement en bas de l'écran.\n"
                                                             "L'objectif est de vaincre vos ennemis en leur tirant, tout en se déplaçant horizontalement et d'autre de l'écran\n"
                                                             "pendant qu'ils descendent vers le bas de l'écran. Les ennemis peuvent tuer le joueur soit en tirant dessus \nou en entrant en collision avec elle."
                                                             " Bouton standard pour tirer est la barre d'espace.")},
             {"enemy spawn in waves. they chase you and will shoot at you after the first boss. the number of enemies \ndepend on the wave. running into"
                      " the enemy will destroy it and damage you, unless you are shielded.",
                                     std::make_tuple(L"Fiender kommer i bølger. De jager deg og vil begynne å skyte på deg etter første boss. Antall fiender \nkommer an på bølgen. Å løpe på"
                                                             " fienden vil ødelegge den, samtidig som den skader med, med mindre du har skjold.",
                                                     "Neprijatelji dolaze u talasima. Oni jure vas i da ce poceti da pucaju na vas posle prvog sefa. Broj neprijatelja\nzavisi od talasa."
                                                             " Radi na neprijatelja ce ga unistiti, dok povrede, osim ako stit.",
                                                     L"Les ennemis viennent par vagues. Ils vous poursuivent et vont commencer à tirer sur vous après le premier boss."
                                                             " Nombre\nd'ennemis dépend de la vague. Fonctionnant sur l'ennemi le détruire, tandis que les blessures, à moins que vous protègent.")},
             {"there are two powerups. one will give you +1 lives, and the other one will grant you immunity for a short duration.",
                                     std::make_tuple(L"Det finnes to oppgraderinger. Den ene vil gi deg +1 liv, mens den andre vil deg immunitet for en kort periode.",
                                                     "Postoje dve nadogradnje. One ce obezbediti jedan zivot, dok ce drugi imunitet za kratko vreme.",
                                                     L"Il y a deux mises à niveau. On fournira une vie, tandis que l'autre volonté de l'immunité pour une courte période.")},
             {"the overheatbar is a function that keeps the player from shooting too much within a short period of time.\n"
                      "if the player overheats, the player has to wait till it cools down before the player can start shooting again",
                                     std::make_tuple(L"Overopphetningslinjen er en funksjon som holder spilleren fra å skyte for mye innenfor et lite tidsintervall.\n"
                                                             "Hvis spilleren overopphetes, må spilleren vente til den kjøles ned igjen før spilleren kan skyte igjen",
                                                     "Pregrevanje linija je funkcija koja drzi igraca od otpustanja previse u malom vremenskom intervalu. Ako igrac pregreje,\n"
                                                             "igrac mora da saceka dok se ne ohladi ponovo pre nego sto igrac moze ponovo pucati.",
                                                     L"Ligne Surchauffe est une fonction qui empêche le joueur de tirer trop dans un petit intervalle de temps."
                                                             " Si le joueur\nsurchauffe, le joueur doit attendre jusqu'à ce qu'il se refroidit à nouveau avant que le joueur peut tirer de nouveau.")},
             {"indestructable junk will periodically fly through the screen, damaging everything in its path.",
                                     std::make_tuple(L"Søppelobjekter er umulig å ødelegge, og vil periodisk fly forbi skjermen, og ødelegge alt på dens vei.",
                                                     "Smece Objekti su neunistivi i da ce periodicno leti pored ekrana i unistiti sve na svom putu.",
                                                     L"Ordures Les objets sont indestructibles et périodiquement survoler l'écran et tout détruire sur son passage.")},
             {"every fifth wave, the boss will spawn. running into it will kill you.\nthe default key to shoot the boss and enemies is space.",
                                     std::make_tuple(L"Hver femte bølge, vil bossen komme. Å løpe på den vil drepe deg.\nStandardknappen får å skyte på bossen og fiendene er mellomromstasten.",
                                                     "Svaki peti talas, sef doci. Running on ce te ubiti.\nUobicajeno dugme ce pucati sefa i neprijatelji su razmak.",
                                                     L"Chaque cinquième vague, le patron vient. Courir sur elle va vous tuer.\nBouton Défaut tirer le patron et les ennemis sont spacebar.")}
            };


public:
    Utilities();

    bool paused = false;

    sf::Sprite *getMuteButton() const;

    void pauseScreen() {
        //Funksjonen setter og fjerner pause
        paused = !paused;
    }

    void makeMuteButton(sf::RenderWindow* window, bool* mutedPointer);
    void checkMuteMouseOver(sf::RenderWindow* window);
    void checkMuteMouseClick(sf::RenderWindow* window, sf::Event event, bool* mutedPointer);

    //PARAM::::: Texture, scale x, scale y, position x, position y, window
    //Ubrukt
    sf::Sprite *addButton(sf::Texture* texture, float scaleX, float scaleY, float posX, float posY, sf::RenderWindow *window);

    //PARAM::::: Text, textsize, origin x, origin y, position x, position y, window, language int
    //Lager og oversetter teksten
    sf::Text *addText(sf::String textContent, unsigned int textSize, int originX, int originY, float posX, float posY, sf::RenderWindow *window, int language);

    //Oversetter spesifike ord
    sf::String translate(sf::String wordToTranslate, int language);

    //Tar inn sprite og returnerer true om mouseover
    bool checkMouseover(sf::Sprite *buttonSprite, sf::RenderWindow *window);

    //Tar inn sprite og returnerer true om mouseclick
    bool checkMouseclick(sf::Sprite *buttonSprite, sf::Event event);

};

#endif //VIETNAMESE_SPACE_PROGRAM_UTIL_H
