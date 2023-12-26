#include <entity.h>

void set_entity_place( EntityTransform_t *entityTransform, Vec2 place )
{
    entityTransform->position = (Vec2) {
        place.x * cosf( toRadians( entityTransform->angle ) ),
        place.y * sinf( toRadians( entityTransform->angle ) )
    };
}

void set_entity_rotation( EntityTransform_t *entityTransform, Vec2 rotation )
{
    entityTransform->rotation = (Vec2) {
        (rotation.x * cosf(entityTransform->angle)) - (rotation.x * sinf(entityTransform->angle)),
        (rotation.y * sinf(entityTransform->angle)) + (rotation.y * cosf(entityTransform->angle))
    };
}