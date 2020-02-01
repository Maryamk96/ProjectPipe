#pragma once

#include "Pipe.h"

class L1 : public Pipe
{
public:
    L1(int r, int c);
    bool hasDirection(Direction d) override;
    bool hasLeakage() override;
    PipeType getPipeType() override;
};
