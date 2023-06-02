#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

#ifdef _WIN32
    const std::string CMD = "dir";
#else
    const std::string CMD = "ls";
#endif

std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) {
        std::cerr << "Error executing command." << std::endl;
        return "";
    }
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);
    return result;
}

int main() {
    std::string output = exec(CMD.c_str());
    std::cout << output << std::endl;
    return 0;
}
