/*
 * Expression parser for caption filters
 * copyright: Kogia-sima 2018
 */

#ifndef STRINGFILTER_PARSER_HPP
#define STRINGFILTER_PARSER_HPP

#include <cstring>
#include "example1/StringView.hpp"
#include "example1/Node.hpp"

class Parser {
 public:
  Parser() {}

  Node* parse(const char* expr);

 protected:
  Node* expression();
  Node* factor();
  Node* term();
  void next();
  StringView word();
  void spaces() noexcept;

  const char& peek() const { return M_expr[M_pos]; }

 private:
  StringView M_expr;
  int M_pos = 0;
};

#endif
