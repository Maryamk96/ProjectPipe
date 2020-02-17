#include "GameWindow.h"
#include "Row.h"
#include "Column.h"
#include "L1.h"
#include "L2.h"
#include "L3.h"
#include "L4.h"
#include "Plus.h"
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

GameWindow::GameWindow(sf::RenderWindow* window) : window(window) {
    texture.loadFromFile(resDir + gameImg);
    sprite.setTexture(texture);
    backBtn = new ImgBtn(10, 10, 75, 75, backImg);
    scoreText = new TextBtn(350, 20, sf::Color::Black, "", mainFont);
    music.openFromFile(resDir + mainMusic);
    music.setLoop(true);
    music.play();
    srand((unsigned)time(0));
    randomPipes();
    setupPipeBtns();
}

GameWindow::~GameWindow() {
    delete backBtn;
    delete scoreText;
}

void GameWindow::backBtnEvents() {
    backBtn->events(mousePos);
}

WindowType GameWindow::events() {
    updateMousePos();
    backBtnEvents();
    if (backBtn->isClicked) return MENU_WINDOW;
    eventsPipeBtns();
    return CURRENT_WINDOW;
}

void GameWindow::render() {
    window->draw(sprite);
    backBtn->render(window);
    renderPipeBtns();
    renderScoreText();
}

void GameWindow::updateMousePos() {
    mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

void GameWindow::setupPipeBtns() {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            delete pipeBtns[y][x];
            pipeBtns[y][x] = nullptr;
        }
    }
    int top = 137;
    int left = 126;
    int w = 111;
    int h = 106;
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            string imgStr = pipes[y][x]->name;
            imgStr += pipes[y][x]->hasWater ? "-w" : "";
            imgStr += ".png";
            pipeBtns[y][x] = new ImgBtn(left, top, w, h, imgStr);
            left += w;
        }
        top += h;
        left = 126;
    }
}

void GameWindow::eventsPipeBtns() {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            pipeBtns[y][x]->events(mousePos);
            if (pipeBtns[y][x]->isClicked) {
                rotatePipe(pipes[y][x]);
                moveWaterToEnd();
                setupPipeBtns();
            }
            else if (pipeBtns[y][x]->isHovered) {
                pipeBtns[y][x]->shape.setFillColor(sf::Color(0xDEDAD1FF));
            }
            else {
                pipeBtns[y][x]->shape.setFillColor(backBtn->shape.getFillColor()); // just reset it.
            }
        }
    }
}

void GameWindow::renderPipeBtns() {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            pipeBtns[y][x]->render(window);
        }
    }
}

void GameWindow::renderScoreText() {
    if (hasWon) scoreText->text.setString("A Win With" + to_string(score));
    else scoreText->text.setString(to_string(score));
    int x = (window->getSize().x - scoreText->text.getGlobalBounds().width) / 2;
    scoreText->text.setPosition(x, 20);
    scoreText->render(window);
}

bool GameWindow::isValid(int row, int col) {
    return row >= 0 && row < 5 && col >= 0 && col < 5;
}

Pipe* GameWindow::customPipeAt(sf::Vector2i index, PipeType t) {
    int y = index.y;
    int x = index.x;
    Pipe* pipe = nullptr;
    if (!isValid(y, x)) return pipe;
    switch (t) {
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

Pipe* GameWindow::randomPipeAt(sf::Vector2i index) {
    int randNum = (rand() % 7);
    return customPipeAt(index, (PipeType)randNum);
}

void GameWindow::randomPipes() {
    bool found = false;
    while (!found) {
        removePipes();
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                pipes[y][x] = randomPipeAt(sf::Vector2i(x, y));
            }
        }
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                updateConnectionsOf(pipes[y][x]);
            }
        }
        if (moveWaterToEnd()) found = true;
    }
    randomizePipes();
    moveWaterToEnd();
}

void GameWindow::removePipes() {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            if (pipes[y][x]) {
                delete pipes[y][x];
                pipes[y][x] = nullptr;
            }
        }
    }
}

void GameWindow::randomizePipes() {
    int y1, x1;
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            y1 = rand() % 5;
            x1 = rand() % 5;
            changePlace(pipes[y][x], pipes[y1][x1]);
        }
    }
}

Pipe* GameWindow::upPipeOf(Pipe* pipe) {
    int r = pipe->r - 1;
    int c = pipe->c;
    if (!isValid(r, c)) return nullptr;
    else return pipes[r][c];
}

Pipe* GameWindow::rightPipeOf(Pipe* pipe) {
    int r = pipe->r;
    int c = pipe->c + 1;
    if (!isValid(r, c)) return nullptr;
    else return pipes[r][c];
}

Pipe* GameWindow::downPipeOf(Pipe* pipe) {
    int r = pipe->r + 1;
    int c = pipe->c;
    if (!isValid(r, c)) return nullptr;
    else return pipes[r][c];
}

