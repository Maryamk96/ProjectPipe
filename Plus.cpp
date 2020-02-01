#include "Plus.h"

Plus::Plus(int r, int c) : Pipe("Plus", r, c) {}

bool Plus::hasDirection(Direction d)
{
    return d != NONE;
}

bool Plus::hasLeakage() {
    if (hasWaterInDirection(UP) || hasWaterInDirection(DOWN))
    {
        if (!hasConnectionInDirection(UP) || !hasConnectionInDirection(DOWN)) return true;
        else return false;
    }
    else if (hasWaterInDirection(RIGHT) || hasWaterInDirection(LEFT))
    {
        if (!hasConnectionInDirection(RIGHT) || !hasConnectionInDirection(LEFT)) return true;
        else return false;
    }
    return false;
}

PipeType Plus::getPipeType()
{
    return PLUS;
}
