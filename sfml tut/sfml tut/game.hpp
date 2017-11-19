#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
#include <SFML/Graphics.hpp>

class GameState;

class Game
{
    public:

    std::stack<GameState*> states;

	//window that our game will be drawn in
    sf::RenderWindow window;

    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    GameState* peekState();

	//act much like main in our program
    void gameLoop();

    Game();
    ~Game();
};

#endif /* GAME_HPP */