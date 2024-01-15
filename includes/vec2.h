#ifndef _VEC2_H_
#define _VEC2_H_

typedef struct vec2f { float x, y; } Vec2f;
typedef struct vec2i { int x, y; } Vec2i;

float vec2_dot( Vec2f v1, Vec2f v2 );
float vec2_lenght( Vec2f v1 );

extern Vec2i vec2f_to_vec2i( Vec2i );
extern Vec2f vec2i_to_vec2f( Vec2f );

extern Vec2f vec2_add( const Vec2f *v1, const float value );
extern Vec2f vec2_sub( const Vec2f *v1, const float value );
extern Vec2f vec2_mul( const Vec2f *v1, const float value );
extern Vec2f vec2_div( const Vec2f *v1, const float value );

extern Vec2f vec2_rotate( const Vec2f *v1, const float angle);

#endif
