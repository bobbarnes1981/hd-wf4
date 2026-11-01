#include <config.h>
#include <debug.h>
#include <display.h>
#include <network.h>

void setup() {
  debug_setup();
  display_setup();
  network_setup();
}

void loop() {
  debug_loop();
  display_loop();
  network_loop();

  // todo: when connected after wifi was disconnected, get ntp time using time.h
}
