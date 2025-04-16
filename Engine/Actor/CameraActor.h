#pragma once

#include "Actor.h"

namespace Blue
{
    class CameraActor : public Actor
    {
    public:
        CameraActor();

        virtual void Tick(float deltaTime);
    private:
        void Move(float deltaTime);
        void Rotate();
    };
}
