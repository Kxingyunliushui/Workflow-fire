#pragma once

#include "data_source.h"

class HttpDataSource : public IDataSource {
public:
    std::string fetchData() override;
};
