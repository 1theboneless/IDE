#include <string>
#include "Registration.h"
#include <iostream>

void Registration(const char* inputusername, const char* inputemail, const char* inputpassword)
{
    std::string command = "python test.py " + std::string(inputusername) + " " + std::string(inputemail) + " " + std::string(inputpassword);
    system(command.c_str());
}
