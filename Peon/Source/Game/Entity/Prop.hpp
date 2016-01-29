#pragma once
// Tyren Review: Never include PCH in headers
#include "../../PCH.hpp"

#include "Entity.hpp"

// Tyren Review: What does this class do? 
class Prop : public Entity
{
public:
    Prop(Game* game, Vector2D position);
    virtual ~Prop();

    virtual void Update() = 0;
    virtual void Render() = 0;
};
