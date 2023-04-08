#pragma once

#include "config_manager.h"

class DataProcessingEngine {
public:
    DataProcessingEngine(ConfigManager* config_manager);
    void start();
    void stop();

private:
    ConfigManager* config_manager_;
    IDataSource* data_source_;
    IDataParser* data_parser_;
    IDataOutput* data_output_;
};
