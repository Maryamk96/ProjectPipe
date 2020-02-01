#include "Pipe.h"

using namespace std;

Pipe::Pipe(string name, int r, int c) : name(name), r(r), c(c) 
{
    hasWater = false;
    r = 0;
    c = 0;
    waters = vector<Direction>(4, NONE); // 4 waters with NONE value
    connections = vector<Direction>(4, NONE); // ...
}

Pipe::~Pipe() 
{

}

bool Pipe::addWaterFrom(Direction d)
{
    if (!hasConnectionInDirection(d)) return false;
    else 
    {
        if (!hasWaterInDirection(d)) waters.push_back(d);
        return true;
    }
}

bool Pipe::addConnectionFrom(Direction d)
{
    if (!hasDirection(d)) return false;
    else 
    {
        if (!hasConnectionInDirection(d)) connections.push_back(d);
        return true;
    }
}

void Pipe::removeConnections() {
    for (int i = 0; i < connections.size(); i++) 
    {
        connections[i] = NONE;
    }
}

void Pipe::removeWaters() 
{
    hasWater = false;
    for (int i = 0; i < waters.size(); i++)
    {
        waters[i] = NONE;
    }
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
