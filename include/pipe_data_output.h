#pragma once

#include "data_output.h"

class PipeDataOutput : public IDataOutput {
public:
    void sendData(const std::string& data) override;
};
