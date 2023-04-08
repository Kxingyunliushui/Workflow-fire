#pragma once

#include <string>

class IDataOutput {
public:
    virtual ~IDataOutput() {}
    virtual void sendData(const std::string& data) = 0;
};
