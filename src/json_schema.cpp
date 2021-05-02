// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#include "json_schema.h"

JSONSchema::JSONSchema(const std::string& jsonString) :
      m_jsonString(jsonString) {
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
