# C JSON Parser

## Description of the project
-------------------

Motivated by an educational purpose, I decided to create a C implementation of a JSON parser (https://www.json.org/json-en.html)


## Features available

The latest version of the library gives you the possibility to

- Parse an serialized JSON array (with `json_array_t` type)
- Parse an serialized JSON object (with `json_object_t` type)
- Get any element with key correspondance using macros (`J_GET_INT`, `J_GET_STR`, `J_GET_BOOL`, `J_GET_NULL`, `J_GET_OBJ`, `J_GET_ARRAY`)


## Installation

In order to install the library globally, clone the repository:
```
$ git clone https://github.com/pr0m3th3usEx/CJsonParser.git
```

And run the following command:
```
$ sudo make install
```

## How to use ?

The library gives 2 header files:
- `cjson/json_parser.h` : All JSON parsing tools
- `cjson/list.h` : Linked list operations

## License

The project is under MIT License.

## Contributors

@Pr0m3th3usEx - Thomas Michel
