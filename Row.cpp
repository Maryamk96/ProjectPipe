#include "Row.h"

Row::Row(int r, int c) : Pipe("Row", r, c) {}

bool Row::hasDirection(Direction d)
{
    return d == LEFT || d == RIGHT;
}

bool Row::hasLeakage() 
{
    return !hasConnectionInDirection(LEFT) || !hasConnectionInDirection(RIGHT);
}

PipeType Row::getPipeType() 
{
    return ROW;
}