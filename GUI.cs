using System;
using System.Numerics;
using Raylib_cs;
using static Raylib_cs.Raylib;

namespace LiminalGame
{
    public static class GUI
    {
        public static int XMiddleBase, YMiddleBase, WindowWidth, WindowHeight;
        public static void DrawCursor() => DrawCircleGradient(GetMouseX(), GetMouseY(), 5, Color.GRAY, Color.WHITE);
        public static void DrawCredit() => DrawText("stencylxd @ 2022", 0, WindowHeight - 11, 11, Color.WHITE);
        public static int XMiddle(Texture2D tex) => (XMiddleBase - (tex.width / 2));
        public static int YMiddle(Texture2D tex) => (YMiddleBase - (tex.height / 2));
        // RectHover() checks if the cursor intersects with a rect
        public static bool RectHover(Rectangle rect) {
            Vector2 pos = GetMousePosition();
            Console.WriteLine(pos.X + " " + pos.Y);
            if (pos.X > rect.x && pos.X < rect.x + rect.width &&
                pos.Y > rect.y && pos.Y < rect.y + rect.height)
            return true; // if cursor intersects rect
            return false; // uh or not
        }
    }
}
