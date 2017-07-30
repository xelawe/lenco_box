/*
   Blink and OTA
   Turns on the onboard LED on for one second, then off for one second, repeatedly.
   This uses delay() to pause between LED toggles.
*/
#define serdebug
#ifdef serdebug
#define DebugPrint(...) {  Serial.print(__VA_ARGS__); }
#define DebugPrintln(...) {  Serial.println(__VA_ARGS__); }
#else
#define DebugPrint(...) { }
#define DebugPrintln(...) { }
#endif

#include "cy_wifi.h"
#include "ota_tool.h"
#include "audio_util.h"

void setup() {
#ifdef serdebug
  Serial.begin(115200);
#endif

  wifi_init("D1mini");
  delay(500);

  init_ota("D1mini");

  pinMode(BUILTIN_LED, OUTPUT);  // initialize onboard LED as output

  init_audio( );
  delay(1000);                      // wait one second
}

void loop() {

  check_ota();

  digitalWrite(BUILTIN_LED, HIGH);  // turn on LED with voltage HIGH
  delay(1000);                      // wait one second
  digitalWrite(BUILTIN_LED, LOW);   // turn off LED with voltage LOW
  delay(1000);                      // wait one second


}

