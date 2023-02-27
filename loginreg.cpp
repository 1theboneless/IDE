#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"
#include <string.h>
#include <iostream>
#include <glfw/include/GLFW/glfw3.h>
#include <string>
#include <algorithm>
#include "Registration.h"
#include "Login.h"
#include <thread>
#include <Windows.h>

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
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x / 2 - 316, ImGui::GetIO().DisplaySize.y / 2 - 180), ImGuiCond_Always);
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus;
    float center_x = ImGui::GetWindowWidth() * 0.5;
    bool open = true;
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.086f, 0.105f, 0.133f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.188f, 0.211f, 0.239f, 1.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.2f);
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.137f, 0.164f, 0.2f, 1.0f));
    ImGui::SetNextWindowSize(ImVec2(633.0f, 360.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 2.0f);
    ImGui::Begin("Login", &open, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);

    
    
    /*ImGui::BeginChild("Loginwindow");*/

    if (show_login_form)
    {
        float input_width = 420;
        float container_width = 440;
        float center_x = ImGui::GetWindowWidth() * 0.5f;
        float container_start_x = center_x - input_width * 0.5f;
        float input_start_x = center_x - input_width * 0.73f;
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 10));
        ImGui::SetCursorPosX(container_start_x);
        ImGui::Dummy(ImVec2(0, 120));
        {
            {
                ImGui::SetCursorPosX(container_start_x);
                ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
                ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.137f, 0.164f, 0.2f, 1.0f));
                ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.137f, 0.164f, 0.2f, 1.0f));
                //ImGui::PushFont(ImFont * custom_font);
                bool open = true;
                ImGui::BeginChild("Username", (ImVec2(container_width, 40)));
                {
                ImGui::Dummy(ImVec2(0, 1));
                ImGui::SetCursorPosX(input_start_x);
                ImGui::SetNextItemWidth(input_width);
                ImGui::InputTextWithHint("##usernameinput", "Username..", inputusername, 32, ImGuiInputTextFlags_EnterReturnsTrue);
            }
                ImGui::EndChild();
            }
            {
                ImGui::SetCursorPosX(container_start_x);
                ImGui::BeginChild("Email", (ImVec2(container_width, 40)));
                {
                ImGui::Dummy(ImVec2(0, 1));
                ImGui::SetCursorPosX(input_start_x);
                ImGui::SetNextItemWidth(input_width);
                ImGui::InputTextWithHint("##email", "Email..", inputemail, 32, ImGuiInputTextFlags_EnterReturnsTrue);
            }
                ImGui::EndChild();
            }
            {
                ImGui::SetCursorPosX(container_start_x);
                ImGui::BeginChild("Password", (ImVec2(container_width, 40)));
                {
                ImGui::Dummy(ImVec2(0, 1));
                ImGui::SetCursorPosX(input_start_x);
                ImGui::SetNextItemWidth(input_width);
                ImGui::InputTextWithHint("##password", "Password..", inputpassword, 32, ImGuiInputTextFlags_EnterReturnsTrue);
            }
            }
            ImGui::PopStyleVar(2);
            ImGui::PopStyleColor(2);
            ImGui::EndChild();
        }
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);
        {
            ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x);
            bool showText = false;
            if (showText)
            {
                ImGui::Text("Registration Completed!");
            }
            if (ImGui::Button("Register"))
            {
                show_login_form = false;
                show_registration_form = true;
            }
            bool isPasswordCorrect = false;
            ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x);
            if (ImGui::Button("Log In", ImVec2(150, 40)))
            {
                Login(inputusername, inputemail, inputpassword);
                show_registration_form = false;
                show_login_form = true;
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
        }
        ImGui::PopStyleVar();
    }
    if (show_registration_form)
    {
        float input_width = 420;
        float container_width = 440;
        float center_x = ImGui::GetWindowWidth() * 0.5f;
        float container_start_x = center_x - input_width * 0.5f;
        float input_start_x = center_x - input_width * 0.73f;
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 10));
        ImGui::SetCursorPosX(container_start_x);
        ImGui::Dummy(ImVec2(0, 70));
        {
            {
                ImGui::SetCursorPosX(container_start_x);
                ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
                ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.137f, 0.164f, 0.2f, 1.0f));
                ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.137f, 0.164f, 0.2f, 1.0f));
                //ImGui::PushFont(ImFont * custom_font);
                ImGui::BeginChild("Username", (ImVec2(container_width, 40)));
                {
                    ImGui::Dummy(ImVec2(0, 1));
                    ImGui::SetCursorPosX(input_start_x);
                    ImGui::SetNextItemWidth(input_width);
                    ImGui::InputTextWithHint("##regusernameinput", "Username..", inputusername, 32, ImGuiInputTextFlags_EnterReturnsTrue);
                }
                ImGui::EndChild();
            }
            {
                ImGui::SetCursorPosX(container_start_x);
                ImGui::BeginChild("Email", (ImVec2(container_width, 40)));
                {
                    ImGui::Dummy(ImVec2(0, 1));
                    ImGui::SetCursorPosX(input_start_x);
                    ImGui::SetNextItemWidth(input_width);
                    ImGui::InputTextWithHint("##regemail", "Email..", inputemail, 32, ImGuiInputTextFlags_EnterReturnsTrue);
                }
                ImGui::EndChild();
            }
            {
                ImGui::SetCursorPosX(container_start_x);
                ImGui::BeginChild("Password", (ImVec2(container_width, 40)));
                {
                    ImGui::Dummy(ImVec2(0, 1));
                    ImGui::SetCursorPosX(input_start_x);
                    ImGui::SetNextItemWidth(input_width);
                    ImGui::InputTextWithHint("##regpassword", "Password..", inputpassword, 32, ImGuiInputTextFlags_EnterReturnsTrue);
                }
                ImGui::EndChild();
            }
        }
        {
            ImGui::SetCursorPosX(container_start_x);
            ImGui::BeginChild("ConfirmPassword", (ImVec2(container_width, 40)));
            {
                ImGui::Dummy(ImVec2(0, 1));
                ImGui::SetCursorPosX(input_start_x);
                ImGui::SetNextItemWidth(input_width);
                ImGui::InputTextWithHint("##confirmpass", "Confirm Password..", inputconfpass, 32, ImGuiInputTextFlags_EnterReturnsTrue);
            }
            ImGui::PopStyleVar(2);
            ImGui::PopStyleColor(2);
            ImGui::EndChild();
        }
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);
        {
            ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x);
        if (ImGui::Button("Cancel"))
        {
            show_registration_form = false;
            show_login_form = true;
        }
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x);
        if (ImGui::Button("Register", ImVec2(150, 40)))
        {
            if (string(inputpassword) == string(inputconfpass))
            {
                thread t1(registrationOutput, inputusername, inputemail, inputpassword);
                t1.detach();
                show_registration_form = false;
                show_login_form = true;
            }
            else
            {
                std::cout << "Registration Failed: Passwords do not match." << std::endl;
            }
        }
        }
        ImGui::PopStyleVar();
}
ImGui::PopStyleColor(3);
ImGui::PopStyleVar(2);
//ImGui::EndChild();
ImGui::End();
return 1;
}
