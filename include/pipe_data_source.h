#pragma once

#include "data_source.h"

class PipeDataSource : public IDataSource {
public:
    std::string fetchData() override;
};
