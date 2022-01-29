//#include <Arduino.h>
#include "MCP3002.h"

MCP3002::MCP3002(uint8_t ss) {
  _ss = ss;
}

MCP3002::~MCP3002() {
}

void MCP3002::begin(void) {
//  mcp3002_cs = cs;
  pinMode(_ss, OUTPUT);
  digitalWrite(_ss, HIGH);
  //SPI.begin();
  SPI.begin(23,33,19,-1);
  SPI.setBitOrder (MSBFIRST);
}

int MCP3002::readData(uint8_t ch) {
  byte cmd = (ch == 0) ? 0x60 : 0x70;
  digitalWrite(_ss, LOW);
  byte MSB = SPI.transfer(cmd); // read from ch
  byte LSB = SPI.transfer(0x00);
  digitalWrite(_ss, HIGH);

  return ((MSB << 8) + LSB) & 0x3ff;
}
