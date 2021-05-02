#pragma once

#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

#include <arrow/dataset/dataset.h>
#include <nlohmann/json.hpp>

class JSONSchema {
  private:
    std::string m_jsonString;
    
    std::vector<std::string> extractFields();
    
  public:
    JSONSchema(const std::string& jsonString);
    
    std::shared_ptr<arrow::Schema> convert2Schema();
};