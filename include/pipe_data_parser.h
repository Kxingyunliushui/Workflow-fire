#pragma once

#include "data_parser.h"

class PipeDataParser : public IDataParser {
public:
    std::string parseData(const std::string& data) override;
};
