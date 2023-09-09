#include <SoftwareSerial.h>
#include <VirtualWire.h>

SoftwareSerial mySerial(9, 10);  // RX, TX pins connected to the USB TTL converter
const int transmitPin = 8;      // Pin connected to the data pin of the RF transmitter module

void setup() {
  Serial.begin(9600);             // Initialize the SoftwareSerial for communication with USB TTL converter
  vw_set_tx_pin(transmitPin);       // Set the transmit pin
  vw_setup(2000);                   // Initialize the VirtualWire library with a data rate of 2000 bps
  vw_set_ptt_inverted(true);
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();    // Read data from the USB TTL converter
    vw_send((uint8_t*)&data, sizeof(data)); // Send the data wirelessly
    vw_wait_tx();                   // Wait for the transmission to complete
  }
}