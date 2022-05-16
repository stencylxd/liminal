using System;
using static LiminalGame.GUI;
using static LiminalGame.Menu;
using static LiminalGame.Player;
using Raylib_cs;
using static Raylib_cs.Raylib;

namespace LiminalGame
{
    /* note: I DID NOT STEAL ANY OF THIS CODE. This was leftover from a project I was working on a while back. */
    public class General
    {
        public static int CurrentFrame = 0, ElapsedSeconds = 0;
        public static State CurrentState = State.MainMenu;
        public static Random Rand = new Random();
        public enum State : int {
            MainMenu = 0,
            Game = 1
        }
        static void Main()
        {
            InitAudioDevice();
            InitWindow(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()), "Liminal");
            SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
            HideCursor();
            SetWindowPosition(0, 0);
            SetWindowIcon(LoadImage("resources/icon.png"));
            // Init the middle align variables and screen dimension variables
            XMiddleBase = GetScreenWidth() / 2;
            YMiddleBase = GetScreenHeight() / 2;
            WindowWidth = GetScreenWidth();
            WindowHeight = GetScreenHeight();
            // Setup main menu
            SetMenuItem("Start", 0);
            SetMenuItem("Options", 1);
            SetMenuItem("Exit", 2);
            InitMenu();

            // Game Loop
            while (!WindowShouldClose())
            {
                // YOU SHALL NOT MESS UP MY TIMERS
                while (!IsWindowFocused()) {
                    BeginDrawing();
                    ClearBackground(Color.BLACK);
                    DrawMenuBackgroundAnimation(0.5f);
                    DrawText("Window is unfocused!", XMiddleBase-150, YMiddleBase-15, 30, Color.SKYBLUE);
                    DrawCursor();
                    EndDrawing();
                }
                // Count frames / seconds elapsed
                CurrentFrame++;
                if (CurrentFrame == GetMonitorRefreshRate(GetCurrentMonitor())) {
                    CurrentFrame = 0;
                    ElapsedSeconds++;
                }
                BeginDrawing();
                ClearBackground(Color.BLACK);
                // Show main menu
                if (CurrentState == State.MainMenu) {   
                    //DrawMenuBackgroundAnimation(0.5f);
                    //DrawMenu(.5f);
                    UpdatePlayerMovement();
                    DrawPlayer();
                    DrawCredit();
                    DrawCursor();
                    EndDrawing();
                    continue;
                }
                EndDrawing();
            }
            CloseWindow();
        }
    }
}
