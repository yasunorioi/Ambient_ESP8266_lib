#ifndef MCP3002_H
#define MCP3002_H

#include <M5Atom.h>
#include <SPI.h>

class MCP3002
{
public:
  MCP3002(uint8_t);
  virtual ~MCP3002();

  void begin(void);
  int readData(uint8_t ch);
private:
  uint8_t _ss;
};

#endif // MCP3002_H
