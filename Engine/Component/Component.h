#pragma once

namespace Blue
{
    class Actor;
    
    class Component
    {
    public:
        Component();
        virtual ~Component();

        virtual void BeginPlay();
        virtual void Tick(float deltaTime);
        virtual void Draw();

        Actor* GetOwner() const;
        void SetOwner(Actor* newOwner);

    protected:
        Actor* owner  = nullptr;
    };
}
