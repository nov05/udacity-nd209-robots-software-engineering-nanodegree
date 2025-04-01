#include <iostream>
#include <direct.h> // For _getcwd()
#include <string>

int main()
{
    // Get and print the current working directory
    char cwd[1024];
    if (_getcwd(cwd, sizeof(cwd)) != NULL)
    {
        std::cout << "Current working directory: " << cwd << std::endl;
    }
    else
    {
        std::cerr << "Error: Unable to get the current directory." << std::endl;
    }

    // Wait for user input before closing the console
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();  // Waits for Enter key press

    return 0;
}

// Output example:
// Current working directory: D:\Program Files\msys64\ucrt64\bin