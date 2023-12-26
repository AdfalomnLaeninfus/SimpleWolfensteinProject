#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "vec2.h"
#include <math.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct entity_move_base {
    float angle;
    Vec2 position;
    Vec2 rotation;
} EntityTransform_t;

typedef struct entity_basic_atribute {
    bool hasPlayable;
    bool canRun;
    bool canAttach;
} EntityBasicAtribute_t;

typedef struct entity_render_base {
    SDL_Rect rect;
    SDL_Surface surface;
} EntityRenderBase;

typedef struct entity_instance {
    EntityRenderBase render;
    EntityTransform_t transform;
    EntityBasicAtribute_t atributes;
} EntityInstance_t;

typedef struct entity_playable_instance {
    int life;

    EntityRenderBase render;
    EntityTransform_t transform;
    EntityBasicAtribute_t atributes;
} EntityPlayableInstance_t;

void set_entity_place( EntityTransform_t *entityTransform, Vec2 place );
void set_entity_rotation( EntityTransform_t *entityTransform, Vec2 rotation );

#endif
