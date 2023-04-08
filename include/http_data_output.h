#pragma once

#include "data_output.h"

class HttpDataOutput : public IDataOutput {
public:
    void sendData(const std::string& data) override;
};
