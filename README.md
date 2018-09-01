# wemos-d1-mini-mcp23017_interrupt
mcp   - wemos
scl   -> d1 | pullup 2k;
sda   -> d2 | pullup 2k;
intA  -> d3 | is it with intern pullup 10k 3,3V;
reset -> reset | 10k pullup 3,3V and C2;
+ | 3,3V and C1;
- | GND and C1, C2;
A1-A3 -> GND;
portA0-2 -> KeyA-C -> GND;
C1 C2 = keramic ~700pF ~x7r or x5r or ... 

