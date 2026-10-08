#ifndef STORAGE_MODULE_H
#define STORAGE_MODULE_H

void initStorageModule();
void saveData(const char* data);
void readData();

int getStoredRecordCount();

#endif