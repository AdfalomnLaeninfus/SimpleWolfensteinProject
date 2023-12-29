#include <entity.h>

void entity_move_forward( EntityTransform_t *entityTransform, float velocity )
{
    entityTransform->position.x = entityTransform->position.x + cosf(entityTransform->rotation.x) * velocity;
    entityTransform->position.y = entityTransform->position.y - sinf(entityTransform->rotation.x) * velocity;
    printf("<EntityPosition(x: %.1f, y:%.1f)>\n", entityTransform->position.x, entityTransform->position.y);
}

void set_entity_place( EntityTransform_t *entityTransform, Vec2 place )
{
    entityTransform->position = place;
}

void set_entity_rotation( EntityTransform_t *entityTransform, Vec2 rotation )
{
    entityTransform->rotation = (Vec2) {
        rotation.x > 180.0f ? rotation.x - 180.0f : rotation.x < 0.0f ? rotation.x + 180.0f : rotation.x,
        rotation.y > 180.0f ? rotation.y - 180.0f : rotation.y < 0.0f ? rotation.y + 180.0f : rotation.y
    };

    // printf("<EntityRotation(x: %.1f, y:%.1f)>\n", entityTransform->rotation.x, entityTransform->rotation.y);
}
