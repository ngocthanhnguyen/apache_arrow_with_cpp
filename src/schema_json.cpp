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

#include "./schema_json.h"

SchemaJSON::SchemaJSON(const std::shared_ptr<arrow::Schema> &ptrSchema)
    : m_schema(ptrSchema) {}

SchemaJSON::SchemaJSON(const std::string &json) {
  std::vector<std::string> fields = this->extractFields(json);
  this->init(fields);
}

SchemaJSON::~SchemaJSON() {}

std::vector<std::string> SchemaJSON::extractFields(const std::string &json) {
  nlohmann::json oJson = nlohmann::json::parse(json);
  std::vector<std::string> fields;
  for (auto &it : oJson.items()) {
    fields.push_back(it.key());
  }
  return fields;
}

int SchemaJSON::init(const std::vector<std::string> &fieldNames) {
  std::vector<std::shared_ptr<arrow::Field>> arrowFields;
  for (auto &it : fieldNames) {
    std::shared_ptr<arrow::Field> arrowField = arrow::field(it, arrow::int64());
    arrowFields.push_back(arrowField);
  }
  m_schema = arrow::schema(arrowFields);
  return 0;
}

std::string SchemaJSON::exportJson() {
  std::string json = "{";

  for (int iCol = 0; iCol < m_schema->num_fields(); ++iCol) {
    std::shared_ptr<arrow::Field> field = m_schema->field(iCol);
    json += "\"" + field->name() + "\":[],";
  }

  json = json.substr(0, json.size() - 1);
  json += "}";

  return json;
}

std::shared_ptr<arrow::Schema> SchemaJSON::getSchema() { return m_schema; }
