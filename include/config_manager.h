#pragma once

#include <string>
#include <unordered_map>
#include "data_source.h"
#include "data_parser.h"
#include "data_output.h"

class ConfigManager {
public:
    ConfigManager(const std::string& config_file);
    IDataSource* getDataSource();
    IDataParser* getDataParser();
    IDataOutput* getDataOutput();

private:
    void loadConfig(std::ifstream& file);
    std::unordered_map<std::string, std::string> config_map_;
};
