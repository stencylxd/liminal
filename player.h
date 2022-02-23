// player.h for the player controller
#include "libs/raylib.h"
#include "keybinds.h"

Vector2 player_position = {500, 500};
int player_is_jumping = 0, 
    player_height = 40, 
    // jump variables
    player_prevent_movement = 1, 
    player_jump_speed = 8, 
    player_jump_pressure = 0,
    player_jump_pressure_level = 5,
    player_jump_height = 40,
    player_jump_timer = 0,
    player_can_double_jump = 1,
    player_double_jump_status = 0,
    // strafing variables
    player_speed = 7,
    player_acceleration = 7,
    player_direction = 0,
    player_strafe_time = 0;

Vector2 player_pos_offset = {0, 0};

void UpdatePlayerStrafing() {
    if (GetInputActive(CONTROL_LEFT) && GetInputActive(CONTROL_RIGHT))
        return;
    if (GetInputActive(CONTROL_LEFT)) {
        player_direction = 1;
        if (player_strafe_time < 14)
            player_strafe_time++;
        if (player_acceleration != 0 && player_strafe_time % 2 == 0)
            player_acceleration--;
        player_position.x -= player_speed - player_acceleration;
    }
    if (player_direction == 1 && player_acceleration < 7 && !GetInputActive(CONTROL_LEFT)) {
        player_strafe_time--;
        if (player_strafe_time % 2 == 0)
            player_acceleration++;
        player_position.x -= player_speed - player_acceleration;
    }
    if (GetInputActive(CONTROL_RIGHT)) {
        player_direction = 2;
        if (player_strafe_time < 14)
            player_strafe_time++;
        if (player_acceleration != 0 && player_strafe_time % 2 == 0)
            player_acceleration--;
        player_position.x += player_speed - player_acceleration;
    }
    if (player_direction == 2 && player_acceleration < 7 && !GetInputActive(CONTROL_RIGHT)) {
        player_strafe_time--;
        if (player_strafe_time % 2 == 0)
            player_acceleration++;
        player_position.x += player_speed - player_acceleration;
    }
}

void UpdatePlayerJumping() {
    // check if player is jumping
    if (player_is_jumping > 0) {
        if (GetInputActive(CONTROL_JUMP) && player_can_double_jump && !player_double_jump_status) {
            player_is_jumping = 1;
            player_double_jump_status = 1;
            player_jump_pressure = 0;
            player_jump_timer = 0;
        } 
        if (player_is_jumping == 1) {
            player_position.y -= (player_jump_speed - player_jump_pressure);
            player_jump_timer++;
            if (player_jump_timer % player_jump_pressure_level == 0) 
                player_jump_pressure++;
            if (player_jump_timer > player_jump_height)
                player_is_jumping = 2;
        }
        if (player_is_jumping == 2) {
            player_position.y += (player_jump_speed - player_jump_pressure);
            player_jump_timer--;
            if (player_jump_timer % player_jump_pressure_level == 0 && player_jump_pressure > 0) 
                player_jump_pressure--;
            if (player_jump_timer == 0) {
                player_is_jumping = 0;
                player_double_jump_status = 0;
            }
        }
    }
    // check if user pressed jump button
    if (GetInputActive(CONTROL_JUMP) && player_is_jumping != 2) 
        player_is_jumping = 1;
}

void UpdatePlayerMovement() {
    if (player_prevent_movement) return;
    UpdatePlayerJumping();
    UpdatePlayerStrafing();
}

void DrawPlayer() { 
    Vector2 
        v11 = {player_position.x + player_height, player_position.y - player_height}, 
        v12 = {player_position.x, player_position.y - player_height}, 
        v13 = player_position, 
        v21 = {player_position.x + player_height, player_position.y - player_height}, 
        v22 = {player_position.x + player_height, player_position.y}, 
        v23 = player_position;
    DrawTriangleLines(v11, v12, v13, WHITE);
    DrawTriangleLines(v21, v22, v23, WHITE);
    DrawLine(0, 500, 1000, 500, WHITE);
    //Rectangle rec = {player_position.x - player_pos_offset.x, player_position.y - player_pos_offset.y, player_size, player_size};
    //DrawRectangleRec(rec, WHITE);
    return;
}