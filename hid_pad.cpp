#include "hid_pad.h"

#if ENABLE_GAMEPAD_MODE

#include <BleGamepad.h>

static BleGamepad bleGamepad("ESP32 Gamepad", "Panzz", 100);
static BleGamepadConfiguration padCfg;

static uint8_t dpadMask = 0;          // bit0=atas, bit1=bawah, bit2=kiri, bit3=kanan
static int16_t lastX = 0, lastY = 0;
static bool    dirty = false;

static signed char hatFromMask(uint8_t m) {
  bool u = m & 1, d = m & 2, l = m & 4, r = m & 8;
  if (u && d) { u = false; d = false; }
  if (l && r) { l = false; r = false; }
  if (u && r) return HAT_UP_RIGHT;
  if (d && r) return HAT_DOWN_RIGHT;
  if (d && l) return HAT_DOWN_LEFT;
  if (u && l) return HAT_UP_LEFT;
  if (u) return HAT_UP;
  if (r) return HAT_RIGHT;
  if (d) return HAT_DOWN;
  if (l) return HAT_LEFT;
  return HAT_CENTERED;
}

void padBegin() {
  padCfg.setAutoReport(false);            // report dikirim manual lewat padFlush()
  padCfg.setButtonCount(16);
  padCfg.setHatSwitchCount(1);
  padCfg.setAxesMin(-32767);
  padCfg.setAxesMax(32767);
  padCfg.setIncludeZAxis(false);          // hanya stick kiri (X, Y) yang dipakai
  padCfg.setIncludeRxAxis(false);
  padCfg.setIncludeRyAxis(false);
  padCfg.setIncludeRzAxis(false);
  padCfg.setIncludeSlider1(false);
  padCfg.setIncludeSlider2(false);
  bleGamepad.begin(&padCfg);
}

bool padConnected() { return bleGamepad.isConnected(); }

void padPress(uint8_t code) {
  if (code >= GP_UP && code <= GP_RIGHT) dpadMask |= (uint8_t)(1 << (code - GP_UP));
  else if (code >= 1 && code <= 16)      bleGamepad.press(code);
  else return;
  dirty = true;
}

void padRelease(uint8_t code) {
  if (code >= GP_UP && code <= GP_RIGHT) dpadMask &= (uint8_t)~(1 << (code - GP_UP));
  else if (code >= 1 && code <= 16)      bleGamepad.release(code);
  else return;
  dirty = true;
}

void padReleaseAll() {
  for (int b = 1; b <= 16; b++) bleGamepad.release(b);
  dpadMask = 0;
  lastX = 0; lastY = 0;
  bleGamepad.setLeftThumb(0, 0);
  dirty = true;
  padFlush();
}

void padSetStick(int16_t x, int16_t y) {
  if (x == lastX && y == lastY) return;
  lastX = x; lastY = y;
  bleGamepad.setLeftThumb(x, y);
  dirty = true;
}

void padFlush() {
  if (!dirty) return;
  bleGamepad.setHat1(hatFromMask(dpadMask));
  bleGamepad.sendReport();
  dirty = false;
}

#else   // ---- mode gamepad dimatikan: fungsi kosong ----

void padBegin() {}
bool padConnected() { return false; }
void padPress(uint8_t) {}
void padRelease(uint8_t) {}
void padReleaseAll() {}
void padSetStick(int16_t, int16_t) {}
void padFlush() {}

#endif
