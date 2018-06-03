#include <iostream>
#include <StringFilter/StringFilter.hpp>

int main(int argc, char *argv[]) {
  StringFilter sf("rabbit and turtle");

  std::cout << std::boolalpha
            << sf.is_valid("rabbit and turtle") << "\n"
            << sf.is_valid("Sea turtles were released to the ocean.")
            << std::endl;

  return 0;
}
