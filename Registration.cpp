#include <string>
#include "Registration.h"
#include <iostream>
#include <string>
#include <thread>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <fstream>

using namespace std;

void Registration(const char* inputusername, const char* inputemail, const char* inputpassword)
{
    std::string password = "\"44SA+&rnMz#4P7cas%+f@3)3#nB66CCE\"";
    const char* args[] = { "register.exe", inputusername, inputemail, inputpassword, "\"44SA+&rnMz#4P7cas%+f@3)3#nB66CCE\"", nullptr };
    int result = _spawnv(_P_WAIT, "register.exe", args);
}

int getRegistrationOutput()
{
    std::fstream myfile("D:\\data.txt", std::ios_base::in);
    char a;
    while (myfile >> a)
    {
        printf("%f ", a);
    }
    getchar();
    return 0;
}
