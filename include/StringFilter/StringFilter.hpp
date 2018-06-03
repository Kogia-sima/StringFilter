/*
 * StringFilter class declaration
 * copyright: Kogia-sima 2018
 */

#ifndef STRINGFILTER_STRINGFILTER_HPP
#define STRINGFILTER_STRINGFILTER_HPP

#include "Node.hpp"

class StringFilter {
 public:
  StringFilter() = delete;

  explicit StringFilter(const char* sentence);

  bool is_valid(const char* str) const;

  ~StringFilter() {
    delete M_sentence;
    delete M_root;
  }

 protected:
  bool is_valid_recursive(Node* const node, const StringView&) const;

 private:
  char* M_sentence;
  Node* M_root;
};

#endif
