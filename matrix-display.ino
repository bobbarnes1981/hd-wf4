#include <config.h>
#include <debug.h>
#include <display.h>

void setup() {
  debug_setup();
  display_setup();
}

void loop() {
  debug_loop();
  display_loop();
  
  delay(100);
}
