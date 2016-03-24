#pragma once
#include "../../Engine/PerlinGenerator.hpp"

class Game;
class TerrainTile;
class Entity;
class Peon;
class Stockpile;

class World
{
public:
    World(Game* game);
    ~World();

    Game* GetGame();
    int GetDay();
    std::string GetMonth();
    int GetYear();

    void Update(double deltaTime);
    void Render();
    void ProcessTime();
    void Generate();
    void SpawnPeon(int quantity, const glm::vec2& position);
    void SpawnOrc(int quantity = 1);
    bool IsPassable(const glm::vec2& point);
    TerrainTile* GetTerrainAtPoint(const glm::vec2& point);

    /*
        Gets the Entity with the given ID that is currently colliding with the given point.

        If the give ID is NONE, then it will return any Entity.
    */
    Entity* GetEntityAtPoint(const glm::vec2& point, int entityID = NONE);

    /*
        Finds and returns all Entities with the given ID that are contained
        in the given Rect.

        If the ID given is NONE, it will return all Entity types.
    */
    std::list<Entity*> GetEntitiesInRect(int entityID, const grim::Rect& rect);

    /*
        Finds and returns the first Entity with the given ID.

        This is used to find unique Entities, such as the Obelisk.
    */
    Entity* FindEntity(int entityID);

    /*
        Find Entities with the given ID that are near the given point.

        If the given ID is NONE, then it will search for ALL Entities.
    */
    std::list<Entity*> FindEntitiesInRange(int entityID, const glm::vec2& point, int range);

    /*
        Gets the position that is at the center of the world.
    */
    glm::vec2 GetCenter() const;

private:
    void CleanEntities();

private:
    const static int MAP_SIZE = 64; // The map size, in tiles.
    const static int MAX_TREE_COUNT = 600; // The amount of trees to place on the map.
    const static int MAX_ROCK_COUNT = 3; // The amount of rocks to place on the map.

    Game* m_game;
    PerlinGenerator m_generator;

    std::unordered_map<glm::vec2, std::unique_ptr<TerrainTile> > m_terrain;
    std::list< std::unique_ptr<Entity> > m_entities;

    // Time
    Timer m_worldTimer;
    int m_day;
    int m_month;
    int m_year;
};