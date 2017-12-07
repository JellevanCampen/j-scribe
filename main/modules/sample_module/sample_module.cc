#include "sample_module.h"
#include "imgui.h"
#include <sstream>

namespace j {
namespace scribe {

  void SampleModule::Initialize() {
    update_count_ = 0;
    draw_count_ = 0;
  }

  void SampleModule::Terminate() {

  }

  void SampleModule::Update() {
    DoSomething();
  }

  void SampleModule::Draw() {
    draw_count_++;
    ShowSomething();
  }

  void SampleModule::DoSomething() {
    update_count_++;
  }

  void SampleModule::ShowSomething() {

    // Generate a line of text to show in the window
    stringstream text;
    text << "I have been updated " << update_count_ << " times, and drawn " << draw_count_ << " times!";

    // Create a window and add some text to it
    ImGui::Begin(("Sample Module - " + GetName()).c_str());
    ImGui::Text("Hello, I am sample module.");
    ImGui::Text(text.str().c_str());
    ImGui::End();
  }

} // namespace
} // namespace