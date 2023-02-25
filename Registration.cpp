#include <string>
#include "Registration.h"
#include <iostream>
#include <string>
#include <thread>
#include <process.h>

void Registration(const char* inputusername, const char* inputemail, const char* inputpassword)
{
    std::string password = "\"44SA+&rnMz#4P7cas%+f@3)3#nB66CCE\"";
    const char* args[] = { "register.exe", inputusername, inputemail, inputpassword, "\"44SA+&rnMz#4P7cas%+f@3)3#nB66CCE\"", nullptr };
    /*std::string command = "register.exe " + std::string(inputusername) + " " + std::string(inputemail) + " " + std::string(inputpassword) + " " + std::string(password);
    system(command.c_str());*/
    int result = _spawnv(_P_WAIT, "register.exe", args);
    std::cout << result;
}
