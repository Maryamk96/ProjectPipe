#include "L3.h"

L3::L3(int r, int c) : Pipe("L3", r, c) {}

bool L3::hasDirection(Direction d) 
{
    return d == LEFT || d == DOWN;
}

bool L3::hasLeakage() 
{
    return !hasConnectionInDirection(LEFT) || !hasConnectionInDirection(DOWN);
}

PipeType L3::getPipeType() 
{
    return PipeType::L3;
}

bool L3::canMoveWaterTo(Direction d)
{
    if (d == LEFT) return hasWaterInDirection(DOWN);
    else return hasWaterInDirection(LEFT);
}
