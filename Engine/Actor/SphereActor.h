#pragma once

#include "Actor.h"

namespace Blue
{
    class SphereActor : public Actor
    {
    public:
        SphereActor();
        ~SphereActor() = default;

        void Tick(float deltaTime) override;
    };    
}
