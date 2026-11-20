/*
  ESP32 BLE Gamepad v3
  Dual output modes (switchable via OLED menu):
    KEYBOARD : joystick = mouse, pushbuttons + IR remote = keyboard keys
    GAMEPAD  : joystick = left stick, pushbuttons + IR remote = gamepad buttons / D-pad
  Mapping is stored separately for each mode.

  Required files in the sketch folder:
    esp32_ble_gamepad.ino, hid_pad.h, hid_pad.cpp

  Libraries:
    - ESP32-BLE-Combo        (BLE keyboard + mouse)
    - ESP32-BLE-Gamepad      (by lemmingDev, needs NimBLE-Arduino)  <- only for GAMEPAD mode
    - Adafruit SSD1306 + Adafruit GFX
    - IRremote 4.4+          (Armin Joachimsmeyer)
  Tools > Partition Scheme: "Huge APP (3MB No OTA/1MB SPIFFS)"

  If you do not need gamepad mode: set ENABLE_GAMEPAD_MODE to 0 in hid_pad.h

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

  NOTE: This is a temporary header-only placeholder.
  The full English-message sketch (same code, translated strings) is prepared.
  See TRANSLATION.md and ask to "push full English ino" to complete the upload.
*/

#error "Full English-message sketch not yet pushed due to size limit. See TRANSLATION.md or request full push."
