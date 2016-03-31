#pragma once

class Game;
class Prop;

class TerrainTile
{
public:
    TerrainTile(Game* game, const glm::vec2& position);
    ~TerrainTile();

    void SetPosition(const glm::vec2& position);
    glm::vec2 GetPosition() const;

    void Render(grim::graphics::SpriteBatch& spriteBatch);

private:
    const static int TILE_SIZE = 32;

    Game* m_game;
    glm::vec2 m_position;
    glm::vec3 m_rotation;
    glm::vec3 m_scale;
    glm::vec2 m_origin;
    int m_spriteColumn;
    int m_spriteRow;

    std::unique_ptr<grim::graphics::Sprite> m_sprite;
};
