#include "Data_Module.h"

void initDataModule() {
  Serial.println("[DATA] Data module initialized");
}

String createJSON(const KisanSetuData& data) {

  String json = "{";

  json += "\"messageID\":";
  json += String(data.messageID);
  json += ",";

  json += "\"deviceID\":\"";
  json += data.deviceID;
  json += "\",";

  json += "\"latitude\":";
  json += String(data.latitude, 6);
  json += ",";

  json += "\"longitude\":";
  json += String(data.longitude, 6);
  json += ",";

  json += "\"altitude\":";
  json += String(data.altitude, 2);
  json += ",";

  json += "\"satellites\":";
  json += String(data.satellites);
  json += ",";

  json += "\"gpsFix\":";
  json += data.gpsFix ? "true" : "false";
  json += ",";

  json += "\"weight\":";
  json += String(data.weight, 2);
  json += ",";

  json += "\"timestamp\":";
  json += String(data.timestamp);

  json += "}";

  return json;
}