#include <Arduino.h>
#include "LoRa_Module/LoRa_Module.h"

void initLoRaModule() {
  Serial.println("[LORA] LoRa module initialized");
  Serial.println("[LORA] Hardware not connected - simulation mode");
}

bool sendLoRaData(const String& data) {

  Serial.println("[LORA] Sending packet...");
  Serial.println("[LORA] Packet data:");
  Serial.println(data);

  return true;
}