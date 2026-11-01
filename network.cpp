#include <network.h>

#include <WiFi.h>
#include <WiFiManager.h>

WiFiManager wifiManager;

void network_setup() {
  WiFi.setAutoReconnect(true);
  wifiManager.autoConnect(AP_NAME);
}
