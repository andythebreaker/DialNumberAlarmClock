#include <iostream>
#include <chrono>

using namespace std;

int main() {
  // Get the current time
  auto now = std::chrono::system_clock::now();
  auto time_t = std::chrono::system_clock::to_time_t(now);

  // Loop until 5 o'clock today
  while (true) {
    // Get the current time again
    now = std::chrono::system_clock::now();
    time_t = std::chrono::system_clock::to_time_t(now);
    cout << "The current time is " << ctime(&time_t) << endl;


    // Check if it is 5 o'clock yet
    if (localtime(&time_t)->tm_min == 17) {
      break;
    }
  }

  return 0;
}
