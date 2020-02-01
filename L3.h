#pragma once

#include "Pipe.h"

class L3 : public Pipe
{
public:
    L3(int r, int c);
    bool hasDirection(Direction d) override;
    bool hasLeakage() override;
    PipeType getPipeType() override;
};
