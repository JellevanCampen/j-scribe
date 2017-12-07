#pragma once
#ifndef J_SCRIBE_MODULES_SAMPLEMODULE_SAMPLEMODULE_H_
#define J_SCRIBE_MODULES_SAMPLEMODULE_SAMPLEMODULE_H_

#include "..\module.h"

using namespace std;

namespace j {
namespace scribe {

// This is a sample module that illustrates how new modules can be build.
//
// Modules must inherit the Module interface. Doing so guarantees the class implements
// all methods required for a module to function.
//
class SampleModule : public Module {
public:
  // The constructor of a module must call the super-constructor of the Module interface.
  // In it, the module passes its unique name and its module name. The latter is a unique
  // identifier string shared by all instances of this module.
  SampleModule(string name) : Module{name, "SMPL"} { }
  ~SampleModule() = default;

  // The functions below are required by the Module interface. They are called by the
  // framework throughout the lifespan of the module.
  void Initialize() override;
  void Terminate() override;
  void Update() override;
  void Draw() override;

private:
  // The member functions and variables below are just samples of update and draw
  // functionality. As long as a module implements the interface functions from the
  // Module interface, it can function as a module. It can have as many public or
  // private functions and variables as it needs.
  void DoSomething();
  void ShowSomething();
  unsigned int update_count_{0};
  unsigned int draw_count_{0};
};

} // namespace
} // namespace

#endif // J_SCRIBE_MODULES_SAMPLEMODULE_SAMPLEMODULE_H_