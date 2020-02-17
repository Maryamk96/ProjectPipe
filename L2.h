#pragma once

#include "Pipe.h"

class L2 : public Pipe 
{
public:
    L2(int r, int c);
    bool hasDirection(Direction d) override;
    bool hasLeakage() override;
    PipeType getPipeType() override;
    bool canMoveWaterTo(Direction d) override;
};
