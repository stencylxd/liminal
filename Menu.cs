using System.Numerics;
using static LiminalGame.GUI;
using Raylib_cs;
using static Raylib_cs.Raylib;

namespace LiminalGame
{
    public static class Menu
    {
         public static int 
            BeginMenuItemsX = 100, 
            BeginMenuItemsY = 100, 
            MenuItemsBoxOffsetX = 10,
            MenuItemsBoxOffsetY = 60,
            MenuItemLineThickness = 1, 
            MenuItemWidth = 200, 
            MenuItemHeight = 50;
        // DrawMenuBackgroundAnimation displays STARS in the background
        private static Rectangle[] StarRects = new Rectangle[40];
        private static int[,] StarDetails = new int[40, 2];
        public static void DrawMenuBackgroundAnimation(float opacity) {
            for (int x = 39; x != -1; x--) {
                // Check if rect is offscreen / not made
                if (StarRects[x].x > WindowWidth || StarRects[x].x == 0) {
                    // Make new rect
                    StarRects[x] = new Rectangle(
                        StarRects[x].x == 0 ? GetRandomValue(1, WindowWidth) : 1, 
                        GetRandomValue(1, WindowHeight), 
                        GetRandomValue(2, 4), GetRandomValue(2, 4));
                    // NEW rotation and speed
                    StarDetails[x, 0] = GetRandomValue(0, 90);
                    StarDetails[x, 1] = GetRandomValue(3, 8);
                }
                // Move star
                StarRects[x].x += StarDetails[x, 1];
                // Draw star
                DrawRectanglePro(StarRects[x], Vector2.One, StarDetails[x, 0], ColorAlpha(Color.WHITE, opacity));
            }
        }
          
        // ShowMainMenu() shows the main menu. wow
        private static Rectangle[] MenuItemsRects = new Rectangle[10];
        private static string[] MenuItemsText = new string[10];
        private static int MenuItemsCount = 0;
        public static void SetMenuItem(string Title, int Id) {
            if (Id < 0 || Id > 40) return;
            MenuItemsCount++;
            MenuItemsText[Id] = Title;
        }

        public static void RemoveMenuItem(int Id) {
            if (Id < 0 || Id > 40) return;
            if (MenuItemsText[Id] != string.Empty) {
                MenuItemsRects[Id] = new Rectangle();
                MenuItemsText[Id] = string.Empty;
                MenuItemsCount--;
            }
        }
        public static void RemoveAllMenuItems() {
            for (int i = 0; i < 40; i++) 
                RemoveMenuItem(i);
        }

        public static void InitMenu() {
            MenuItemsRects = new Rectangle[10];
            for (int i = 0; i != 10; i++) 
                MenuItemsRects[i] = new Rectangle(BeginMenuItemsX, BeginMenuItemsY + i * MenuItemsBoxOffsetY, MenuItemWidth, MenuItemHeight);
        }

        public static Color MenuItemColor = Color.WHITE;
        public static Color MenuItemHoverColor = Color.GOLD;
        public static void DrawMenu(float Opacity = 1, bool DrawInputHints = true) {
            if (Opacity < 1) {
                //MenuItemColor.a = MenuItemHoverColor.a = (byte)Opacity;
                MenuItemColor = ColorAlpha(MenuItemColor, Opacity);
                MenuItemHoverColor = ColorAlpha(MenuItemHoverColor, Opacity);
            }
            for (int i = 0; i < MenuItemsCount; i++) {
                if (RectHover(MenuItemsRects[i])) MenuItemLineThickness = 3; else MenuItemLineThickness = 1;
                DrawRectangleLinesEx(
                    MenuItemsRects[i], 
                    MenuItemLineThickness, 
                    DrawInputHints ? RectHover(MenuItemsRects[i]) ? MenuItemHoverColor : MenuItemColor : MenuItemColor);
                DrawText(
                    MenuItemsText[i], 
                    BeginMenuItemsX + MenuItemsBoxOffsetX, 
                    BeginMenuItemsY + (i * MenuItemsBoxOffsetY) + 10, 
                    25, 
                    ColorAlpha(Color.WHITE, Opacity));
            }
        }
    }
}