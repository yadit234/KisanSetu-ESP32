#include "LoRa_Module.h"

void initLoRaModule() {
  Serial.println("[LORA] LoRa module initialized");
}

bool sendLoRaData(const String& data) {

  Serial.println("[LORA] Sending packet...");
  Serial.println(data);

  return true;
}