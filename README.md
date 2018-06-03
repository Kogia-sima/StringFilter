# StringFilter Library

[![Build Status](https://travis-ci.org/Kogia-sima/StringFilter.svg?branch=master)](https://travis-ci.org/Kogia-sima/StringFilter)

StringFilter is a fast filter for strings. Basic boolean operators (and, or, not) are supported.

## Build

```console
$ mkdir -p build
$ cd build
$ cmake -DBUILD_SHARED_LIBS=ON ..
$ make
$ sudo make install
```

## Usage (C++)

```cpp
#include <iostream>
#include <StringFilter/StringFilter.hpp>

int main() {
  StringFilter sf("rabbit and turtle");
  sf.is_valid("rabbit vs turtle");  // => true
  sf.is_valid("Sea turtles are released to the ocean.");  // => false

  return 0;
}
```
