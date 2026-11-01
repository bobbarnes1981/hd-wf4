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
  
  delay(100);
}
