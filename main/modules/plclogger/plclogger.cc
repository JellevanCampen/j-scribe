#include "plclogger.h"

namespace j {
namespace scribe {

bool PLCLogger::Connect() {
  client_.ConnectTo(ip_.c_str(), rack_, slot_);
  int status = client_.Connect();
  if (status == 0) { return true; }
  return false;
}

bool PLCLogger::Disconnect() {
  int status = client_.Disconnect();
  if (status == 0) { return true; }
  return false;
}

} // namespace
} // namespace


/*
// Display partner PLC settings
cout << "Partner PLC settings:" << endl;
cout << ">> IP: " << PLC.ip << endl;
cout << ">> Rack: " << PLC.rack << endl;
cout << ">> Slot: " << PLC.slot << endl;
cout << "================" << endl;

// Connect to the PLC
cout << "Attempting to connect to PLC at " << PLC.ip << "... ";
TS7Client client;
client.ConnectTo(PLC.ip, PLC.rack, PLC.slot);
status = client.Connect();
if (status == 0) {
  cout << "SUCCESS" << endl;
}
else {
  cout << "ERROR" << endl;
  cout << ">> " << CliErrorText(status) << endl;
  exit(errorConnection);
}

// Display partner PLC block info
PS7BlocksList blocks;
status = client.ListBlocks(blocks);
if (status == 0) {
  cout << "SUCCESS" << endl;
}
else {
  cout << "ERROR" << endl;
  cout << ">> " << CliErrorText(status) << endl;
  exit(errorListBlocks);
}
cout << ">> OB count: " << blocks->OBCount << endl;
cout << ">> FB count: " << blocks->FBCount << " + " << blocks->SFBCount << " (FailSafe)" << endl;
cout << ">> FC count: " << blocks->FCCount << " + " << blocks->SFCCount << " (FailSafe)" << endl;
cout << ">> DB count: " << blocks->OBCount << " + " << blocks->SDBCount << " (FailSafe)" << endl;

// Disconnect from the PLC
cout << "================" << endl;
cout << "Disconnecting from PLC at " << PLC.ip << "... ";
status = client.Disconnect();
if (status == 0) {
  cout << "SUCCESS" << endl;
}
else {
  cout << "ERROR" << endl;
  cout << ">> " << CliErrorText(status) << endl;
  exit(errorDisconnection);
}
*/