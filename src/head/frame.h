#pragma once
#include "raylib.h"
class frame{
    public:
    unsigned numFrames;
    Rectangle frameRec ;
    unsigned frameDelay;
    unsigned frameDelayCounter;
    unsigned frameIndex;
    int frameWidth;
};