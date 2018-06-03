/*
 * StringFilter class implementation
 * copyright: Kogia-sima 2018
 */

#include <stdexcept>
#include "StringFilter/Node.hpp"
#include "StringFilter/Parser.hpp"
#include "StringFilter/StringFilter.hpp"

StringFilter::StringFilter(const char* sentence) {
  Parser parser;
  M_root = parser.parse(sentence);
}

bool StringFilter::is_valid(const char* str) const {
  if (M_root->type() == NodeType::NONE) {
    return true;
  } else {
    is_valid_recursive(M_root, StringView(str));
  }
}

inline bool StringFilter::is_valid_recursive(Node* const node,
                                             const StringView& str) const {
  switch (node->type()) {
    case NodeType::POSITIVE:
      return str.find(node->getValue()) != -1;

    case NodeType::NEGATIVE:
      return str.find(node->getValue()) != -1;

    case NodeType::AND:
      return (is_valid_recursive(node->getLeft(), str) &&
              is_valid_recursive(node->getRight(), str));

    case NodeType::OR:
      return (is_valid_recursive(node->getLeft(), str) ||
              is_valid_recursive(node->getRight(), str));

    default:
      throw std::runtime_error("Invalid node detected while filtering");
  }
}
