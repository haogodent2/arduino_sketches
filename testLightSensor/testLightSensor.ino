/*
log analog light sensor data
 */
#include <SPI.h>
#include <SD.h>

// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.
const int chipSelect = 4;
const int sensorPin_1 = A0;    // select the input pin for sensor
const int sensorPin_2 = A1;
const int delayTime = 5000; // milliseconds
int sensorValue_1 = 0;
int sensorValue_2 = 0;
int logOpened = 0;

unsigned long time;

void setup(){
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop(){
  // make a string for assembling the data to log:
	String dataString = "";

  // read sensor value and append to dataString
  sensorValue_1 = analogRead(sensorPin_1);
  sensorValue_2 = analogRead(sensorPin_2);
  time = millis();
  dataString += String(time);
  dataString += ",";
  dataString += String(sensorValue_1);
  dataString += ",";
  dataString += String(sensorValue_2);
  dataString += ",";

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
	File dataFile = SD.open("LOG.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
    if (logOpened){
    }
    else{
      logOpened = 1;
      Serial.println("log file opened successfully");
    }
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening log file");
  }
  delay(delayTime);
}








