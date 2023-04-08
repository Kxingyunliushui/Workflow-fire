#pragma once

#include <string>

class IDataParser {
public:
    virtual ~IDataParser() {}
    virtual std::string parseData(const std::string& data) = 0;
};
