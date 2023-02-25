#include <iostream>
#include <cstdio>
#include <string>
#include <windows.h>

using namespace std;

int registrationOutput(const char* inputusername, const char* inputemail, const char* inputpassword)
{
    string password = "\"44SA+&rnMz#4P7cas%+f@3)3#nB66CCE\"";
    string command = "register.exe " + string(inputusername) + " " + string(inputemail) + " " + string(inputpassword) + " " + password;

    // Convert the command to a wide character string
    int wlen = MultiByteToWideChar(CP_UTF8, 0, command.c_str(), -1, NULL, 0);
    if (wlen == 0) {
        cerr << "Error: Failed to convert command to wide character string." << endl;
        return 1;
    }
    wchar_t* wcommand = new wchar_t[wlen];
    if (MultiByteToWideChar(CP_UTF8, 0, command.c_str(), -1, wcommand, wlen) == 0) {
        cerr << "Error: Failed to convert command to wide character string." << endl;
        delete[] wcommand;
        return 1;
    }

    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    HANDLE hReadPipe, hWritePipe;
    if (!CreatePipe(&hReadPipe, &hWritePipe, &sa, 0)) {
        cerr << "Error: Failed to create pipe." << endl;
        delete[] wcommand;
        return 1;
    }

    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.hStdError = hWritePipe;
    si.hStdOutput = hWritePipe;
    si.dwFlags |= STARTF_USESTDHANDLES;

    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(NULL, wcommand, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
        cerr << "Error: Failed to create process." << endl;
        CloseHandle(hReadPipe);
        CloseHandle(hWritePipe);
        delete[] wcommand;
        return 1;
    }

    CloseHandle(pi.hThread);

    // Close the write end of the pipe so we can read from the read end
    CloseHandle(hWritePipe);

    // Read the output of the command
    char buffer[128];
    string result = "";
    DWORD bytesRead;
    while (ReadFile(hReadPipe, buffer, sizeof(buffer), &bytesRead, NULL) && bytesRead != 0) {
        result.append(buffer, bytesRead);
    }

    // Close the read end of the pipe
    CloseHandle(hReadPipe);

    // Wait for the process to exit
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Get the exit code of the process
    DWORD exitCode;
    if (!GetExitCodeProcess(pi.hProcess, &exitCode))
    {
        cerr << "Error: Failed to get exit code." << endl;
    }
    else
    {
        cout << "Success registration " << exitCode << "." << endl;
    }

    // Close the process and thread handles
    CloseHandle(pi.hProcess);
    return 1;
}
