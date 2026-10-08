import json
import time
import random

DEVICE_ID = "KS-FARM-001"

latitude = 20.5937
longitude = 78.9629
altitude = 310.5
satellites = 8

message_id = 0

print("========================================")
print("        KISANSETU PC SIMULATION")
print("========================================")
print("Hardware: NOT CONNECTED")
print("Mode: SOFTWARE SIMULATION")
print()

while True:

    message_id += 1

    # Simulate changing weight
    weight = round(random.uniform(100, 150), 2)

    # Create KisanSetu data packet
    data = {
        "device_id": DEVICE_ID,
        "message_id": message_id,
        "packet_type": "SENSOR_DATA",
        "latitude": latitude,
        "longitude": longitude,
        "altitude": altitude,
        "weight_kg": weight,
        "satellites": satellites,
        "gps_fix": True,
        "timestamp": int(time.time())
    }

    # Convert to JSON
    json_data = json.dumps(data)

    print("----------------------------------------")
    print(f"Message ID : {message_id}")
    print(f"Weight     : {weight} kg")
    print(f"GPS        : {latitude}, {longitude}")
    print(f"Satellites : {satellites}")
    print()
    print("JSON Packet:")
    print(json_data)
    print("----------------------------------------")

    time.sleep(5)