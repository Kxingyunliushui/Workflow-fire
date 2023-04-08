#include "config_manager.h"
#include "http_data_source.h"
#include "pipe_data_source.h"
#include "http_data_parser.h"
#include "pipe_data_parser.h"
#include "http_data_output.h"
#include "pipe_data_output.h"
#include <fstream>
#include <stdexcept>
#include <iostream>


ConfigManager::ConfigManager(const std::string& config_file) {
    std::ifstream file(config_file);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Cannot open config file.");
    }
    loadConfig(file);
}


void ConfigManager::loadConfig(std::ifstream& file) {
    std::string line;
    while (std::getline(file, line)) {
        std::cout << "Reading line: " << line << std::endl; // 添加调试信息
        if (!line.empty()) {
            size_t pos = line.find(":");
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            config_map_[key] = value;
        }
    }
}

IDataSource* ConfigManager::getDataSource() {
    const std::string& dataSourceType = config_map_["dataSource"];
    if (dataSourceType == "httpDataSource") {
        return new HttpDataSource();
    }
    else if (dataSourceType == "pipeDataSource") {
        return new PipeDataSource();
    }
    else {
        throw std::runtime_error("Unknown data source type");
    }
}

IDataParser* ConfigManager::getDataParser() {
    const std::string& dataParserType = config_map_["dataParser"];
    if (dataParserType == "httpDataParser") {
        return new HttpDataParser();
    }
    else if (dataParserType == "pipeDataParser") {
        return new PipeDataParser();
    }
    else {
        throw std::runtime_error("Unknown data parser type");
    }
}

IDataOutput* ConfigManager::getDataOutput() {
    const std::string& dataOutputType = config_map_["dataOutput"];
    if (dataOutputType == "httpDataOutput") {
        return new HttpDataOutput();
    }
    else if (dataOutputType == "pipeDataOutput") {
        return new PipeDataOutput();
    }
    else {
        throw std::runtime_error("Unknown data output type");
    }
}
