#include <string>
#include "Login.h"
#include <iostream>

void Login(const char* inputusername, const char* inputemail, const char* inputpassword)
{
    std::string command = "python test.py " + std::string(inputusername) + " " + std::string(inputemail) + " " + std::string(inputpassword);
    system(command.c_str());
}
