#pragma once

#include "Pipe.h"

class L4 : public Pipe
{
public:
    L4(int r, int c);
    bool hasDirection(Direction d) override;
    bool hasLeakage() override;
    PipeType getPipeType() override;
    bool canMoveWaterTo(Direction d) override;
};
