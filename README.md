# StringFilter Library

StringFilter is a fast filter for strings. Basic boolean operators (and, or, not) are supported.

## Python interface

Although StringFilter is written in C++, you can also use it as python module.

For example,

```python
import StringFilter

sf = StringFilter.StringFilter("apple or (not orange and strawberry)")
sf.is_valid('This is an apple pie.')  # => True
sf.is_valid('straw is an agricultural by-product.')  # => False
```

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
