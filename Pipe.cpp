#include "Pipe.h"

using namespace std;

Pipe::Pipe(string name, int r, int c) : name(name), r(r), c(c) {}

Pipe::~Pipe() 
{

}

bool Pipe::addWaterFrom(Direction d) 
{
    if (!hasConnectionInDirection(d)) return false;
    else {
        hasWater = true;
        if (!hasWaterInDirection(d)) waters.push_back(d);
        return true;
    }
}

bool Pipe::addConnectionFrom(Direction d)
{
    if (!hasDirection(d)) return false;
    else {
        if (!hasConnectionInDirection(d)) connections.push_back(d);
        return true;
    }
}

void Pipe::removeConnections()
{
    connections.clear();
}

void Pipe::removeWaters()
{
    hasWater = false;
    waters.clear();
}

bool Pipe::hasWaterInDirection(Direction d)
{
    for (auto water : waters)
    {
        if (water == d) return true;
    }
    return false;
}

bool Pipe::hasConnectionInDirection(Direction d)
{
    for (auto connection : connections)
    {
        if (connection == d) return true;
    }
    return false;
}

bool Pipe::isNearToStart() 
{
    return r == 1 && c == 1;
}

bool Pipe::isNearToEnd() 
{
    return r == 4 && c == 4;
}
