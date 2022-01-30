// main.c for liminal source
#include "libs/discord.h"
#include "libs/raylib.h"
#include "player.h"
#include "color.h"

int main() {
    // Setup discord
    if (SetupDiscord(861353865081258025)) 
        SetActivity("The player is playing");
    // Setup basic stuff
    InitAudioDevice();
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "liminal");
    SetConfigFlags(FLAG_MSAA_4X_HINT|FLAG_VSYNC_HINT);
    SetTargetFPS(GetMonitorRefreshRate(0));
    DisableCursor();
    SetWindowMonitor(0);
    SetWindowPosition(0, 0);
    SetWindowIcon(LoadImage("resources/icon.png"));
    //Texture bg0 = LoadTexture("resources/textures/bg0.png");
    //Rectangle bg0_rect = {0, 0, GetMonitorWidth(0), GetMonitorHeight(0)};
    player_prevent_movement = 0;
    int jump_timer_max = 0;
    while (!WindowShouldClose()) {
        DiscordInvoke();
        UpdatePlayerMovement();
        BeginDrawing();
        ClearBackground(NIGHTTIME);
        //DrawTextureRec(bg0, bg0_rect, (Vector2){0, 0}, WHITE);
        DrawText(TextFormat("jump_timer: %d", player_jump_timer), 10, 10, 20, WHITE);
        DrawText(TextFormat("is_jumping: %d", player_is_jumping), 10, 30, 20, WHITE);
        if (jump_timer_max < player_jump_timer) jump_timer_max = player_jump_timer;
        DrawText(TextFormat("jump_timer_max: %d", jump_timer_max), 10, 50, 20, WHITE);
        DrawText(TextFormat("double_jump_status: %d", player_double_jump_status), 10, 70, 20, WHITE);
        DrawPlayer();
        EndDrawing();
    }
    return 0;
}
