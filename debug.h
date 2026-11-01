#ifndef H_DEBUG
#define H_DEBUG

#include <Arduino.h>

#define DEBUG_PORT Serial
#define DEBUG_BAUD 115200

extern void debug_setup();

extern void debug_loop();

#endif