#include <Arduino.h>
#include <F1sh.h>

/*
  This is a quickstart example for F1sh, this is a good way to explore F1sh and its capabilities.
  This example assumes that you are using F1sh's motor driver board which containes 4 motors and 6 servos powered by an Adafruit's PCA9685 controller.
  Released GNU GPLv3 license.
  For more infomation on F1sh, please visit: https://github.com/F1sh-org/F1sh.git
*/



// F1sh expects a certificate and a key file to be present in the root of the LittleFS filesystem.
// Create a cert by yourself by running the following command:
// openssl req -x509 -newkey rsa:4096 -nodes -keyout server.key -out server.crt -sha256 -days 36500 -subj "/C=VN/ST=HN/O=F1sh-org/OU=F1sh/CN=F1sh.local" -addext "subjectAltName = DNS:F1sh.local,IP:192.168.4.1"
// After that put both server.crt and server.key in the root of the LittleFS filesystem by putting them under /data folder from this project
// Then under PlatformIO, go to the Platform and select Upload Filesystem Image to upload the files to the ESP32.


const char *ssid = "F1sh";
const char *password = "stemistclub";

const char *hostname = "f1sh.local";

const int channel = 0; // 1-13 - You should change this if there are multiple APs in the area.
// ESP32 does not have ability to change channel dynamically based on the environment, so if channel is set to 0 or out of range, F1sh will automatically set to a random channel between 1 and 13

F1sh f1sh;

void handleGamepad() {
  // This function is called when the gamepad is connected
}

void setup() {
  Serial.begin(115200);
  f1sh.F1shInitAP(ssid, password, hostname, channel);
  #ifdef CORE_DEBUG_LEVEL
    Serial.setDebugOutput(true);
  #endif
  // Register callbacks
  f1sh.setGamepadCallback(handleGamepad);
}

void loop() {

}
