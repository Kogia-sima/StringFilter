/*
 * Node class declaration
 * copyright: Kogia-sima 2018
 */

#include <cstdio>
#include "example1/Node.hpp"

Node::~Node() {
  destroy_recursive();
}

void Node::debug_print() const noexcept {
  print_recursive(0);
}

inline void Node::destroy_recursive() {
  if (M_left != nullptr) {
    M_left->destroy_recursive();
    delete M_left;
    M_left = nullptr;
  }
  if (M_right != nullptr) {
    M_right->destroy_recursive();
    delete M_right;
    M_right = nullptr;
  }
}

inline void Node::print_recursive(int level) const noexcept {
  if (M_left != nullptr) {
    M_left->print_recursive(level + 1);
  }

  printf("%*s", level << 1, "");

  if (M_type == NodeType::NEGATIVE) {
    printf("^");
  }

  printf("%.*s\n", M_value.size(), M_value.data());

  if (M_right != nullptr) {
    M_right->print_recursive(level + 1);
  }
}
