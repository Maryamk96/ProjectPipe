#pragma once

#include "Pipe.h"

class Plus : public Pipe {
public:
    Plus(int r, int c);
    bool hasDirection(Direction d) override;
    bool hasLeakage() override;
    PipeType getPipeType() override;
};
