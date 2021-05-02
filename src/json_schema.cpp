#include "json_schema.h"

JSONSchema::JSONSchema(const std::string& jsonString) : m_jsonString(jsonString) {
  
}

std::vector<std::string> JSONSchema::extractFields() {
  nlohmann::json oJson = nlohmann::json::parse(m_jsonString);
  std::vector<std::string> fields;  
  for (auto& it : oJson.items()) {
    fields.push_back(it.key());
  }
  return fields;
}

std::shared_ptr<arrow::Schema> JSONSchema::convert2Schema() {
  std::vector<std::string> fieldNames = this->extractFields();
  std::vector<std::shared_ptr<arrow::Field>> arrowFields;
  for (auto& it : fieldNames) {
    std::shared_ptr<arrow::Field> arrowField = arrow::field(it, arrow::int64());
    arrowFields.push_back(arrowField);
  }
  return arrow::schema(arrowFields);
}