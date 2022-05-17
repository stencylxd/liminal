using Raylib_cs;
using static Raylib_cs.Raylib;
using static Raylib_cs.KeyboardKey;
using static Raylib_cs.GamepadButton;
namespace LiminalGame {
    public static class Keybinds {
        public const int
            // Universal Bindings
            CONTROL_PAUSE  = 1,
            CONTROL_JUMP   = 2,
            CONTROL_CROUCH = 3,
            CONTROL_LEFT   = 4,
            CONTROL_MOVE   = 5,
            CONTROL_RIGHT  = 6,
            // Keyboard Bindings
            KEYBIND_PAUSE  = (int)KEY_ESCAPE,
            KEYBIND_JUMP   = (int)KEY_SPACE,
            KEYBIND_CROUCH = (int)KEY_LEFT_SHIFT,
            KEYBIND_LEFT   = (int)KEY_A,
            KEYBIND_RIGHT  = (int)KEY_D,
            // Gamepad Bindings
            GAMEPAD_PAUSE  = (int)GAMEPAD_BUTTON_MIDDLE_RIGHT,
            GAMEPAD_JUMP   = (int)GAMEPAD_BUTTON_RIGHT_FACE_DOWN,
            GAMEPAD_CROUCH = (int)GAMEPAD_BUTTON_LEFT_TRIGGER_1,
            // strafing is determied by joystick, but for dpad gamers....
            GAMEPAD_LEFT   = (int)GAMEPAD_BUTTON_LEFT_FACE_LEFT,
            GAMEPAD_RIGHT  = (int)GAMEPAD_BUTTON_LEFT_FACE_RIGHT;

        public static bool InputDown(int control) {
            switch (control) {
                case CONTROL_MOVE:   return (InputDown(CONTROL_LEFT)                || InputDown(CONTROL_RIGHT));
                case CONTROL_LEFT:   return (IsKeyDown((KeyboardKey)KEYBIND_LEFT)   || IsGamepadButtonDown(0, (GamepadButton)GAMEPAD_LEFT));
                case CONTROL_RIGHT:  return (IsKeyDown((KeyboardKey)KEYBIND_RIGHT)  || IsGamepadButtonDown(0, (GamepadButton)GAMEPAD_RIGHT));
                case CONTROL_JUMP:   return (IsKeyDown((KeyboardKey)KEYBIND_JUMP)   || IsGamepadButtonDown(0, (GamepadButton)GAMEPAD_JUMP));
                case CONTROL_CROUCH: return (IsKeyDown((KeyboardKey)KEYBIND_CROUCH) || IsGamepadButtonDown(0, (GamepadButton)GAMEPAD_CROUCH));
                case CONTROL_PAUSE:  return (IsKeyDown((KeyboardKey)KEYBIND_PAUSE)  || IsGamepadButtonDown(0, (GamepadButton)GAMEPAD_PAUSE));
                default: return false;
            }
        }

        public static int GetInput() {
            if (InputDown(CONTROL_LEFT))   return CONTROL_LEFT;
            if (InputDown(CONTROL_RIGHT))  return CONTROL_RIGHT;
            if (InputDown(CONTROL_CROUCH)) return CONTROL_CROUCH;
            if (InputDown(CONTROL_JUMP))   return CONTROL_JUMP;
            if (InputDown(CONTROL_PAUSE))  return CONTROL_PAUSE;
            return 0;
        }
    }
}