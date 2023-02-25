#include <string>
#include "Registration.h"
#include <iostream>
#include <string>
#include <thread>

void Registration(const char* inputusername, const char* inputemail, const char* inputpassword)
{
    std::string password = "\"44SA+&rnMz#4P7cas%+f@3)3#nB66CCE\"";
    std::string command = "register.exe " + std::string(inputusername) + " " + std::string(inputemail) + " " + std::string(inputpassword) + " " + std::string(password);
    system(command.c_str());
}
