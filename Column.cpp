#include "Column.h"

Column::Column(int r, int c) : Pipe("Column", r, c) {}

bool Column::hasDirection(Direction d) 
{
    return d == UP || d == DOWN;
}

bool Column::hasLeakage() 
{
    return !hasConnectionInDirection(DOWN) || !hasConnectionInDirection(UP);
}

PipeType Column::getPipeType()
{
    return COLUMN;
}

bool Column::canMoveWaterTo(Direction d)
{
    if (d == UP) return hasWaterInDirection(DOWN);
    else return hasWaterInDirection(UP);
}
