# wemos-d1-mini-mcp23017_interrupt

# mcp   - wemos  
scl   -> d1 | pullup 2k  
sda   -> d2 | pullup 2k  
intA  -> d3 | is it with intern pullup 10k 3,3V  
reset -> reset is it with intern pullup or 10k pullup 3,3V and C2  
VDD | 3,3V and C1  
VSS | GND and C1, C2  
A1-A3 -> GND  
portA0-2 -> KeyA-C -> GND  
C1 C2 = keramic ~700pF ~x7r or x5r or ...   

Arduino 1.8.5  
esp8266 by ESP Community Version 2.4.2  
Bord: LOLIN(WEMOS)D1 R2 & mini  
80MHz,Flash 4M(1M SPIFFS),v2 Lower Memory, Disabled, None Only Sketch, 115200  
auf /dev/ttyUSB0  

