#pragma once

#include "Pipe.h"

class Column : public Pipe 
{
public:
    Column(int r, int c);
    bool hasDirection(Direction d) override;
    bool hasLeakage() override;
    PipeType getPipeType() override;
};
