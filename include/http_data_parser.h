#pragma once

#include "data_parser.h"

class HttpDataParser : public IDataParser {
public:
    std::string parseData(const std::string& data) override;
};
