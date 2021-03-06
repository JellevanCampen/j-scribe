//The MIT License (MIT)
//
//Copyright (c) 2017 Stefano Cristiano
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

// ---------------------------------------------------------------------------
// Box Shadow for imgui using vertex colors
// Current Limitations:
// - Only works for axis aligned non rounded rectangle
// - Not optimized at all
// - User needs to figure out how many slices / rings are needed and what
//   spacing would look good for a box of given size and shadow sigma.
//	 Ideally the parameters should be automatically calculated based on some
//   high, medium, low quality settings
// ---------------------------------------------------------------------------

#pragma once
#ifndef IMGUI_BOXSHADOW_H_
#define IMGUI_BOXSHADOW_H_

#include "imgui.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_DEFINE_PLACEMENT_NEW
#include "imgui_internal.h"

/*ImVec2 operator+(ImVec2 p1, ImVec2 p2);
ImVec2 operator-(ImVec2 p1, ImVec2 p2);
ImVec2 operator/(ImVec2 p1, ImVec2 p2);
ImVec2 operator*(ImVec2 p1, int value);
ImVec2 operator*(ImVec2 p1, float value);
ImVec4 operator+(float val, ImVec4 p2);
ImVec4 operator*(float val, ImVec4 p2);
ImVec4 operator*(ImVec4 p2, float val);
ImVec4 operator-(ImVec4 p1, ImVec4 p2);
ImVec4 operator*(ImVec4 p1, ImVec4 p2);
ImVec4 operator/(ImVec4 p1, ImVec4 p2);*/

ImVec4 operator+(float val, ImVec4 p2);
ImVec4 operator*(float val, ImVec4 p2);
ImVec4 operator*(ImVec4 p2, float val);
ImVec4 operator/(ImVec4 p1, ImVec4 p2);

namespace ImGui
{
struct RectangleShadowSettings {
  // Inputs
  bool    linear = false;
  float   sigma = 3;
  ImVec2  padding = ImVec2(50, 50);
  ImVec2  rectPos = ImVec2(50, 50);
  ImVec2  rectSize = ImVec2(120, 120);
  ImVec2  shadowOffset = ImVec2(0, 0);
  ImVec2  shadowSize = ImVec2(120, 50);
  ImColor shadowColor = ImColor(0.6f, 0.6f, 0.6f, 1.0f);

  int  rings = 3;
  int  spacingBetweenRings = 6;
  int  samplesPerCornerSide = 1;
  int  spacingBetweenSamples = 15;

  // Outputs
  int totalVertices = 0;
  int totalIndices = 0;

  // Visualization
  bool enableDebugVisualization = false;
};

ImVec4 boxGaussianIntegral(ImVec4 x);
ImVec4 boxLinearInterpolation(ImVec4 x);
float boxShadow(ImVec2 lower, ImVec2 upper, ImVec2 point, float sigma, bool linearInterpolation);
void drawRectangleShadowVerticesAdaptive(RectangleShadowSettings& settings);
void drawShadowTestExampleWindow();
}
#endif // IMGUI_BOXSHADOW_H_