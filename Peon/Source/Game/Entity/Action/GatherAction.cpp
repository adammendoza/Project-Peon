#include "PCH.hpp"
#include "GatherAction.hpp"
#include "../../Game.hpp"
#include "MoveAction.hpp"
#include "DepositAction.hpp"
#include "../Monster.hpp"
#include "../Resource.hpp"
#include "../../Item/Inventory.hpp"
#include "../../Map/Map.hpp"

GatherAction::GatherAction(Monster* owner, Resource* target) :
    Action(owner, "Gather"),
    m_target(target),
    m_gatherTime(3),
    m_ownerInventory(nullptr)
{
    m_ownerInventory = m_owner->GetInventory();

    // If the target resource doesn't exist, just complete the action.
    if (m_target == nullptr)
    {
        Abort();
        return;
    }

    // If the target resource is full or dead, just complete the action.
    if (m_target->IsFull() || m_target->IsDead())
    {
        Abort();
        return;
    }

    // We are clear to begin the GatherAction. Add this peon to the target resource.
    m_target->AddPeon();
}

GatherAction::~GatherAction()
{
}

void GatherAction::Update(double deltaTime)
{
    if (m_target == nullptr)
    {
        // The target is null, which isn't supposed to happen. Abort.
        Abort();
        return;
    }

    if (m_target->IsDead())
    {
        Complete();
        return;
    }

    ItemType item = m_target->GetItem();

    // Check if we are in range of the resource
    Vector2D targetCenter = m_target->GetPositionCenter();
    Vector2D monsterCenter = m_owner->GetPositionCenter();
    double distance = Vector2D::Distance(monsterCenter, targetCenter);

    if (distance <= MIN_GATHER_DISTANCE)
    {
        // We are close enough. We can start gathering.
        if (!m_timer.IsStarted())
        {
            m_gatherTime = Random::Generate(5000, 10000);
            m_timer.Start();
        }
        else
        {
            if (m_timer.GetTime() > m_gatherTime)
            {
                m_target->Damage();
                m_timer.Stop();

                m_owner->GetGame()->PlaySound("woodcutting_00"); // TODO different sounds
                m_ownerInventory->GiveItem(item, (int)Random::Generate(1, 3));
                m_owner->PushAction(std::make_unique<DepositAction>(m_owner, item, -1));
            }
        }
    }
    else
    {
        // We aren't close enough. Move to the resource.
        m_owner->PushAction(std::make_unique<MoveAction>(m_owner, m_target->GetPosition()));
    }
}

void GatherAction::Complete()
{
    // If the target resource exists, remove this peon from it.
    if (m_target != nullptr)
    {
        m_target->RemovePeon();
    }

    Action::Complete();
}

void GatherAction::Abort()
{
    Action::Complete();
}

void GatherAction::FindNode()
{
    // Get any adjacent resource entities
}