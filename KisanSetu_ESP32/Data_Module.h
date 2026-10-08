#ifndef DATA_MODULE_H
#define DATA_MODULE_H

#include <Arduino.h>

struct KisanSetuData {

  String deviceID;
  unsigned long messageID;

  float latitude;
  float longitude;
  float altitude;

  int satellites;
  bool gpsFix;

  float weight;

  unsigned long timestamp;
};

void initDataModule();

String createJSON(const KisanSetuData& data);

#endif