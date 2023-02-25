#include <iostream>
#include <cstdlib>
#include <string>

int compile()
{
    std::cout << "Enter C++ code:\n";
    std::string code;
    std::getline(std::cin, code); // read user input

    // compile and execute code
    std::string command = "cl /EHsc /Fe:temp.exe"; // compile command
    std::system((command + " /Fo:temp.obj /c -", code).c_str()); // compile code
    std::system("./temp.exe"); // execute compiled code

    return 0;
}
