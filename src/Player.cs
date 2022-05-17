using System.Numerics;
using static LiminalGame.Keybinds;
using Raylib_cs;
using static Raylib_cs.Raylib;

namespace LiminalGame {
    public static class Player {
        public static Vector2 
            PlayerPosition        = new Vector2(500, 500),
            PlayerPosOffset       = Vector2.Zero;
        private static Vector2
            PlayerTriangleVec0    = new Vector2(),
            PlayerTriangleVec1    = new Vector2(),
            PlayerTriangleVec2    = new Vector2();
        public static bool
            PlayerPreventMovement = false,
            PlayerJumping         = false;
        public static int 
            PlayerSideLength      = 40,
            // jump variables
            PlayerJumpTimer       = 0,
            PlayerJumpSpeed       = 10, 
            PlayerJumpGravity     = 0,
            // has to divide evenly into PlayerJumpHeightMax
            PlayerJumpGravityMax  = 5,
            PlayerJumpHeightMax   = 50, 
            // strafing variables
            PlayerSpeed           = 9,
            PlayerAcceleration    = 9,
            // player_direction keeps last direction after done strafing
            // 0  = no direction yet
            // -1 = left
            // 1  = right
            PlayerDirection       = 0,
            PlayerStrafeTime      = 0,
            PlayerMaxStrafeTime   = 14;

        public static void UpdatePlayerStrafing() {
            if (InputDown(CONTROL_LEFT) && InputDown(CONTROL_RIGHT)) return;
            if (InputDown(CONTROL_MOVE)) {
                // 5 here turns CONTROL_LEFT/RIGHT into -1 and 1, which are direction codes.
                PlayerDirection = GetInput() - 5;
                if (PlayerStrafeTime < PlayerMaxStrafeTime)
                    PlayerStrafeTime++;
                if (PlayerAcceleration > 0 && PlayerStrafeTime % 2 == 0)
                    PlayerAcceleration--;
            }
            if (PlayerAcceleration < PlayerSpeed && !InputDown(CONTROL_MOVE)) {
                PlayerStrafeTime--;
                if (PlayerStrafeTime % 2 == 0)
                    PlayerAcceleration++;
            }
            PlayerPosition.X += PlayerDirection * (PlayerSpeed - PlayerAcceleration);
        }

        // not done at all
        public static void UpdatePlayerJumping() {
            // check if player pressed the jump button
            if (InputDown(CONTROL_JUMP) && !PlayerJumping)
                PlayerJumping = true;
            // do the jumping part of things
            if (PlayerJumping) {
                PlayerJumpTimer++;
                //PlayerPosition.Y -= PlayerJumping ? 1 : 0 * (PlayerJumpSpeed - PlayerJumpGravity);
            }
            return;
        }

        public static void UpdatePlayerMovement() {
            if (PlayerPreventMovement) return;
            UpdatePlayerJumping();
            UpdatePlayerStrafing();
        }

        public static void DrawPlayer() { 
            PlayerTriangleVec0.X = PlayerPosition.X + PlayerSideLength;
            PlayerTriangleVec0.Y = PlayerPosition.Y - PlayerSideLength;
            PlayerTriangleVec1.X = PlayerPosition.X;
            PlayerTriangleVec1.X = PlayerPosition.Y - PlayerSideLength;
            PlayerTriangleVec2.X = PlayerPosition.X + PlayerSideLength;
            PlayerTriangleVec2.Y = PlayerPosition.Y;
            DrawTriangleLines(PlayerTriangleVec0, PlayerTriangleVec1, PlayerPosition, Color.WHITE);
            DrawTriangleLines(PlayerTriangleVec0, PlayerTriangleVec2, PlayerPosition, Color.WHITE);
            // temp line for "collision testing"
            DrawLine(0, 500, 1000, 500, Color.WHITE);
            return;
        }
    }
}