#include <Wire.h>
#include <Adafruit_MCP23017.h>

Adafruit_MCP23017 mcp;

int ledPin=2; // WEMOS port for LED default is on
int intPin=0; // WEMOS port for Interrupt detect
int keyA=0;   // MCP port Number 0-15 for A0-B7
int keyB=1;   // MCP
int keyC=2;   // MCP
int pulseCount = 0; // WEMOS Interrupt Counter 
uint8_t pin;  //  handing
uint8_t val;  //  handing

void setup() {
  Serial.begin(115200);
  Serial.print("\n \n \n");
  Serial.print("MCP23007 Interrupt Test");
  Serial.println();
  Serial.println();
  
  pinMode(intPin,INPUT);
  pinMode(ledPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(intPin), pulsecounter, FALLING); // start wemos interrupt

  mcp.begin(0); //0 or empty is default Adress 

  mcp.setupInterrupts(true,true,LOW);
  mcp.pinMode(keyA, INPUT);
  mcp.pinMode(keyB, INPUT);
  mcp.pinMode(keyC, INPUT);
  mcp.pullUp(keyA, HIGH);
  mcp.pullUp(keyB, HIGH);
  mcp.pullUp(keyC, HIGH);
  mcp.setupInterruptPin(keyA,FALLING);
  mcp.setupInterruptPin(keyB,FALLING);
  mcp.setupInterruptPin(keyC,FALLING);
}
  
void loop() {
  Serial.println("++Hauptschleife++");
  activekey();
  delay(1000);
}

void pulsecounter() {
  pulseCount++;
}

void activekey() {
  if (pulseCount >= 1) {
    Serial.print("detect, key pressed. Pulse is : ");
    Serial.println(pulseCount);
    detachInterrupt(digitalPinToInterrupt(intPin)); //stop wemos interrupt
    pulseCount = 0;
    pin=mcp.getLastInterruptPin(); // i2c 
    val=mcp.getLastInterruptPinValue(); // and is reset interrupt on mcp
    while( ! (mcp.digitalRead(keyA) && mcp.digitalRead(keyB) && mcp.digitalRead(keyC) ) ) {
      Serial.println("wait, to unlook key");
      delay(500);
    };
    Serial.print("Port : ");
    Serial.print(pin); // print Portnumber 0-15 for A0-B7
    Serial.print(" Value is : ");
    Serial.print(val); // print 0 or 1 for low or high on port, 255 = register empty
    Serial.println(" .");
    pin = 222; // error
    val = 222;
    attachInterrupt(digitalPinToInterrupt(intPin), pulsecounter, FALLING); // start wemos interrupt
  }
}

