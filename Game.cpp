#include "Game.h"
#include "Row.h"
#include "Column.h"
#include "L1.h"
#include "L2.h"
#include "L3.h"
#include "L4.h"
#include "Plus.h"
#include <stdlib.h>
#include <vector>

using namespace std;

Game::Game()
{
    window = new sf::RenderWindow(sf::VideoMode(windowW, windowH), gameName);
    event = sf::Event();
    currentWindow = MENU_WINDOW;
    menuWindow = new MenuWindow(window);
    gameWindow = new GameWindow(window);
    aboutWindow = new AboutWindow(window);
}

Game::~Game()
{
    delete menuWindow;
    delete gameWindow;
    delete aboutWindow;
    delete window;
}

void Game::start()
{
    while (window->isOpen())
    {
        events();
        render();
    }
}

void Game::events() 
{
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window->close();
    }
    WindowType win;
    switch (currentWindow) 
    {
    case MENU_WINDOW:
        win = menuWindow->events();
        break;
    case GAME_WINDOW:
        win = gameWindow->events();
        break;
    case ABOUT_WINDOW:
        win = aboutWindow->events();
        break;
    default:
        win = CURRENT_WINDOW;
        break;
    }
    if (win != CURRENT_WINDOW) currentWindow = win;
}

void Game::render()
{
    window->clear();
    ///
    renderWindows();
    ///
    window->display();
}

void Game::renderWindows()
{
    switch (currentWindow)
    {
    case MENU_WINDOW:
        menuWindow->render();
        break;
    case GAME_WINDOW:
        gameWindow->render();
        break;
    case ABOUT_WINDOW:
        aboutWindow->render();
        break;
    case CLOSE_WINDOW:
        window->close();
        break;
    default:
        break;
    }
}

bool Game::isValid(int row, int col) 
{
    return row >= 0 && row < 5 && col >= 0 && col < 5;
}

Pipe* Game::customPipeAt(sf::Vector2i index, PipeType t)
{
    int y = index.y;
    int x = index.x;
    Pipe* pipe = NULL;
    if (!isValid(y, x)) return pipe;
    switch (t) 
    {
    case ROW:
        pipe = new class::Row(y, x);
        break;
    case COLUMN:
        pipe = new class::Column(y, x);
        break;
    case L1:
        pipe = new class::L1(y, x);
        break;
    case L2:
        pipe = new class::L2(y, x);
        break;
    case L3:
        pipe = new class::L3(y, x);
        break;
    case L4:
        pipe = new class::L4(y, x);
        break;
    case PLUS:
        pipe = new class::Plus(y, x);
        break;
    default:
        break;
    }
    return pipe;
}

Pipe* Game::randomPipeAt(sf::Vector2i index)
{
    int randNum = (rand() % 7);
    return customPipeAt(index, (PipeType)randNum);
}

void Game::randomPipes()
{
    bool found = false;
    while (!found)
    {
        removePipes();
        for (int y = 0; y < 5; y++) 
        {
            for (int x = 0; x < 5; x++)
            {
                pipes[y][x] = randomPipeAt(sf::Vector2i(x, y));
                updateConnectionsOf(pipes[y][x]);
            }
        }
        for (int y = 0; y < 5 && !found; y++) 
        {
            for (int x = 0; x < 5 && !found; x++)
            {
                for (int t = 0; t < 7 && !found; t++) 
                {
                    delete pipes[y][x];
                    pipes[y][x] = customPipeAt(sf::Vector2i(x, y), (PipeType)t);
                    updateConnectionsOf(pipes[y][x]);
                    if (moveWaterToEnd()) found = true;
                }
            }
        }
    }
    randomizePipes();
}

void Game::removePipes()
{
    for (int y = 0; y < 5; y++) 
    {
        for (int x = 0; x < 5; x++)
        {
            delete pipes[y][x];
            pipes[y][x] = NULL;
        }
    }
}

void Game::randomizePipes() 
{
    int y1, x1;
    for (int y = 0; y < 5; y++) 
    {
        for (int x = 0; x < 5; x++) 
        {
            y1 = rand() % 5;
            x1 = rand() % 5;
            changePlace(pipes[y][x], pipes[y1][x1]);
        }
    }
}

sf::Vector2i Game::upIndexOf(sf::Vector2i index)
{
    return sf::Vector2i(index.x, index.y - 1);
}

sf::Vector2i Game::rightIndexOf(sf::Vector2i index)
{
    return sf::Vector2i(index.x + 1, index.y);
}

sf::Vector2i Game::downIndexOf(sf::Vector2i index) 
{
    return sf::Vector2i(index.x, index.y + 1);
}

