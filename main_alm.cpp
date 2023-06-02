#include <iostream>
#include <chrono>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <thread>
#include <ctime>

#ifdef _WIN32
#include <windows.h> // for Sleep function (milliseconds)
#else
#include <unistd.h> // for usleep function (microseconds)
#endif

#ifdef _WIN32
const std::string CMD = "dir";
#else
const std::string CMD = "ls";
#endif

const std::string dial_phone = "adb -s R9JNA08TQDJ shell am start -a android.intent.action.CALL -d tel:117";
const std::string hang_up = "adb shell input keyevent 6";

using namespace std;

void exec(const char* cmd)
{
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe)
    {
        std::cerr << "Error executing command." << std::endl;
        // return "";
    }
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
        result += buffer;
    }
    pclose(pipe);
    //return result;
    std::cout << result << std::endl;
}

int main()
{
    // Get the current time
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);

    // Loop until 5 o'clock today
    while (true)
    {
        // Get the current time again
        now = std::chrono::system_clock::now();
        time_t = std::chrono::system_clock::to_time_t(now);
#ifdef _WIN32
        system("cls");
#else
        // For Linux/macOS, you can use system("clear") or other methods to clear the screen
        system("clear");
#endif
        cout << "The current time is " << ctime(&time_t) << endl;
        // Delay for a certain period (e.g., 1 second)
#ifdef _WIN32
        Sleep(1000); // 1000 milliseconds = 1 second
#else
        usleep(1000000); // 1000000 microseconds = 1 second
#endif
        int odd_chk=0;

        // Check if it is 5 o'clock yet
        if (localtime(&time_t)->tm_min == 51)
        {
            //std::string output = exec(CMD.c_str());
            //std::cout << output << std::endl;
            //-exec(CMD.c_str());
            while (true)
            {
                odd_chk=odd_chk==0?1:0;
                // Execute the command
                if (odd_chk==1)
                    std::system(dial_phone.c_str());
                else
                    std::system(hang_up.c_str());
                // Wait for 10 seconds
                std::time_t startTime = std::time(nullptr);
                while (std::difftime(std::time(nullptr), startTime) < 10)
                    //std::system(hang_up.c_str());
                    continue;
            }


            break;
        }
    }

    return 0;
}
