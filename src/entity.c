#include <entity.h>

void set_entity_place( EntityInstance *entity, Vec2 place )
{
    entity->transform.position = place;
}