#pragma once

#include "Pipe.h"

class Row : public Pipe
{
public:
    Row(int r, int c);
    bool hasDirection(Direction d) override;
    bool hasLeakage() override;
    PipeType getPipeType() override;
    bool canMoveWaterTo(Direction d) override;
};
