#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "vec2.h"

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

typedef struct entity_instance {
    EntityMoveBase transform;
    EntityBasicAtribute atributes;
} EntityInstance;

#endif
