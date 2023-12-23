#include <math.h>
#include <vec2.h>

float vec2_dot( const Vec2 v1, const Vec2 v2 )
{
    return ( v1.x * v2.x ) + ( v1.y * v2.y );
}

float vec2_lenght( const Vec2 v1 ) {
    return sqrtf( vec2_dot( v1, v1 ) );
}

Vec2 vec2_add( const Vec2 *v1, const Vec2 *v2 )
{
    return (Vec2) {
        v1->x + v2->x,
        v1->y + v2->y
    };
}

Vec2 vec2_sub( const Vec2 *v1, const Vec2 *v2 )
{
    return (Vec2) {
        v1->x - v2->x,
        v1->y - v2->x
    };
}

Vec2 vec2_mul( const Vec2 *v1, const Vec2 *v2 )
{
    return (Vec2) {
        v1->x * v2->x,
        v1->y * v2->y
    };
}

Vec2 vec2_div( const Vec2 *v1, const Vec2 *v2 )
{
    return (Vec2) {
        v1->x / v2->x,
        v1->y / v2->y
    };
}

Vec2 vec2_rotate( const Vec2 *v1, const float angle)
{
    return (Vec2) {
        ( v1->x * cosf(angle) ) - ( v1->x * sinf(angle) ),
        ( v1->y * sinf(angle) ) - ( v1->y * cosf(angle) )
    };
}
