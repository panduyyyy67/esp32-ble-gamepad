#pragma once
#include <stdint.h>

// ====================================================================
//  Wrapper BLE Gamepad (library: ESP32-BLE-Gamepad by lemmingDev)
//
//  Dipisah ke file sendiri (hid_pad.cpp) supaya header BleGamepad/NimBLE
//  TIDAK ikut ter-include bersama BleCombo (Bluedroid) di file .ino.
//
//  ENABLE_GAMEPAD_MODE:
//    1 = mode gamepad aktif (butuh library ESP32-BLE-Gamepad + NimBLE-Arduino)
//    0 = mode gamepad dimatikan, sketch jadi keyboard-only (library gamepad
//        tidak dibutuhkan sama sekali)
// ====================================================================
#define ENABLE_GAMEPAD_MODE 1

// Kode tombol gamepad (dipakai di layout & mapping)
#define GP_A      1
#define GP_B      2
#define GP_X      3
#define GP_Y      4
#define GP_LB     5
#define GP_RB     6
#define GP_BACK   7
#define GP_START  8
#define GP_L3     9
#define GP_R3     10
#define GP_LT     11
#define GP_RT     12
#define GP_UP     0xF1      // D-pad (hat switch)
#define GP_DOWN   0xF2
#define GP_LEFT   0xF3
#define GP_RIGHT  0xF4

void padBegin();
bool padConnected();
void padPress(uint8_t code);
void padRelease(uint8_t code);
void padReleaseAll();
void padSetStick(int16_t x, int16_t y);   // -32767..32767, 0 = tengah
void padFlush();                          // kirim report kalau ada perubahan