Pipe* GameWindow::leftPipeOf(Pipe* pipe) {
    int r = pipe->r;
    int c = pipe->c - 1;
    if (!isValid(r, c)) return nullptr;
    else return pipes[r][c];
}

void GameWindow::updateConnectionsOf(Pipe* pipe) {
    if (!pipe) return;
    pipe->removeWaters();
    pipe->removeConnections();
    if (pipe->isNearToStart() && pipe->hasDirection(UP)) pipe->addConnectionFrom(UP);
    if (pipe->isNearToEnd() && pipe->hasDirection(RIGHT)) pipe->addConnectionFrom(RIGHT);
    Pipe* up = upPipeOf(pipe);
    Pipe* right = rightPipeOf(pipe);
    Pipe* down = downPipeOf(pipe);
    Pipe* left = leftPipeOf(pipe);
    if (up && pipe->hasDirection(UP) && up->hasDirection(DOWN)) {
        pipe->addConnectionFrom(UP);
        up->addConnectionFrom(DOWN);
    }
    if (right && pipe->hasDirection(RIGHT) && right->hasDirection(LEFT)) {
        pipe->addConnectionFrom(RIGHT);
        right->addConnectionFrom(LEFT);
    }
    if (down && pipe->hasDirection(DOWN) && down->hasDirection(UP)) {
        pipe->addConnectionFrom(DOWN);
        down->addConnectionFrom(UP);
    }
    if (left && pipe->hasDirection(LEFT) && left->hasDirection(RIGHT)) {
        pipe->addConnectionFrom(LEFT);
        left->addConnectionFrom(RIGHT);
    }
}

bool GameWindow::isConnectedFromDirection(Direction d, Pipe* p1, Pipe* p2) {
    if (!p1 || !p2) return false;
    if (d == UP && p1->hasConnectionInDirection(UP) && p2->hasConnectionInDirection(DOWN)) return true;
    else if (d == RIGHT && p1->hasConnectionInDirection(RIGHT) && p2->hasConnectionInDirection(LEFT)) return true;
    else if (d == DOWN && p1->hasConnectionInDirection(DOWN) && p2->hasConnectionInDirection(UP)) return true;
    else if (d == LEFT && p1->hasConnectionInDirection(LEFT) && p2->hasConnectionInDirection(RIGHT)) return true;
    else return false;
}

void GameWindow::changePlace(Pipe* p1, Pipe* p2) {
    if (!p1 || !p2) return;
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
    updateConnectionsOf(p1);
    updateConnectionsOf(p2);
}

bool GameWindow::recursiveMove(Pipe* p, Direction from) {
    if (!p || p->hasWaterInDirection(from)) return false;
    if (p->isNearToStart() && !p->hasDirection(UP)) return false;
    p->addWaterFrom(from);
    score = score + 100;
    if (p->isNearToEnd() && p->hasDirection(RIGHT)) return true;
    if (p->hasLeakage()) return false;
    Pipe* up = upPipeOf(p);
    Pipe* right = rightPipeOf(p);
    Pipe* down = downPipeOf(p);
    Pipe* left = leftPipeOf(p);
    if (p->canMoveWaterTo(UP) && isConnectedFromDirection(UP, p, up) && recursiveMove(up, DOWN)) return true;
    if (p->canMoveWaterTo(RIGHT) && isConnectedFromDirection(RIGHT, p, right) && recursiveMove(right, LEFT)) return true;
    if (p->canMoveWaterTo(DOWN) && isConnectedFromDirection(DOWN, p, down) && recursiveMove(down, UP)) return true;
    if (p->canMoveWaterTo(LEFT) && isConnectedFromDirection(LEFT, p, left) && recursiveMove(left, RIGHT)) return true;
    return false;
}

bool GameWindow::moveWaterToEnd() {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            if (pipes[y][x]) pipes[y][x]->removeWaters();
        }
    }
    score = 0;
    hasWon = recursiveMove(pipes[0][0], UP);
    return hasWon;
}

void GameWindow::rotatePipe(Pipe* p) {
    PipeType t = p->getPipeType();
    PipeType newT;
    switch (t) {
    case ROW:
        newT = COLUMN;
        break;
    case COLUMN:
        newT = ROW;
        break;
    case PLUS:
        newT = PLUS;
        break;
    case L1:
        newT = L2;
        break;
    case L2:
        newT = L3;
        break;
    case L3:
        newT = L4;
        break;
    case L4:
        newT = L1;
        break;
    default:
        newT = ROW;
        break;
    }
    int r = p->r;
    int c = p->c;
    delete p;
    pipes[r][c] = customPipeAt(sf::Vector2i(c, r), newT);
    updateConnectionsOf(pipes[r][c]);
}
