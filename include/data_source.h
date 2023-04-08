#pragma once

#include <string>

class IDataSource {
public:
    virtual ~IDataSource() {}
    virtual std::string fetchData() = 0;
};
