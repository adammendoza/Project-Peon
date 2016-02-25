#pragma once

class Game;
class Prop;

class TerrainTile
{
public:
    TerrainTile(Game* game, const Vector2D& position);
    ~TerrainTile();

    void SetPosition(const Vector2D& position);
    Vector2D GetPosition() const;

    void Render();

private:
    const static int TILE_SIZE = 32;

    Game* m_game;
    Vector2D m_position;
    Vector2D m_origin;
    std::string m_spritesheet;
    int m_spriteColumn;
    int m_spriteRow;
};
