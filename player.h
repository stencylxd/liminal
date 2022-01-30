// player.h for the player controller
#include "libs/raylib.h"
Vector2 player_position = {500, 500};
int player_is_jumping = 0, 
    player_prevent_movement = 1, 
    player_can_double_jump = 1,
    player_size = 50, 
    player_height = 40, 
    player_jump_speed = 7, 
    player_jump_height = 40,
    player_jump_timer = 0,
    player_double_jump_status = 0,
    player_jump_pressure = 0;
Vector2 player_pos_offset = {0, 0};

void UpdatePlayerMovement() {
    if (player_prevent_movement) return;
    UpdatePlayerJumping();

}

void UpdatePlayerJumping() {
    // check if player is jumping
    if (player_is_jumping > 0) {
        if ((IsKeyPressed(KEY_SPACE) 
                || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) 
                && player_can_double_jump
                && !player_double_jump_status) {
            player_is_jumping = 1;
            player_double_jump_status = 1;
            player_jump_timer = 0;
            player_jump_pressure = 0;
        }
        if (player_is_jumping == 1) {
            player_position.y -= (player_jump_speed - player_jump_pressure);
            player_jump_timer++;
            if (player_jump_timer > player_jump_height)
                player_is_jumping = 2;
        }
        if (player_is_jumping == 2) {
            player_position.y += (player_jump_speed - player_jump_pressure);
            player_jump_timer--;
            if (player_jump_timer == 0) {
                player_is_jumping = 0;
                player_double_jump_status = 0;
            }
        }
    }
    // check if user pressed jump button
    if ((IsKeyPressed(KEY_SPACE) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) && player_is_jumping != 2) 
        player_is_jumping = 1;
}


void DrawPlayer() { 
    DrawTriangleLines(
        (Vector2){player_position.x - player_size+2, player_position.y + player_size+2}, 
        (Vector2){player_position.x + player_size+2, player_position.y + player_size+2}, 
        (Vector2){player_position.x, player_position.y - player_height}, WHITE);
    return;
}