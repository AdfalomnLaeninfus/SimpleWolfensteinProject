#include <entity.h>

void set_entity_place( EntityInstance *entity, Vec2 place )
{
    entity->transform.position = place;
}

void set_entity_playable_place( EntityPlayableInstance *entity, Vec2 place )
{
    entity->transform.position = place;
}