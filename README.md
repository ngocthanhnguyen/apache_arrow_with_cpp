## Toy project to manipulate the Apache Framework by using C++
This respository intends to store the code to investigate the Apache Arrow framework.

# Purpose
Implement a functionality to convert an arrow::schema instance to JSON string and vice versa. An executable program is also created to test the functionality.

# Development environment
Ubuntu 20.04 WSL (Ubuntu on Windows 10)

# Installation
- Apache Arrow: follow the guide at https://arrow.apache.org/install/.
- JSON library for C++ developed by nlohmann at https://github.com/nlohmann/json. Below is the installation procedure:
```
git clone https://github.com/nlohmann/json
cd json
mkdir build
cmake ..
make install
```

# Building the program
```
https://github.com/thanhnn-uit-13/apache_arrow_with_c- # this project
apache_arrow_with_c-
mkdir build
cmake ..
```

# Using the program
1. Test the functionality to convert an arrow::schema instance to JSON string
```
ExecTestSchemaJsonConversion conversion Schema2Json
```
2. Test the functionality to convert a JSON string to arrow::schema instance
```
ExecTestSchemaJsonConversion conversion Json2Schema
```
3. Test the functionality to convert an arrow::schema instance to JSON string and back to the original arrow::schema instance
```
ExecTestSchemaJsonConversion conversion Schema2Json2Schema
```
4. Test the functionality to convert a JSON string to arrow::schema instance and back to the original JSON string
```
ExecTestSchemaJsonConversion conversion Json2Schema2Json
```

# Structure
```
apache_arrow_with_c-
├── test.cpp: contains the code to test the functionality
│── CMakeLists.txt: build configuration file for the whole project
└── src
    ├── json_schema.(h/cpp): implements the functionality to convert a JSON string to arrow::schema instance 
    ├── schema_json.(h/cpp): implements the functionality to convert an arrow::schema instance to JSON string
    └── CMakeLists.txt: build configuration file for the folder
```
