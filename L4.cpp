#include "L4.h"

L4::L4(int r, int c) : Pipe("L4", r, c) {}

bool L4::hasDirection(Direction d) 
{
    return d == LEFT || d == UP;
}

bool L4::hasLeakage() 
{
    return !hasConnectionInDirection(LEFT) || !hasConnectionInDirection(UP);
}

PipeType L4::getPipeType()
{
    return PipeType::L4;
}
