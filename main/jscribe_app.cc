#include "jscribe_app.h"
#include "imgui_box_shadow.h"
#include "modules\sample_module\sample_module.h"
#include <iostream>

namespace j {
namespace scribe {

JScribeApp::JScribeApp() {
  cout << "Starting " << applicationName_ << endl;
  cout << "================" << endl;
  InitializeOpenGL();
  InitializeImGUI();

  // Add a sample module for demonstration purposes
  SampleModule* sampleModule = new SampleModule{"MySampleModule"};
  modules_.push_back(sampleModule);
}

JScribeApp::~JScribeApp() {
  TerminateImGUI();
  TerminateOpenGL();
}

bool JScribeApp::InitializeOpenGL() {
  cout << "Initializing GLFW... ";
  if (glfwInit()) { cout << "SUCCESS" << endl; }
  else {
    cout << "ERROR" << endl;
    cout << ">> Could not initialize GLFW" << endl;
    return false;
  }

  cout << "Creating OpenGL context and window for rendering output... ";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  window_ = glfwCreateWindow(applicationWidth_, applicationHeight_, applicationName_.c_str(), NULL, NULL);
  if (window_) { cout << "SUCCESS" << endl; }
  else {
    cout << "ERROR" << endl;
    cout << ">> Could not create an OpenGL context and window for rendering" << endl;
    return false;
  }

  glfwMakeContextCurrent(window_);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  glfwSetKeyCallback(window_, GLFWKeyCallback);
  glfwSetErrorCallback(GLFWErrorCallback);
  int width, height;
  glfwGetFramebufferSize(window_, &width, &height);
  glViewport(0, 0, width, height);
  cout << "================" << endl;
  return true;
}

bool JScribeApp::TerminateOpenGL() {
  glfwDestroyWindow(window_);
  glfwTerminate();
  return true;
}

bool JScribeApp::InitializeImGUI() {
  ImGui_ImplGlfwGL3_Init(window_, true);
  ImGuiIO& io = ImGui::GetIO();
  io.Fonts->AddFontFromFileTTF("../../../resources/fonts/Roboto-Medium.ttf", 14.0f);

  // Set the ImGUI style
  ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.05f, 0.05f, 0.05f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_TextDisabled, ImVec4(0.5f, 0.5f, 0.5f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(1.f, 1.f, 1.f, 0.95f));
  ImGui::PushStyleColor(ImGuiCol_PopupBg, ImVec4(0.95f, 0.95f, 0.95f, 0.95f));
  ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.85f, 0.85f, 0.85f, 0.85f));
  ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.f, 0.66f, 1.f, 0.5f));
  ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.f, 0.66f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(0.f, 0.33f, 1.f, 1.0f));
  ImGui::PushStyleColor(ImGuiCol_TitleBgCollapsed, ImVec4(0.f, 0.33f, 1.f, 0.5f));
  ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.f, 0.33f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_MenuBarBg, ImVec4(0.f, 0.66f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_ScrollbarBg, ImVec4(1.f, 1.f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_ScrollbarGrab, ImVec4(0.85f, 0.85f, 0.85f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabHovered, ImVec4(0.f, 0.66f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabActive, ImVec4(0.f, 0.33f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_ComboBg, ImVec4(.95f, .95f, .95f, .95f));
  ImGui::PushStyleColor(ImGuiCol_CheckMark, ImVec4(0.f, 0.66f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(1.f, 1.f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(0.f, 0.33f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(.85f, .85f, .85f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.f, 0.66f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.f, 0.33f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.f, 0.66f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.f, 0.66f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.f, 0.33f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(.85f, .85f, .85f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_SeparatorHovered, ImVec4(0.f, 0.66f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_SeparatorActive, ImVec4(0.f, 0.33f, 1.f, 1.f));

  ImGui::PushStyleColor(ImGuiCol_ResizeGrip, ImVec4(0.85f, 0.85f, 0.85f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_ResizeGripHovered, ImVec4(0.f, 0.66f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_ResizeGripActive, ImVec4(0.f, 0.33f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_CloseButton, ImVec4(1.f, 1.f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_CloseButtonHovered, ImVec4(1.f, 1.f, 1.f, 1.f));
  ImGui::PushStyleColor(ImGuiCol_CloseButtonActive, ImVec4(0.f, 0.33f, 1.f, 1.f));

  ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, ImVec4(0.f, 0.66f, 1.f, 1.f));
  return true;
}

bool JScribeApp::TerminateImGUI() {
  ImGui_ImplGlfwGL3_Shutdown();
  return true;
}

void JScribeApp::Start() {
  running_ = true;
  while(running_) {
    Update();
    Draw();
  }
}

void JScribeApp::Stop() { running_ = false; }

void JScribeApp::Update() {
  for (auto m : modules_) {
    m->Update();
  }
}

void JScribeApp::Draw() {
  // Close the application if the window is closed
  if (glfwWindowShouldClose(window_)) { running_ = false; }

  // Process all window events
  glfwPollEvents();

  // Draw all modules
  ImGui_ImplGlfwGL3_NewFrame();
  for (auto m : modules_) {
    m->Draw();
  }

  // Render ImGUI to the framebuffer
  int display_w, display_h;
  glfwGetFramebufferSize(window_, &display_w, &display_h);
  glViewport(0, 0, display_w, display_h);
  ImVec4 clear_color = ImVec4(0.95f, 0.95f, 0.95f, 1.f);
  glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui::Render();

  // Swap the buffers and sync to the window refresh rate
  glfwSwapBuffers(window_);
  glfwSwapInterval(1);
}

void JScribeApp::GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  std::cout << "Key callback called" << std::endl;
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) { glfwSetWindowShouldClose(window, GLFW_TRUE); }
}

void JScribeApp::GLFWErrorCallback(int error, const char* description)
{
  std::cout << "ERROR (GLFW" << error << "): " << description << std::endl;
}

void JScribeApp::DrawImGUISampleWindows() {
  bool show_test_window = true;
  bool show_another_window = false;
  ImVec4 clear_color = ImVec4(0.95f, 0.95f, 0.95f, 1.f);

  // 1. Show a simple window
  // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets appears in a window automatically called "Debug"
  {
    static float f = 0.0f;
    ImGui::Text("Hello, world!");
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    ImGui::ColorEdit3("clear color", (float*)&clear_color);
    if (ImGui::Button("Test Window")) show_test_window ^= 1;
    if (ImGui::Button("Another Window")) show_another_window ^= 1;
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
  }

  // 2. Show another simple window, this time using an explicit Begin/End pair
  if (show_another_window)
  {
    ImGui::Begin("Another Window", &show_another_window);
    ImGui::Text("Hello from another window!");
    ImGui::End();
  }

  // 3. Show the ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
  if (show_test_window)
  {
    ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
    ImGui::ShowTestWindow(&show_test_window);
  }

  ImGui::drawShadowTestExampleWindow();
}

} // namespace
} // namespace