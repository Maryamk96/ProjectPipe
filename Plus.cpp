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

bool Plus::canMoveWaterTo(Direction d) 
{
    if (d == UP) return hasWaterInDirection(DOWN);
    else if (d == DOWN) return hasWaterInDirection(UP);
    else if (d == RIGHT) return hasWaterInDirection(LEFT);
    else if (d == LEFT) return hasWaterInDirection(RIGHT);
    else return false;
}
