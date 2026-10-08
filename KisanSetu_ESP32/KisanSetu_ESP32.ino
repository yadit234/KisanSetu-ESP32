#include "Data_Module/Data_Module.h"
#include "Storage_Module/Storage_Module.h"
#include "GPS_Module/GPS_Module.h"
#include "Weighing_Module/Weighing_Module.h"
#include "LoRa_Module/LoRa_Module.h"

KisanSetuData sensorData;

const char* DEVICE_ID = "KS-FARM-001";

unsigned long cycleCount = 0;

// ================================
// SIMULATION VALUES
// ================================

float simulatedLatitude = 20.5937;
float simulatedLongitude = 78.9629;
float simulatedAltitude = 310.5;

float simulatedWeight = 125.50;

int simulatedSatellites = 8;

// ================================
// SETUP
// ================================

void setup() {

  Serial.begin(115200);

  delay(1000);

  Serial.println();
  Serial.println("========================================");
  Serial.println("       KISANSETU EDGE HUB");
  Serial.println("========================================");

  // Initialize device ID
  sensorData.deviceID = DEVICE_ID;

  // Initialize modules
  initDataModule();
  initStorageModule();
  initGPSModule();
  initWeighingModule();
  initLoRaModule();

  Serial.println("[SYSTEM] All modules initialized");
}

// ================================
// LOOP
// ================================

void loop() {

  cycleCount++;

  // ================================
  // MESSAGE ID
  // ================================

  sensorData.messageID = cycleCount;

  // ================================
  // DEVICE ID
  // ================================

  sensorData.deviceID = DEVICE_ID;

  // ================================
  // SIMULATED GPS
  // ================================

  sensorData.latitude = simulatedLatitude;
  sensorData.longitude = simulatedLongitude;
  sensorData.altitude = simulatedAltitude;

  // ================================
  // SIMULATED WEIGHT
  // ================================

  sensorData.weight = simulatedWeight;

  // ================================
  // SIMULATED GPS STATUS
  // ================================

  sensorData.satellites = simulatedSatellites;
  sensorData.gpsFix = true;

  // ================================
  // TIMESTAMP
  // ================================

  sensorData.timestamp = millis();

  // ================================
  // CREATE JSON
  // ================================

  String jsonData = createJSON(sensorData);

  // ================================
  // LORA TRANSMISSION
  // ================================

  bool loraResult = sendLoRaData(jsonData);

  // ================================
  // DISPLAY DATA
  // ================================

  Serial.println("----------------------------------------");

  Serial.print("Simulation Cycle: ");
  Serial.println(cycleCount);

  Serial.println();

  Serial.println("KISANSETU SENSOR DATA:");

  Serial.print("Device ID: ");
  Serial.println(sensorData.deviceID);

  Serial.print("Message ID: ");
  Serial.println(sensorData.messageID);

  Serial.print("Latitude: ");
  Serial.println(sensorData.latitude, 6);

  Serial.print("Longitude: ");
  Serial.println(sensorData.longitude, 6);

  Serial.print("Altitude: ");
  Serial.print(sensorData.altitude);
  Serial.println(" m");

  Serial.print("Weight: ");
  Serial.print(sensorData.weight);
  Serial.println(" kg");

  Serial.print("Satellites: ");
  Serial.println(sensorData.satellites);

  Serial.print("GPS Fix: ");
  Serial.println(sensorData.gpsFix ? "YES" : "NO");

  Serial.print("Timestamp: ");
  Serial.println(sensorData.timestamp);

  Serial.println();

  // ================================
  // JSON OUTPUT
  // ================================

  Serial.println("Generated JSON:");
  Serial.println(jsonData);

  Serial.println();

  // ================================
  // LORA STATUS
  // ================================

  if (loraResult) {

    Serial.println("LoRa Status: PACKET SENT");

  } else {

    Serial.println("LoRa Status: PACKET FAILED");
  }

  Serial.println();

  Serial.println("Simulation Cycle Complete");
  Serial.println("--------------------------------");

  delay(5000);
}