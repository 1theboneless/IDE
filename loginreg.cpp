#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"
#include <string.h>
#include <iostream>
#include <glfw/include/GLFW/glfw3.h>
#include <string>
#include <algorithm>
#include "Registration.h"

using namespace std;

string username;
string password;
string email;
string confirmpass;
char inputemail[CHAR_MAX];
char inputusername[CHAR_MAX];
char inputpassword[CHAR_MAX];
char inputconfpass[CHAR_MAX];

bool show_registration_form = false;
bool show_login_form = true;

int chartostr()
{
    string inpes = string(inputemail);
    string inpus = string(inputusername);
    string inpas = string(inputpassword);
    string inconpas = string(inputconfpass);
    return 0;
}

int strcmp()
{
    if (string(inputusername) == username && password == string(inputpassword))
    {
        std::cout << "Login Success" << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Login Failed" << std::endl;
        return 0;
    }
}

int loginReg()
{
    string text = "Hello World!";
    ImGui::SetNextWindowSize(ImVec2(ImGui::GetWindowWidth(), ImGui::GetWindowHeight()));
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus;
    float center_x = ImGui::GetWindowWidth()* 0.5;
    bool open = true;
    ImGui::Begin("Login", &open, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    ImGuiWindowFlags;
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.0f);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.5f, 0.5f, 0.5f, 0.5f));
    ImGui::BeginChild("Loginwindow");

    if (show_login_form)
    {
        // Set rounding for input fields and buttons
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.0f);
        ImGui::SetCursorPosX(center_x);
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Username", NULL, true).x * 0.5);
        ImGui::Text("Input Username");
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Username", NULL, true).x);
        ImGui::SetNextItemWidth(200);
        ImGui::InputText("##usernameinput", inputusername, CHAR_MAX);
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Email", NULL, true).x * 0.5);
        ImGui::Text("Input Email");
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Username", NULL, true).x);
        ImGui::SetNextItemWidth(200);
        ImGui::InputText("##email", inputemail, CHAR_MAX, ImGuiInputTextFlags_Password);
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x * 0.5);
        ImGui::Text("Input Password");
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x);
        ImGui::SetNextItemWidth(200);
        ImGui::InputText("##password", inputpassword, CHAR_MAX, ImGuiInputTextFlags_Password);
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Register", NULL, true).x * 0.55);
        bool showText = false;
        if (showText)
        {
            ImGui::Text("Registation Completed!");
        }
        if (ImGui::Button("Register"))
        {
            show_login_form = false;
            show_registration_form = true;
        }
        bool isPasswordCorrect = false;
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x);
        if (ImGui::Button("Log In", ImVec2(200, 50)))
        {
            if (strcmp() == 1)
            {
                ImGui::Text("%s", text.c_str());
                isPasswordCorrect = true;
            }
            if (strcmp() == 0)
            {
                ImGui::Text("%s", text.c_str());
                isPasswordCorrect = false;
            }
        }

        // Reset rounding for input fields and buttons
        ImGui::PopStyleVar(2);
    }
if (show_registration_form)
    {
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.0f);
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Username", NULL, true).x * 0.5);
        ImGui::Text("Input Username");
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Username", NULL, true).x);
        ImGui::SetNextItemWidth(200);
        ImGui::InputText("##regusernameinput", inputusername, CHAR_MAX);
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Email", NULL, true).x * 0.5);
        ImGui::Text("Input Email");
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Username", NULL, true).x);
        ImGui::SetNextItemWidth(200);
        ImGui::InputText("##regemail", inputemail, CHAR_MAX, ImGuiInputTextFlags_Password);
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x * 0.5);
        ImGui::Text("Input Password");
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x);
        ImGui::SetNextItemWidth(200);
        ImGui::InputText("##regpassword", inputpassword, CHAR_MAX, ImGuiInputTextFlags_Password);
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Confirm password", NULL, true).x * 0.5);
        ImGui::Text("Confirm password");
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x);
        ImGui::SetNextItemWidth(200);
        ImGui::InputText("##confirmpass", inputconfpass, CHAR_MAX, ImGuiInputTextFlags_Password);
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Cancel", NULL, true).x * 0.55);

        if (ImGui::Button("Cancel"))
        {
            show_registration_form = false;
            show_login_form = true;
        }
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x);
        if (ImGui::Button("Register", ImVec2(200, 50)))
        {
            if (string(inputpassword) == string(inputconfpass))
            {
                Registration(inputusername, inputemail, inputpassword);
                show_registration_form = false;
                show_login_form = true;
            }
            else
            {
                std::cout << "Registration Failed: Passwords do not match." << std::endl;
            }
        }
ImGui::PopStyleVar(2);
}

ImGui::PopStyleColor();
ImGui::PopStyleVar();
ImGui::EndChild();
ImGui::End();
return 1;
}
