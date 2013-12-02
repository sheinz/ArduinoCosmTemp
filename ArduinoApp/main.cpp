#include <SPI.h>
#include <Ethernet.h>
#include <HttpClient.h>
#include <Cosm.h>

#include "DS18B20.h"

#include <DHT.h>
#include <Adafruit_BMP085.h>

#include "cosm.key"

// MAC address for your Ethernet shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Your Cosm key to let you upload data
char cosmKey[] = PRIVATE_COSM_KEY;  // defined in cosm.key


// Define the strings for our datastream IDs
char indoorSensorId[] = "indoor";
char outdoorSensorId[] = "outdoor";
char humidityId[] = "humidity";
char pressureId[] = "pressure";

CosmDatastream datastreams[] = {
   CosmDatastream(indoorSensorId, strlen(indoorSensorId), DATASTREAM_FLOAT),
   CosmDatastream(outdoorSensorId, strlen(outdoorSensorId), DATASTREAM_FLOAT),
   CosmDatastream(humidityId, strlen(humidityId), DATASTREAM_FLOAT),
   CosmDatastream(pressureId, strlen(pressureId), DATASTREAM_FLOAT),
};
// Finally, wrap the datastreams into a feed
CosmFeed feed(102125, datastreams, 4 /* number of datastreams */);

EthernetClient client;
CosmClient cosmclient(client);

// ----------------------------------------------------------------------------

DS18B20 ds(5);
byte numberOfSensors;

DHT dht(2, DHT22);
Adafruit_BMP085 bmp;

void setup()
{
   // put your setup code here, to run once:
   Serial.begin(9600);

   Serial.println("Starting multiple datastream upload to Cosm...");
   Serial.println();

   while (Ethernet.begin(mac) != 1)
   {
      Serial.println("Error getting IP address via DHCP, trying again...");
      delay(15000);
   }

   numberOfSensors = ds.search();

   Serial.print("Found sensors: ");
   Serial.println(numberOfSensors);

   dht.begin();

   if (!bmp.begin())
   {
      Serial.println("Could not find a valid BMP085 sensor, check wiring!");
      while (1) {}
   }
}

void loop()
{
   if (numberOfSensors < 2)
   {
      Serial.println("Not enough sensors. Need at least two sensors.");
      numberOfSensors = ds.search();
      delay(3000);
      return;
   }

   float indoorTemp = ds.startAndWaitForTemperature(0);
   float outdoorTemp = ds.startAndWaitForTemperature(1);

   float humidity = dht.readHumidity();
   int32_t pressure = bmp.readPressure();


   if (indoorTemp < -100 || outdoorTemp < -100)
   {
      Serial.println("Invalid temperature");
      delay(3000);
      return;
   }

   if (isnan(humidity))
   {
      Serial.println("Failed to read from DHT");
      delay(3000);
      return;
   }

   datastreams[0].setFloat(indoorTemp);
   Serial.print("Read indoor sensor value ");
   Serial.println(datastreams[0].getFloat());

   datastreams[1].setFloat(outdoorTemp);
   Serial.print("Read outdoor sensor value ");
   Serial.println(datastreams[1].getFloat());

   datastreams[2].setFloat(humidity);
   Serial.print("Humidity: ");
   Serial.println(datastreams[2].getFloat());

   datastreams[3].setFloat(pressure);
   Serial.print("Pressure = ");
   Serial.print(datastreams[3].getFloat());
   Serial.println(" Pa");

   Serial.println("Uploading it to Cosm");
   int ret = cosmclient.put(feed, cosmKey);
   Serial.print("cosmclient.put returned ");
   Serial.println(ret);

   Serial.println();

   delay(5000);
}

