#pragma once

#include <vector>
#include <string>
#include "enum.h"

class Pipe {


public:
    Pipe(std::string name, int r, int c);
    virtual bool hasDirection(Direction d) = 0;
    virtual bool hasLeakage() = 0;
    virtual PipeType getPipeType() = 0;
    virtual bool addWaterFrom(Direction d) = 0;
    void removeWater();
    bool hasWaterInDirection(Direction d);

protected:
    bool hasWater;
    int r; // row
    int c; // column
    std::vector<Direction> waters; // shows which direction has water
    const std::string name;
};
