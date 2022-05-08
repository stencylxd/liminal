using System.Numerics;
using static LiminalGame.Keybinds;
using Raylib_cs;
using static Raylib_cs.Raylib;

namespace LiminalGame {
    public static class Player {
        // player.h for the player controller
        public static Vector2 
            player_position         = new Vector2(500, 500),
            player_pos_offset       = Vector2.Zero;
        public static bool
            PlayerPreventMovement = false,
            PlayerJumping = false;

        public static int 
            PlayerSideLength      = 40,
            // jump variables
            PlayerJumpTimer       = 0,
            PlayerJumpSpeed       = 10, 
            PlayerJumpGravity     = 0,
            // has to divide evenly into PlayerJumpHeightMax
            PlayerJumpGravityMax = 5,
            PlayerJumpHeightMax  = 50, 

            // strafing variables
            PlayerSpeed            = 9,
            PlayerAcceleration     = 9,

            // player_direction keeps last direction after done strafing
            // 0  = no direction yet
            // -1 = left
            // 1  = right
            player_direction        = 0,
            player_strafe_time      = 0,
            player_max_strafe_time  = 14;

        public static void UpdatePlayerStrafing() {
            if (InputDown(CONTROL_LEFT) && InputDown(CONTROL_RIGHT)) return;
            if (InputDown(CONTROL_MOVE)) {
                // 5 here turns CONTROL_LEFT/RIGHT into -1 and 1, which are direction codes.
                player_direction = GetInput() - 5;
                if (player_strafe_time < player_max_strafe_time)
                    player_strafe_time++;
                if (PlayerAcceleration > 0 && player_strafe_time % 2 == 0)
                    PlayerAcceleration--;
            }
            if (PlayerAcceleration < PlayerSpeed && !InputDown(CONTROL_MOVE)) {
                player_strafe_time--;
                if (player_strafe_time % 2 == 0)
                    PlayerAcceleration++;
            }
            player_position.X += player_direction * (PlayerSpeed - PlayerAcceleration);
        }

        public static void UpdatePlayerJumping() {
            // check if player pressed the jump button
            if (InputDown(CONTROL_JUMP) && !PlayerJumping)
                PlayerJumping = true;
            // do the jumping part of things
            if (PlayerJumping) {
                PlayerJumpTimer++;
                player_position.Y -= PlayerJumping ? 1 : 0 * (PlayerJumpSpeed - PlayerJumpGravity);
            }
            return;
        }

        public static void UpdatePlayerMovement() {
            if (PlayerPreventMovement) return;
            UpdatePlayerJumping();
            UpdatePlayerStrafing();
        }

        public static void DrawPlayer() { 
            Vector2 
                v11 = new Vector2(player_position.X + PlayerSideLength, player_position.Y - PlayerSideLength), 
                v12 = new Vector2(player_position.X, player_position.Y - PlayerSideLength), 
                v13 = player_position,
                v21 = v11, 
                v22 = new Vector2(player_position.X + PlayerSideLength, player_position.Y), 
                v23 = v13;
            DrawTriangleLines(v11, v12, v13, Color.WHITE);
            DrawTriangleLines(v21, v22, v23, Color.WHITE);
            // temp line for "collision testing"
            DrawLine(0, 500, 1000, 500, Color.WHITE);
            return;
}

    }
}