/*
  This repository provides TWO language variants of the sketch.

  Use one of these as your main sketch file:

    esp32_ble_gamepad_id.ino  → Bahasa Indonesia (OLED messages)
    esp32_ble_gamepad_en.ino  → English (OLED messages)

  Both share the same logic and the same companion files:
    hid_pad.h
    hid_pad.cpp

  Arduino IDE tip:
  1. Create a folder named e.g. esp32_ble_gamepad
  2. Copy the chosen .ino into it and rename it to esp32_ble_gamepad.ino
  3. Copy hid_pad.h and hid_pad.cpp into the same folder
  4. Open the folder as a sketch and upload (Huge APP partition)

  See README.md and LANGUAGE.md for details.
*/

#error "Choose esp32_ble_gamepad_id.ino or esp32_ble_gamepad_en.ino as the main sketch (see README)."
