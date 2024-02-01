#include <entity.h>

EntityInstance_t entity_create( EntityRenderBase render, EntityBasicAttribute_t attributes, EntityTransform_t transform )
{
    return ( EntityInstance_t ) { render, transform, attributes };
}

void set_entity_position( EntityTransform_t *entityTransform, Vec2f position ) { entityTransform->position = position; }

void set_entity_rotation( EntityTransform_t *entityTransform, Vec2f rotation )
{
    entityTransform->rotation = ( Vec2f ) {
        rotation.x > PI_TIMES_TWO ? rotation.x - PI_TIMES_TWO : rotation.x < 0.0f ? rotation.x + PI_TIMES_TWO : rotation.x,
        rotation.y > PI_TIMES_TWO ? rotation.y - PI_TIMES_TWO : rotation.y < 0.0f ? rotation.y + PI_TIMES_TWO : rotation.y
    };
}

Vec2f get_entity_position( EntityInstance_t *entity ) { return entity->transform.position; }
Vec2f get_entity_rotation( EntityInstance_t *entity ) { return entity->transform.rotation; }
