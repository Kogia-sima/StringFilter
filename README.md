# StringFilter Library

[![Build Status](https://travis-ci.org/Kogia-sima/StringFilter.svg?branch=master)](https://travis-ci.org/Kogia-sima/StringFilter) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/Kogia-sima/StringFilter/blob/master/LICENSE) ![gcc version](https://img.shields.io/badge/gcc-4.8-blue.svg) ![clang version](https://img.shields.io/badge/clang-3.7-blue.svg)

StringFilter is a fast filter for strings. You can use this filter for filtering large sentence set by complex conditions. Basic boolean operatoes (and, or, not) are supported.

For example, if you want to extract the sentences which has 'apple' or 'orange' keyword inside, you create filter object as `StringFilter("apple or orange")` and then check those sentences as fast as possible.

## Prerequisite

- CMake >= 2.8.12
- C++ compiler with C++11 support
- (Optional) Python 2.7 or 3.x

I have tested the program using the following compilers.

- GNU GCC g++ (4.8.5)
- Clang++ (3.7.1)


## C++ API

### Installation

```console
$ git clone --recursive https://github.com/Kogia-sima/StringFilter.git
$ cd StringFilter
$ mkdir -p build
$ cd build
$ cmake -DBUILD_SHARED_LIBS=ON ..
$ make
$ sudo make install
```

### Usage

```cpp
#include <iostream>
#include <StringFilter/StringFilter.hpp>

int main() {
  using namespace std;

  StringFilter sf("rabbit and turtle");
  
  cout << boolalpha;
  cout << sf.is_valid("rabbit vs turtle") << endl;  // => true
  cout << sf.is_valid("Sea turtles were released to the ocean.") << endl;  // => false

  return 0;
}
```

## Python API

### Installation

```console
$ pip install git+https://github.com/Kogia-sima/StringFilter.git
```

### Example usage

```python
import StringFilter

sf = StringFilter.StringFilter('rabbit and turtle')
print(sf.is_valid('rabbit vs turtle'))  # => True
print(sf.is_valid('Sea turtles were released to the ocean.'))  # => False
```

## TODO

- Performance test
- namespace support
- boolean operator for StringFilter class.
- Case insensitive support.
