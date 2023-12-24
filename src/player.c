#include <wolfenstein.h>

void set_player_angle( Player *player, float value )
{
    player->transform.angle = value;
}
