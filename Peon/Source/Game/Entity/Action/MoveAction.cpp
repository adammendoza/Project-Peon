#include "PCH.hpp"
#include "MoveAction.hpp"
#include "../Monster.hpp"
#include "../../Game.hpp"

MoveAction::MoveAction(Monster* owner, const Vector2D& destination) :
    Action(owner, MOVE_ACTION, "Move"),
    m_destination(destination),
    m_followTarget(nullptr),
    m_range(0),
    m_hopOffset(0),
    m_hopIndex(0),
    m_hopAmp(6),
    m_hopFreq(15)
{
    m_hopFreq += Random::Generate(-3, 3);
}

MoveAction::~MoveAction()
{
    m_owner->SetPositionOffset(Vector2D(0, 0));
}


Vector2D MoveAction::GetDestination() const
{
    return m_destination;
}

void MoveAction::Update(double deltaTime)
{
    // If we have a follow target, update our destination.
    if (m_followTarget != nullptr)
    {
        m_destination = m_followTarget->GetPosition();
    }

    m_hopIndex += deltaTime;
    m_hopOffset = abs(sin(m_hopIndex * m_hopFreq) * m_hopAmp);
    m_owner->SetPositionOffset(Vector2D(0, -m_hopOffset));

    Vector2D position = m_owner->GetPosition();
    
    /*
    if (position == m_destination)
    {
        Complete();
        return;
    }
    */

    Vector2D start = position;
    double distance = Vector2D::Distance(start, m_destination);
    Vector2D direction = m_destination - start;
    direction.Normalize();

    position += direction * (m_owner->GetMoveSpeed() * deltaTime);

    if (Vector2D::Distance(position, m_destination) <= m_range)
    {
        Complete();
    }

    if (Vector2D::Distance(start, position) > distance)
    {
        position = m_destination;
        Complete();
    }
        
    m_owner->SetPosition(position);
}

void MoveAction::SetFollowTarget(Entity* target)
{
    m_followTarget = target;
}

void MoveAction::SetMinimumRange(int range)
{
    m_range = range;
}