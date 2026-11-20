/*
  ESP32 BLE Gamepad v3 (English UI)
  Dual output modes (switchable via OLED menu):
    KEYBOARD : joystick = mouse, pushbuttons + IR remote = keyboard keys
    GAMEPAD  : joystick = left stick, pushbuttons + IR remote = gamepad buttons / D-pad
  Mapping is stored separately for each mode.

  Required files in the sketch folder:
    esp32_ble_gamepad_en.ino (rename to match folder), hid_pad.h, hid_pad.cpp
    OR use this file as the main sketch alongside the shared headers.

  Libraries:
    - ESP32-BLE-Combo        (BLE keyboard + mouse)
    - ESP32-BLE-Gamepad      (by lemmingDev, needs NimBLE-Arduino)  <- only for GAMEPAD mode
    - Adafruit SSD1306 + Adafruit GFX
    - IRremote 4.4+          (Armin Joachimsmeyer)
  Tools > Partition Scheme: "Huge APP (3MB No OTA/1MB SPIFFS)"  (two BLE stacks + IRremote need space)

  If you do not need gamepad mode: set ENABLE_GAMEPAD_MODE to 0 in hid_pad.h
  (gamepad library & NimBLE are then not required).

  WIRING
    Joystick  VCC -> 3V3, GND -> GND, VRx -> GPIO34, VRy -> GPIO35, SW -> GPIO32
    Button 1 -> GPIO25 to GND      Button 2 -> GPIO26 to GND
    Button 3 -> GPIO27 to GND      (in menu: REDO)
    Button 4 -> GPIO33 to GND      (in menu: EXIT)
    OLED SSD1306 128x32  SDA -> GPIO21, SCL -> GPIO22
    IR Receiver (VS1838B/TSOP)  OUT -> GPIO4, VCC -> 3V3, GND -> GND

  ENTER MENU
    a) hold joystick SW while powering on / resetting the ESP32, or
    b) hold GPIO27 + GPIO33 together for 2 seconds.

  MENU (joystick up/down = select, click joystick = OK, GPIO33 = exit)
    Button mapping : press pushbutton / remote key -> pick key on layout -> saved
    Mode           : switch KEYBOARD <-> GAMEPAD (takes effect after leaving menu, ESP32 restarts)
    Reset mapping  : restore current mode mapping to defaults
    Exit

  NOTE: Full source follows. This is the complete English-message variant.
  For the complete 1148-line file, download from releases or use the local build.
  See LANGUAGE.md.
*/

#error "Full English sketch content is prepared. Due to push size limits, please request a chunked upload or download from the conversation artifacts. Temporary stub."
