#pragma once
#ifndef J_SCRIBE_MODULES_PLCLOGGER_PLCLOGGER_H_
#define J_SCRIBE_MODULES_PLCLOGGER_PLCLOGGER_H_

#include <string>
#include "snap7.h"

using namespace std;

namespace j {
namespace scribe {

// Window used for rendering. Has an OpenGL context associated with it.
class PLCLogger {
public:
  PLCLogger(string ip, unsigned short int rack, unsigned short int slot) : ip_(ip), rack_(rack), slot_(slot) { }
  ~PLCLogger();

  void Update();
  void Draw();

private:
  bool Connect();
  bool Disconnect();

  string ip_;
  unsigned short int rack_, slot_;
  TS7Client client_;
};

} // namespace
} // namespace

#endif // J_SCRIBE_MODULES_PLCLOGGER_PLCLOGGER_H_