#ifndef _VEC2_H_
#define _VEC2_H_

typedef struct vec2 {
    float x;
    float y;
} Vec2;

float vec2_dot( Vec2 v1, Vec2 v2 );
float vec2_lenght( Vec2 v1 );

#endif