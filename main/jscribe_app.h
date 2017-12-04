#pragma once
#ifndef J_SCRIBE_JSCRIBEAPP_H_
#define J_SCRIBE_JSCRIBEAPP_H_

#include <list>
#include "modules\module.h"
#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"
#include "glad.h"
#include "GLFW\glfw3.h"

using namespace std;

namespace j {
namespace scribe {

// The j-scribe application.
class JScribeApp {
public:
  JScribeApp();
  ~JScribeApp();
  void Start();
  void Stop();
private:
  bool InitializeOpenGL();
  bool TerminateOpenGL();
  bool InitializeImGUI();
  bool TerminateImGUI();
  void Update();
  void Draw();

  static void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
  static void GLFWErrorCallback(int error, const char* description);

  bool running_{false};
  list<Module*> modules_;
  GLFWwindow* window_;
  const string applicationName_{ "J-Scribe v0.0.1" };
  const int applicationWidth_{ 1600 };
  const int applicationHeight_{ 900 };
};

} // namespace
} // namespace

#endif // J_SCRIBE_JSCRIBEAPP_H_