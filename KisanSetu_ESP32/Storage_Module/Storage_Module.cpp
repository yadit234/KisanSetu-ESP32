#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include "Storage_Module.h"

// SD card SPI pins
#define SD_SCK   14
#define SD_MISO  12
#define SD_MOSI  13
#define SD_CS    5

const char* DATA_FILE = "/kisansetu_data.jsonl";

void initStorageModule() {

  Serial.println("Initializing Storage Module...");

  SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

  if (!SD.begin(SD_CS)) {
    Serial.println("SD Card: Not Connected");
    return;
  }

  Serial.println("SD Card: Initialized");

  if (!SD.exists(DATA_FILE)) {

    File file = SD.open(DATA_FILE, FILE_WRITE);

    if (file) {
      file.close();
      Serial.println("Created KisanSetu data file.");
    } else {
      Serial.println("Failed to create data file.");
    }
  }
}

void saveData(const char* data) {

  File file = SD.open(DATA_FILE, FILE_APPEND);

  if (file) {

    file.println(data);
    file.close();

    Serial.println("Data saved to SD card.");

  } else {

    Serial.println("Failed to open data file.");
  }
}

void readData() {

  File file = SD.open(DATA_FILE);

  if (!file) {
    Serial.println("No stored data found.");
    return;
  }

  Serial.println();
  Serial.println("========== STORED KISANSETU DATA ==========");

  while (file.available()) {
    Serial.write(file.read());
  }

  file.close();

  Serial.println();
  Serial.println("===========================================");
}


// Count stored sensor records
int getStoredRecordCount() {

  File file = SD.open(DATA_FILE);

  if (!file) {
    return 0;
  }

  int count = 0;

  while (file.available()) {

    String line = file.readStringUntil('\n');

    if (line.length() > 2) {
      count++;
    }
  }

  file.close();

  return count;
}