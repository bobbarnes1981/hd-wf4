#include <display.h>

#include <Adafruit_Protomatter.h>
#include <WiFi.h>

void display_setup() {
  controller_setup();
}

void display_loop() {
  if (WiFi.status() != WL_CONNECTED) {
    matrix.setCursor(5, 12);
    matrix.setTextColor(matrix.color565(0, 255, 0)); // Green text
    matrix.print("WiFi");
    matrix.show();
  } else {
    // Clear the screen buffer
    matrix.fillScreen(matrix.color565(0, 0, 0));

    // Draw some basic geometry using Adafruit_GFX functions
    matrix.drawRect(0, 0, matrix.width(), matrix.height(), matrix.color565(255, 0, 0)); // Red border
    matrix.drawCircle(matrix.width() / 2, matrix.height() / 2, 10, matrix.color565(0, 0, 255)); // Blue center circle
    matrix.setCursor(5, 12);
    matrix.setTextColor(matrix.color565(0, 255, 0)); // Green text
    matrix.print("HD-WF4");

    // Push buffer to the physical panel
    matrix.show();
  }
}