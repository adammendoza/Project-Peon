#include "PCH.hpp"
#include "Obelisk.hpp"
#include "../Game.hpp"
#include "../../Engine/Renderer.hpp"

Obelisk::Obelisk(Game* game, const glm::vec2& position) :
    Prop(game, position, OBELISK)
{
    m_origin = glm::vec2(48, 240);
    m_hitBox = Rect(-36, -30, 73, 80);
}

Obelisk::~Obelisk()
{
}

void Obelisk::Update(double deltaTime)
{
    if (IsDead())
    {
        Debug::Log("Obelisk is dead. Game over.");
    }
}

void Obelisk::Render()
{
    grim::Renderer* renderer = m_game->GetRenderer();
    renderer->RenderSprite("obelisk", 0, 0, (int)(m_position.x - m_origin.x), (int)(m_position.y - m_origin.y), 96, 288);

    Entity::Render();
}
