#ifndef GPS_MODULE_H
#define GPS_MODULE_H

void initGPSModule();
void readGPSData();
void printGPSData();

float getLatitude();
float getLongitude();
float getAltitude();
int getSatellites();
bool hasGPSFix();

#endif