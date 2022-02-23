// main.c for liminal source
#include "libs/discord.h"
#include "libs/raylib.h"
#include "player.h"

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
    player_prevent_movement = 0;
    while (!WindowShouldClose()) {
        DiscordInvoke();
        UpdatePlayerMovement();
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(TextFormat("time: %d", player_strafe_time), 10, 10, 20, WHITE);
        DrawText(TextFormat("direction: %d", player_direction), 10, 30, 20, WHITE);
        DrawText(TextFormat("accel: %d", player_acceleration), 10, 70, 20, WHITE);
        DrawPlayer();
        EndDrawing();
    }
    return 0;
}
