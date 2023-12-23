#ifndef _VEC2_H_
#define _VEC2_H_

typedef struct vec2 {
    float x;
    float y;
} Vec2;

float vec2_dot( Vec2 v1, Vec2 v2 );
float vec2_lenght( Vec2 v1 );

Vec2 vec2_add( const Vec2 *v1, const Vec2 *v2 );
Vec2 vec2_sub( const Vec2 *v1, const Vec2 *v2 );
Vec2 vec2_mul( const Vec2 *v1, const Vec2 *v2 );
Vec2 vec2_div( const Vec2 *v1, const Vec2 *v2 );

Vec2 vec2_rotate( const Vec2 *v1, const float angle);

#endif
