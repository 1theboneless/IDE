#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"
#include <string.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <string>
#include <algorithm>

using namespace std;

string username;
string password;
string confirmpass;
char inputusername[CHAR_MAX];
char inputpassword[CHAR_MAX];
char inputconfpass[CHAR_MAX];

bool show_registration_form = false;
bool show_login_form = true;

int chartostr()
{
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
    ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x * 0.5, ImGui::GetIO().DisplaySize.y * 0.5));
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus;
    float center_x = ImGui::GetWindowWidth() * 0.5f;
    ImGui::Begin("Login");
    if (show_login_form)
    {
        ImGui::SetCursorPosX(center_x);
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Username", NULL, true).x * 0.5);
        ImGui::Text("Input Username");
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Username", NULL, true).x);
        ImGui::SetNextItemWidth(200);
        ImGui::InputText("##usernameinput", inputusername, CHAR_MAX);


        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x * 0.5);
        ImGui::Text("Input Password");
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x);
        ImGui::SetNextItemWidth(200);
        ImGui::InputText("##password", inputpassword, CHAR_MAX, ImGuiInputTextFlags_Password);

        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Register", NULL, true).x * 0.55);

        if (ImGui::Button("Register"))
        {
            show_login_form = false;
            show_registration_form = true;
        }
        ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Password", NULL, true).x);
        if (ImGui::Button("Log In", ImVec2(200, 50)))
        {
            if (strcmp() == 1)
            {
                ImGui::Text("%s", text.c_str());
            }
        }
    }
if (show_registration_form)
{
ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Username", NULL, true).x * 0.5);
ImGui::Text("Input Username");
ImGui::SetCursorPosX(center_x - ImGui::CalcTextSize("Input Username", NULL, true).x);
ImGui::SetNextItemWidth(200);
ImGui::InputText("##regusernameinput", inputusername, CHAR_MAX);
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
username = string(inputusername);
password = string(inputpassword);
show_registration_form = false;
show_login_form = true;
}
else
{
std::cout << "Registration Failed: Passwords do not match." << std::endl;
}
}
}
ImGui::End();
return 1;
}
