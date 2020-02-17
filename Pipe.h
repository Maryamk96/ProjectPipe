#pragma once

#include <vector>
#include <string>
#include "enum.h"

class GameWindow;

class Pipe 
{
    friend class GameWindow;
protected:
    bool hasWater = false;
    int r = -1; // row
    int c = -1; // column
    std::vector<Direction> waters; // shows which direction has water
    std::vector<Direction> connections; // shows which direction is connected to another pipe
    const std::string name;
public:
    Pipe(std::string name, int r, int c);
    virtual ~Pipe();
    virtual bool hasDirection(Direction d) = 0;
    virtual bool hasLeakage() = 0;
    virtual PipeType getPipeType() = 0;
    virtual bool canMoveWaterTo(Direction d) = 0;
    bool addWaterFrom(Direction d);
    bool addConnectionFrom(Direction d);
    void removeConnections();
    void removeWaters();
    bool hasWaterInDirection(Direction d);
    bool hasConnectionInDirection(Direction d);
    bool isNearToStart();
    bool isNearToEnd();
};
