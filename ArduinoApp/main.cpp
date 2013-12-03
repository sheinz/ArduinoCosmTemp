#include <SPI.h>
#include <Ethernet.h>
#include <HttpClient.h>
#include <Xively.h>

#include "DS18B20.h"

#include <DHT.h>
#include <Adafruit_BMP085.h>

#include "xively.key"

// Workaround for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=34734
#ifdef PROGMEM
#undef PROGMEM
#define PROGMEM __attribute__((section(".progmem.data")))
#endif

// MAC address for your Ethernet shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Your Xively key to let you upload data
const char* cosmKey = PRIVATE_XIVELY_KEY;  // defined in cosm.key


// Define the strings for our datastream IDs
char indoorSensorId[] = "indoor";
char outdoorSensorId[] = "outdoor";
char humidityId[] = "humidity";
char pressureId[] = "pressure";

XivelyDatastream datastreams[] = {
   XivelyDatastream(indoorSensorId, strlen(indoorSensorId), DATASTREAM_FLOAT),
   XivelyDatastream(outdoorSensorId, strlen(outdoorSensorId), DATASTREAM_FLOAT),
   XivelyDatastream(humidityId, strlen(humidityId), DATASTREAM_FLOAT),
   XivelyDatastream(pressureId, strlen(pressureId), DATASTREAM_FLOAT),
};
// Finally, wrap the datastreams into a feed
XivelyFeed feed(1226691453, datastreams, 4 /* number of datastreams */);

EthernetClient client;
XivelyClient xivelyclient(client);

// ----------------------------------------------------------------------------

DS18B20 ds(5);
byte numberOfSensors;

DHT dht(2, DHT22);
Adafruit_BMP085 bmp;

void setup()
{
   // put your setup code here, to run once:
   Serial.begin(9600);

   Serial.println(F("Starting multiple datastream upload to Xively..."));
   Serial.println();

   while (Ethernet.begin(mac) != 1)
   {
      Serial.println(F("Error getting IP address via DHCP, trying again..."));
      delay(15000);
   }

   numberOfSensors = ds.search();

   Serial.print(F("Found sensors: "));
   Serial.println(numberOfSensors);

   dht.begin();

   if (!bmp.begin())
   {
      Serial.println(F("Could not find a valid BMP085 sensor, check wiring!"));
      while (1) {}
   }
}

void loop()
{
   if (numberOfSensors < 2)
   {
      Serial.println(F("Not enough sensors. Need at least two sensors."));
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
      Serial.println(F("Invalid temperature"));
      delay(3000);
      return;
   }

   if (isnan(humidity))
   {
      Serial.println(F("Failed to read from DHT"));
      delay(3000);
      return;
   }

   datastreams[0].setFloat(indoorTemp);
   Serial.print(F("Read indoor sensor value "));
   Serial.println(datastreams[0].getFloat());

   datastreams[1].setFloat(outdoorTemp);
   Serial.print(F("Read outdoor sensor value "));
   Serial.println(datastreams[1].getFloat());

   datastreams[2].setFloat(humidity);
   Serial.print(F("Humidity: "));
   Serial.println(datastreams[2].getFloat());

   datastreams[3].setFloat(pressure);
   Serial.print(F("Pressure = "));
   Serial.print(datastreams[3].getFloat());
   Serial.println(" Pa");

   Serial.println(F("Uploading it to Xively"));
   int ret = xivelyclient.put(feed, cosmKey);
   Serial.print(F("xivelyclient.put returned "));
   Serial.println(ret);

   Serial.println();

   delay(5000);
}

