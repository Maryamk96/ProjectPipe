#include "Pipe.h"

using namespace std;

Pipe::Pipe(string name, int r, int c) : name(name), r(r), c(c) {}

void Pipe::removeWater() {
    hasWater = false;
}

bool Pipe::hasWaterInDirection(Direction d) {
    for (auto water : waters) {
        if (water == d) return true;
    }
    return false;
}
