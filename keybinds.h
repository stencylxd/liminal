// keybinds.h for controls
#include "libs/raylib.h"

const int
    CONTROL_PAUSE  = 1,
    CONTROL_JUMP   = 2,
    CONTROL_CROUCH = 3,
    CONTROL_LEFT   = 4,
    CONTROL_MOVE   = 5,
    CONTROL_RIGHT  = 6;
const int
    KEYBIND_PAUSE  = KEY_ESCAPE,
    KEYBIND_JUMP   = KEY_SPACE,
    KEYBIND_CROUCH = KEY_LEFT_SHIFT,
    KEYBIND_LEFT   = KEY_A,
    KEYBIND_RIGHT  = KEY_D;
const int
    GAMEPAD_PAUSE  = GAMEPAD_BUTTON_MIDDLE_RIGHT,
    GAMEPAD_JUMP   = GAMEPAD_BUTTON_RIGHT_FACE_DOWN,
    GAMEPAD_CROUCH = GAMEPAD_BUTTON_LEFT_TRIGGER_1,
    // strafing is determied by joystick, but for dpad gamers....
    GAMEPAD_LEFT   = GAMEPAD_BUTTON_LEFT_FACE_LEFT,
    GAMEPAD_RIGHT  = GAMEPAD_BUTTON_LEFT_FACE_RIGHT;

int InputDown(int control) {
    switch (control) {
        case CONTROL_MOVE:
            return (InputDown(CONTROL_LEFT)   || InputDown(CONTROL_RIGHT));
        case CONTROL_LEFT:
            return (IsKeyDown(KEYBIND_LEFT)   || IsGamepadButtonDown(0, GAMEPAD_LEFT));
        case CONTROL_RIGHT:
            return (IsKeyDown(KEYBIND_RIGHT)  || IsGamepadButtonDown(0, GAMEPAD_RIGHT));
        case CONTROL_JUMP:
            return (IsKeyDown(KEYBIND_JUMP)   || IsGamepadButtonDown(0, GAMEPAD_JUMP));
        case CONTROL_CROUCH:
            return (IsKeyDown(KEYBIND_CROUCH) || IsGamepadButtonDown(0, GAMEPAD_CROUCH));
        case CONTROL_PAUSE:
            return (IsKeyDown(KEYBIND_PAUSE)  || IsGamepadButtonDown(0, GAMEPAD_PAUSE));
        default: return 0;
    }
}

int GetInput() {
    if (InputDown(CONTROL_LEFT))   return CONTROL_LEFT;
    if (InputDown(CONTROL_RIGHT))  return CONTROL_RIGHT;
    if (InputDown(CONTROL_CROUCH)) return CONTROL_CROUCH;
    if (InputDown(CONTROL_JUMP))   return CONTROL_JUMP;
    if (InputDown(CONTROL_PAUSE))  return CONTROL_PAUSE;
    return 0;
}