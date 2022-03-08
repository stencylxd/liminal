// main.c for liminal source
#include "libs/discord.h"
#include "libs/raylib.h"
#include "player.h"

int main() {
    // Setup discord
    if (SetupDiscord(861353865081258025)) 
        SetActivity("The player is playing");
    // setup basic stuff
    InitAudioDevice();
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "liminal");
    SetConfigFlags(FLAG_MSAA_4X_HINT|FLAG_VSYNC_HINT);
    SetTargetFPS(GetMonitorRefreshRate(0));
    DisableCursor();
    SetWindowMonitor(0);
    SetWindowPosition(0, 0);
    SetWindowIcon(LoadImage("resources/icon.png"));
    player_prevent_movement = 0;
    while (!WindowShouldClose()) {
        DiscordInvoke();
        BeginDrawing();
        ClearBackground(BLANK);
        UpdatePlayerMovement();
        DrawText(TextFormat("time: %d", player_jump_timer), 10, 10, 20, WHITE);
        DrawText(TextFormat("gravity: %d", player_jump_gravity), 10, 30, 20, WHITE);
        DrawText(TextFormat("jumping: %d", player_jumping), 10, 70, 20, WHITE);
        DrawPlayer();
        EndDrawing();
    }
    return 0;
}
