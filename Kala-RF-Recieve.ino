
#include <VirtualWire.h>
#include <Keyboard.h>

const int receivePin = 8;       // Pin connected to the data pin of the RF receiver module

void setup() {
  vw_set_rx_pin(receivePin);       // Set the receive pin
  vw_setup(2000);                  // Initialize the VirtualWire library with a data rate of 2000 bps
  vw_rx_start();                   // Start the receiver
  Keyboard.begin();                // Initialize the Keyboard library
vw_set_ptt_inverted(true);

}


void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN]; // Buffer to store the received message
  uint8_t buflen = VW_MAX_MESSAGE_LEN; // Length of the received message

  if (vw_get_message(buf, &buflen)) { // If a message is received
    char data = *(char*)buf;        // Extract the received data
  
    Keyboard.write(data);           // Emulate the key press on the computer
  }
}