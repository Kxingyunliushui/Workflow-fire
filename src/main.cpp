#include "config_manager.h"
#include "data_processing_engine.h"


#ifdef _WIN32
#include <iostream>
#include <string>
#include <Windows.h>
std::string getExecutablePath() {
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    return std::string(buffer).substr(0, pos);
}
#else __linux__
#include <iostream>
#include <string>
#include <limits.h>
#include <unistd.h>
std::string getExecutablePath() {
    char buffer[PATH_MAX];
    ssize_t length = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (length != -1) {
        buffer[length] = '\0';
        std::string::size_type pos = std::string(buffer).find_last_of("\\/");
        return std::string(buffer).substr(0, pos);
    }
    return "";
}
#endif

int main() {
    std::string path = getExecutablePath();
    std::cout << "Executable path: " << path << std::endl;
    ConfigManager config_manager("../../../config/config.txt");
    DataProcessingEngine engine(&config_manager);
    engine.start();
    return 0;
}
