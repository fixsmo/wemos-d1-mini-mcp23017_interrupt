#include <Wire.h>
#include <Adafruit_MCP23017.h>

Adafruit_MCP23017 mcp;

int ledPin=2;
int intPin=0;
int keyA=0;
int keyB=1;
int keyC=2;
bool state = LOW;
int pulseCount = 0;
uint8_t pin;
uint8_t val;

void setup() {
  Serial.begin(115200);
  Serial.print("\n \n \n");
  Serial.print("MCP23007 Interrupt Test");
  Serial.println();
  Serial.println();
  
  pinMode(intPin,INPUT);
  pinMode(ledPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(intPin), pulsecounter, FALLING);

  mcp.begin(0);

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
    detachInterrupt(digitalPinToInterrupt(intPin));
    pulseCount = 0;
    pin=mcp.getLastInterruptPin();
    val=mcp.getLastInterruptPinValue();
    while( ! (mcp.digitalRead(keyA) && mcp.digitalRead(keyB) && mcp.digitalRead(keyC) ) ) {
      Serial.println("wait, to unlook key");
      delay(500);
    };
    Serial.print("Port : ");
    Serial.print(pin);
    Serial.print(" Value is : ");
    Serial.print(val);
    Serial.print(" .");
    pin = 222;
    val = 222;
    attachInterrupt(digitalPinToInterrupt(intPin), pulsecounter, FALLING);
  }
}

