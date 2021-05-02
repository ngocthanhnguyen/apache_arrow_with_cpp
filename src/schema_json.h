#pragma once

#include<vector>
#include<string>

#include <arrow/dataset/dataset.h>
#include <nlohmann/json.hpp>

class SchemaJSON {
  private:
    std::shared_ptr<arrow::Schema> m_schema;
    
    int init(const std::vector<std::string>& fields);
    std::vector<std::string> extractFields(const std::string& json);
    
  public:
    SchemaJSON(const std::string& json);
    SchemaJSON(const std::shared_ptr<arrow::Schema> &ptrSchema);
    ~SchemaJSON();
    
    std::string exportJson();
    std::shared_ptr<arrow::Schema> getSchema();
};