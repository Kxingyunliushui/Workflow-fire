#include "data_processing_engine.h"

DataProcessingEngine::DataProcessingEngine(ConfigManager* config_manager)
    : config_manager_(config_manager) {
    data_source_ = config_manager->getDataSource();
    data_parser_ = config_manager->getDataParser();
    data_output_ = config_manager->getDataOutput();
}

void DataProcessingEngine::start() {
    std::string data = data_source_->fetchData();
    std::string parsed_data = data_parser_->parseData(data);
    data_output_->sendData(parsed_data);
}

void DataProcessingEngine::stop() {
    // Add any necessary cleanup or stopping code here
}
