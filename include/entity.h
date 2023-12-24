#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "vec2.h"
#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct entity_move_base {
    float angle;
    Vec2 position;
    Vec2 rotation;
} EntityMoveBase;

typedef struct entity_basic_atribute {
    bool hasPlayable;
    bool canRun;
    bool canAttach;
} EntityBasicAtribute;

typedef struct entity_render_base {
    SDL_Rect rect;
    SDL_Surface surface;
} EntityRenderBase;

typedef struct entity_instance {
    EntityRenderBase render;
    EntityMoveBase transform;
    EntityBasicAtribute atributes;
} EntityInstance;

typedef struct entity_playable_instance {
    int life;

    EntityRenderBase render;
    EntityMoveBase transform;
    EntityBasicAtribute atributes;
} EntityPlayableInstance;

void set_entity_place(EntityInstance *entity, Vec2 place);

#endif