sf::Vector2i Game::leftIndexOf(sf::Vector2i index)
{
    return sf::Vector2i(index.x - 1, index.y);
}

Pipe* Game::upPipeOf(Pipe* pipe) 
{
    sf::Vector2i index(pipe->c, pipe->r);
    sf::Vector2i upIndex = upIndexOf(index);
    return pipes[upIndex.y][upIndex.x];
}

Pipe* Game::rightPipeOf(Pipe* pipe) 
{
    sf::Vector2i index(pipe->c, pipe->r);
    sf::Vector2i rightIndex = rightIndexOf(index);
    return pipes[rightIndex.y][rightIndex.x];
}

Pipe* Game::downPipeOf(Pipe* pipe) 
{
    sf::Vector2i index(pipe->c, pipe->r);
    sf::Vector2i downIndex = downIndexOf(index);
    return pipes[downIndex.y][downIndex.x];
}

Pipe* Game::leftPipeOf(Pipe* pipe)
{
    sf::Vector2i index(pipe->c, pipe->r);
    sf::Vector2i leftIndex = leftIndexOf(index);
    return pipes[leftIndex.y][leftIndex.x];
}

void Game::updateConnectionsOf(Pipe* pipe)
{
    pipe->removeConnections();
    pipe->removeWaters();
    if (pipe->isNearToStart() && pipe->hasDirection(UP)) pipe->addConnectionFrom(UP);
    if (pipe->isNearToEnd() && pipe->hasDirection(RIGHT)) pipe->addConnectionFrom(RIGHT);
    Pipe* up = upPipeOf(pipe);
    Pipe* right = rightPipeOf(pipe);
    Pipe* down = downPipeOf(pipe);
    Pipe* left = leftPipeOf(pipe);
    if (pipe->hasDirection(UP) && up->hasDirection(DOWN)) 
    {
        pipe->addConnectionFrom(UP);
        up->addConnectionFrom(DOWN);
    }
    if (pipe->hasDirection(RIGHT) && right->hasDirection(LEFT))
    {
        pipe->addConnectionFrom(RIGHT);
        up->addConnectionFrom(LEFT);
    }
    if (pipe->hasDirection(DOWN) && down->hasDirection(UP))
    {
        pipe->addConnectionFrom(DOWN);
        up->addConnectionFrom(UP);
    }
    if (pipe->hasDirection(LEFT) && left->hasDirection(RIGHT)) 
    {
        pipe->addConnectionFrom(LEFT);
        up->addConnectionFrom(RIGHT);
    }
}

bool Game::isConnectedFromDirection(Direction d, Pipe* p1, Pipe* p2)
{
    Direction dComplement = NONE;
    if (d == UP) dComplement = DOWN;
    if (d == DOWN) dComplement = UP;
    if (d == LEFT) dComplement = RIGHT;
    if (d == RIGHT) dComplement = LEFT;
    return p1->hasConnectionInDirection(d) && p2->hasConnectionInDirection(dComplement);
}

void Game::changePlace(Pipe* p1, Pipe* p2)
{
    int r1 = p1->r;
    int c1 = p1->c;
    int r2 = p2->r;
    int c2 = p2->c;
    pipes[r1][c1] = p2;
    pipes[r2][c2] = p1;
    p2->c = c1;
    p2->r = r1;
    p1->c = c2;
    p1->r = r2;
}

bool Game::moveWaterToEnd()
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++) 
        {
            pipes[y][x]->removeWaters();
        }
    }
    score = 0;
    return recursiveMove(pipes[1][1], UP);
}

bool Game::recursiveMove(Pipe* p, Direction from) 
{
    if (p == NULL) return false;
    if (p->isNearToStart() && !p->hasDirection(UP)) return false;
    if (p->isNearToEnd() && p->hasDirection(RIGHT)) return true;
    p->addWaterFrom(from);
    score++;
    if (p->hasLeakage()) return false;
    Pipe* up = upPipeOf(p);
    Pipe* right = rightPipeOf(p);
    Pipe* down = downPipeOf(p);
    Pipe* left = leftPipeOf(p);
    if (isConnectedFromDirection(UP, p, up) && recursiveMove(up, DOWN)) return true;
    if (isConnectedFromDirection(RIGHT, p, right) && recursiveMove(right, LEFT)) return true;
    if (isConnectedFromDirection(DOWN, p, down) && recursiveMove(down, UP)) return true;
    if (isConnectedFromDirection(LEFT, p, left) && recursiveMove(left, RIGHT)) return true;
    return false;
}
