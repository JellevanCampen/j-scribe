#pragma once
#ifndef J_SCRIBE_MODULES_MODULE_H_
#define J_SCRIBE_MODULES_MODULE_H_

#include <string>

using namespace std;

namespace j {
namespace scribe {

// Interface for j-scribe modules
class Module {
 protected:
  Module(string name, const string moduletype) : name_{name}, moduletype_{ moduletype } { };
  virtual ~Module() { }
  const string& GetName() const { return name_; }
  void SetName(const string& name) { name_ = name; }
  const string& GetModuleType() const { return moduletype_; }
  virtual void Initialize() = 0;
  virtual void Terminate() = 0;
  virtual void Update() = 0;
  virtual void Draw() = 0;

  // Only the engine can manage initialization, updating, drawing, and
  // termination of the subsystem as it performs initialization and
  // termination, and it execution via the game loop.
  friend class JScribeApp;
private:
  string name_;
  const string moduletype_;
};

} // namespace
} // namespace

#endif // J_SCRIBE_MODULES_MODULE_H_