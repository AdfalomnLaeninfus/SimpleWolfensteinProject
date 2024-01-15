#include <math.h>
#include <vec2.h>

float vec2_dot( const Vec2f v1, const Vec2f v2 ) { return ( v1.x * v2.x ) + ( v1.y * v2.y ); }
float vec2_lenght( const Vec2f v1 ) { return sqrtf( vec2_dot( v1, v1 ) ); }

Vec2f vec2i_to_vec2f( Vec2i *v ) { return ( Vec2f ) { ( int ) v->x, ( int ) v->y }; }
Vec2i vec2f_to_vec2i( Vec2f *v ) { return ( Vec2i ) { ( float ) v->x, ( float ) v->y }; }

Vec2f vec2_add( const Vec2f *v1, float value ) { return ( Vec2f ) { v1->x + value, v1->y + value }; }
Vec2f vec2_sub( const Vec2f *v1, float value ) { return ( Vec2f ) { v1->x - value, v1->y - value }; }
Vec2f vec2_mul( const Vec2f *v1, float value ) { return ( Vec2f ) { v1->x * value, v1->y * value }; }
Vec2f vec2_div( const Vec2f *v1, float value ) { return ( Vec2f ) { v1->x / value, v1->y / value }; }

Vec2f vec2_rotate( const Vec2f *v1, const float angle )
{
    return ( Vec2f ) {
        ( v1->x * cosf( angle ) ) - ( v1->x * sinf( angle ) ),
        ( v1->y * sinf( angle ) ) + ( v1->y * cosf( angle ) )
    };
}
