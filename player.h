// player.h for the player controller
#include "libs/raylib.h"
#include "keybinds.h"

Vector2 
    player_position         = {500, 500},
    player_pos_offset       = {0, 0};
int player_prevent_movement = 1, 
    player_side_length      = 40,
    // jump variables

    // player_jumping statuses
    // 0 = not jumping
    // 1 = going up
    // -1 = going down
    player_jumping          = 0, 
    player_jump_timer       = 0,
    player_jump_speed       = 10, 
    player_jump_gravity     = 0,
    // has to divide evenly into player_max_jump_height
    player_jump_gravity_max = 5,
    player_max_jump_height  = 50, 

    // strafing variables
    player_speed            = 9,
    player_acceleration     = 9,

    // player_direction keeps last direction after done strafing
    // 0  = no direction yet
    // -1 = left
    // 1  = right
    player_direction        = 0,
    player_strafe_time      = 0,
    player_max_strafe_time  = 14;

void UpdatePlayerStrafing() {
    if (InputDown(CONTROL_LEFT) && InputDown(CONTROL_RIGHT)) return;
    if (InputDown(CONTROL_MOVE)) {
        // 5 here turns CONTROL_LEFT/RIGHT into -1 and 1, which are direction codes.
        player_direction = GetInput() - 5;
        if (player_strafe_time < player_max_strafe_time)
            player_strafe_time++;
        if (player_acceleration && !(player_strafe_time % 2))
            player_acceleration--;
    }
    if (player_acceleration < player_speed && !InputDown(CONTROL_MOVE)) {
        player_strafe_time--;
        if (!(player_strafe_time % 2))
            player_acceleration++;
    }
    player_position.x += player_direction * (player_speed - player_acceleration);
}

//// STILL REWRITING!!!!
//void UpdatePlayerJumping() {
//    // check if player is jumping
//    if (InputDown(CONTROL_JUMP) && player_jumping == 0)
//        player_jumping = 1;
//    if (player_jumping) {
//        player_jump_timer++;
//        player_position.y -= player_jumping * (player_jump_speed - player_jump_gravity);
//    }
//    return;
//}

void UpdatePlayerMovement() {
    if (player_prevent_movement) return;
    UpdatePlayerJumping();
    UpdatePlayerStrafing();
}

void DrawPlayer() { 
    Vector2 
        v11 = {player_position.x + player_side_length, player_position.y - player_side_length}, 
        v12 = {player_position.x, player_position.y - player_side_length}, 
        v13 = player_position,
        v21 = v11, 
        v22 = {player_position.x + player_side_length, player_position.y}, 
        v23 = v13;
    DrawTriangleLines(v11, v12, v13, WHITE);
    DrawTriangleLines(v21, v22, v23, WHITE);
    // temp line for "collision testing"
    DrawLine(0, 500, 1000, 500, WHITE);
    return;
}
