#include "imgui.h"
#include <imgui_impl_glfw.h>
#include <imgui_impl_vulkan.h>
#include <stdio.h>         
#include <stdlib.h>
#include "logreg.h"       
#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#include <glfw/include/GLFW/glfw3.h>
#include <vulkan/vulkan.h>

int compiler()
{
    ImGui::Begin("Compiler");
    static char inputText[1024 * 16] = { 0 };
    ImGui::InputTextMultiline("##input", inputText, IM_ARRAYSIZE(inputText), ImVec2(-1.0f, ImGui::GetTextLineHeight() * 10));
    ImVec2 pos = ImVec2(ImGui::GetWindowWidth() - 210.0f, ImGui::GetWindowHeight() - 30.0f);
    ImGui::SetCursorPos(pos);
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.4f, 0.4f, 0.4f, 1.0f));
    ImGui::Button("Submit", ImVec2(200, 20));
    ImGui::PopStyleColor();
    ImGui::End();
    return 1;
}
