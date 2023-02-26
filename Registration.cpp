#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <stdio.h>
#include <atlstr.h>
#include <stdexcept>

void registrationOutput(const char* inputusername, const char* inputemail, const char* inputpassword)
{
    std::string username = inputusername;
    std::string email = inputemail;
    std::string pass = inputpassword;

    std::string password = "\"44SA+&rnMz#4P7cas%+f@3)3#nB66CCE\"";
    std::string command = "register.exe " + username + " " + email + " " + pass + " " + password;

    // Open a pipe to the command line and execute the command
    std::array<char, 256> buffer;
    std::string result = "";
    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }
    int exitCode = _pclose(pipe);
    if (exitCode != 0) {
        std::cerr << "Error executing command. errno=" << errno << ", exit code=" << exitCode << std::endl;
    }

    // Print the output of the command
    std::cout << result << std::endl;
}
