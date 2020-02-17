#include "L2.h"

L2::L2(int r, int c) : Pipe("L2", r, c) {}

bool L2::hasDirection(Direction d)
{
    return d == RIGHT || d == DOWN;
}

bool L2::hasLeakage() 
{
    return !hasConnectionInDirection(RIGHT) || !hasConnectionInDirection(DOWN);
}

PipeType L2::getPipeType()
{
    return PipeType::L2;
}

bool L2::canMoveWaterTo(Direction d) 
{
    if (d == RIGHT) return hasWaterInDirection(DOWN);
    else return hasWaterInDirection(RIGHT);
}
