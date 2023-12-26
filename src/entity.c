#include <entity.h>

void set_entity_place( EntityTransform *entityTransform, Vec2 place )
{
    entityTransform->position = (Vec2) {
        (place.x * cosf(entityTransform->angle)) - (place.x * sinf(entityTransform->angle)),
        (place.y * sinf(entityTransform->angle)) + (place.y * cosf(entityTransform->angle))
    };
}

void set_entity_rotation( EntityTransform *entityTransform, Vec2 rotation )
{
    entityTransform->rotation = (Vec2) {
        (rotation.x * cosf(entityTransform->angle)) - (rotation.x * sinf(entityTransform->angle)),
        (rotation.y * sinf(entityTransform->angle)) + (rotation.y * cosf(entityTransform->angle))
    };
}