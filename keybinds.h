// keybinds.h for controls
#include "libs/raylib.h"

const int
    CONTROL_PAUSE = 1,
    CONTROL_JUMP = 2,
    CONTROL_CROUCH = 3,
    CONTROL_LEFT = 4,
    CONTROL_RIGHT = 5;
const int
    KEYBIND_PAUSE = KEY_ESCAPE,
    KEYBIND_JUMP = KEY_SPACE,
    KEYBIND_CROUCH = KEY_LEFT_SHIFT,
    KEYBIND_LEFT = KEY_A,
    KEYBIND_RIGHT = KEY_D;

const int
    GAMEPAD_PAUSE = GAMEPAD_BUTTON_MIDDLE_RIGHT,
    GAMEPAD_JUMP = GAMEPAD_BUTTON_RIGHT_FACE_DOWN,
    GAMEPAD_CROUCH = GAMEPAD_BUTTON_LEFT_TRIGGER_1,
    // strafing is determied by joystick, but for dpad gamers....
    GAMEPAD_LEFT = GAMEPAD_BUTTON_LEFT_FACE_LEFT,
    GAMEPAD_RIGHT = GAMEPAD_BUTTON_LEFT_FACE_RIGHT;

int GetInputActive(int control) {
    if (control == CONTROL_PAUSE && 
        (IsKeyDown(KEYBIND_PAUSE) || 
        IsGamepadButtonDown(1, GAMEPAD_PAUSE)))
        return 1;
    if (control == CONTROL_JUMP && 
        (IsKeyDown(KEYBIND_JUMP) || 
        IsGamepadButtonDown(1, GAMEPAD_JUMP)))
        return 1;
    if (control == CONTROL_CROUCH && 
        (IsKeyDown(KEYBIND_CROUCH) || 
        IsGamepadButtonDown(1, GAMEPAD_CROUCH)))
        return 1;
    if (control == CONTROL_LEFT && 
        (IsKeyDown(KEYBIND_LEFT) || 
        IsGamepadButtonDown(1, GAMEPAD_LEFT)))
        return 1;
    if (control == CONTROL_RIGHT && 
        (IsKeyDown(KEYBIND_RIGHT) || 
        IsGamepadButtonDown(1, GAMEPAD_RIGHT)))
        return 1;
    return 0;
}