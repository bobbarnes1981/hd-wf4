#include <Adafruit_Protomatter.h>

// Matrix dimensions for a single panel connected to Port 1 (X1)
#define BIT_DEPTH       4    // Color depth (1 to 6)
#define PANEL_WIDTH     64   // Individual module width in pixels
#define PANEL_HEIGHT    32   // Individual module height in pixels

// Hardware pin mapping specific to Huidu HD-WF4 (ESP32-S3)
#define WF4_CLK_PIN     34
#define WF4_LAT_PIN     33
#define WF4_OE_PIN      35

#define WF4_A_PIN       39
#define WF4_B_PIN       38
#define WF4_C_PIN       37
#define WF4_D_PIN       36
#define WF4_E_PIN       21   // Set to -1 if using 1/16 scan panels (A,B,C,D only)

// Port 1 (X1) Data Pins
#define WF4_X1_R1_PIN   2
#define WF4_X1_G1_PIN   6
#define WF4_X1_B1_PIN   10
#define WF4_X1_R2_PIN   3
#define WF4_X1_G2_PIN   7
#define WF4_X1_B2_PIN   11

// Port Selection Enable Pins (HD-WF4 uses these pins to switch between physical ports)
#define WF4_PORT_X3_X4_EN  14
#define WF4_PORT_X1_X2_EN  45

// Setup pin arrays for Protomatter constructor
uint8_t rgbPins[] = {
  WF4_X1_R1_PIN, WF4_X1_G1_PIN, WF4_X1_B1_PIN,
  WF4_X1_R2_PIN, WF4_X1_G2_PIN, WF4_X1_B2_PIN
};

uint8_t addrPins[] = {
  WF4_A_PIN, WF4_B_PIN, WF4_C_PIN, WF4_D_PIN // Include WF4_E_PIN here if utilizing 1/32 scan panels
};

// Initialize the Protomatter Matrix
Adafruit_Protomatter matrix(
  PANEL_WIDTH,          // Width of matrix grid
  BIT_DEPTH,            // Color bit depth
  1, rgbPins,           // Number of parallel matrices (usually 1), RGB pins array
  sizeof(addrPins),     // Number of address lines
  addrPins,             // Address pins array
  WF4_CLK_PIN,          // Clock pin
  WF4_LAT_PIN,          // Latch pin
  WF4_OE_PIN,           // Output Enable pin
  true                  // Enable double-buffering for smooth animation
);

void setup() {
  Serial.begin(115200);

  // CRITICAL STEP FOR HD-WF4: Set the hardware port output enable line high
  pinMode(WF4_PORT_X1_X2_EN, OUTPUT);
  digitalWrite(WF4_PORT_X1_X2_EN, HIGH);

  // Initialize the matrix
  ProtomatterStatus status = matrix.begin();
  
  if (status != PROTOMATTER_OK) {
    Serial.println("Protomatter initialization failed!");
    while(1); 
  }
  
  Serial.println("Matrix initialized successfully!");
}

void loop() {
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
  
  delay(100);
}
