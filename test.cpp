#include "../src/json_schema.h"
#include "../src/schema_json.h"
#include <cassert>

/*
  TEST 1: Convert an arrow::schema instance to JSON string
*/
int Schema2Json() {
  std::cout << "TEST: Convert an arrow::schema to JSON string" << std::endl;
  
  //input test data
  std::string inputJson = "{\"field1\":[],\"field2\":[]}";
  
  // impl
  SchemaJSON oSchemaJSON(inputJson);
  std::string exportedJson = oSchemaJSON.exportJson();
  
  // checkpoint
  assert(inputJson.compare(exportedJson) == 0);
  std::cout << "Pass!" << std::endl;
  return 0;
}

/*
  TEST 2: Convert a JSON string to arrow::schema instance
*/
int Json2Schema() {
  std::cout << "TEST: Convert a JSON string to arrow::schema instance" << std::endl;
  
  // input test data
  std::string inputJson = "{\"field1\":[],\"field2\":[]}";
  std::shared_ptr<arrow::Schema> schema = arrow::schema({arrow::field("field1", arrow::int64()),
                                                         arrow::field("field2", arrow::int64())});
                               
  // impl.
  JSONSchema oJsonSchema(inputJson);
  std::shared_ptr<arrow::Schema> schemaFromJson = oJsonSchema.convert2Schema();
  
  // checkpoint
  assert(schemaFromJson->Equals(*schema) == true);
  std::cout << "Pass!" << std::endl;
  return 0;  
}

/*
  TEST 3: Convert an arrow::schema instance to JSON string and back to arrow::schema
*/
int Schema2Json2Schema() {
  std::cout << "TEST: Convert an arrow::schema instance to JSON string and back to arrow::schema" << std::endl;
  
  // input test data
  std::string inputJson = "{\"field1\":[],\"field2\":[]}";
  std::shared_ptr<arrow::Schema> schema = arrow::schema({arrow::field("field1", arrow::int64()),
                                                         arrow::field("field2", arrow::int64())});
  
  // impl
  SchemaJSON oSchemaJSON(inputJson);
  std::string exportedJson = oSchemaJSON.exportJson();
  JSONSchema oJsonSchema(exportedJson);
  std::shared_ptr<arrow::Schema> schemaExported = oJsonSchema.convert2Schema();
  
  //checkpoint
  assert(schema->Equals(*schemaExported) == true);
  std::cout << "Pass!" << std::endl;
  
  return 0;
}

/*
  TEST 4: Convert a JSON string to arrow::schema instance and back to JSON string
*/
int Json2Schema2Json() {
  std::cout << "TEST: Convert a JSON string to arrow::schema instance and back to JSON string" << std::endl;
  
  // input test data
  std::string inputJson = "{\"field1\":[],\"field2\":[]}";
  
  // impl
  JSONSchema oJsonSchema(inputJson);
  std::shared_ptr<arrow::Schema> schemaFromJson = oJsonSchema.convert2Schema();
  SchemaJSON oSchemaJSON(schemaFromJson);
  std::string exportedJson = oSchemaJSON.exportJson();
  
  // checkpoint
  assert(exportedJson.compare(exportedJson) == 0);
  std::cout << "Pass!" << std::endl;
  
  return 0;
}

int main(int agrc, char** agrv) {
  if (agrc < 3) {
    std::cerr << "Not enough parameters" << std::endl;
    return 0;
  }
  
  std::string program(agrv[1]);
  std::string testTarget(agrv[2]);
  
  if (program.compare("conversion") == 0) {
    if (testTarget.compare("Schema2Json") == 0)
      Schema2Json();
    else if (testTarget.compare("Json2Schema") == 0)
      Json2Schema();
    else if (testTarget.compare("Schema2Json2Schema") == 0)
      Schema2Json2Schema();
    else if (testTarget.compare("Json2Schema2Json") == 0)
      Json2Schema2Json();
    else
      std::cerr << "Unsupported test target" << std::endl;
  } else {
    std::cerr << "Unsupported test program" << std::endl;
  }
  return 0;
}