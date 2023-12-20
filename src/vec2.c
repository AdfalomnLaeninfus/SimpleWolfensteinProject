#include <math.h>
#include <vec2.h>

float vec2_dot( Vec2 v1, Vec2 v2 )
{
    return (v1.x * v2.x) + (v1.y * v2.y);
}

float vec2_lenght( Vec2 v1, Vec2 v2 ) {
    return sqrtf( vec2_dot( v1, v2 ) );
}
