#include "L1.h"

L1::L1(int r, int c) : Pipe("L1", r, c) {}

bool L1::hasDirection(Direction d)
{
    return d == UP || d == RIGHT;
}

bool L1::hasLeakage() 
{
    return !hasConnectionInDirection(UP) || !hasConnectionInDirection(RIGHT);
}

PipeType L1::getPipeType()
{
    return PipeType::L1;
}

bool L1::canMoveWaterTo(Direction d) 
{
    if (d == UP) return hasWaterInDirection(RIGHT);
    else return hasWaterInDirection(UP);
}
