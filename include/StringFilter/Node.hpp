/*
 * Node class declaration
 * copyright: Kogia-sima 2018
 */

#ifndef STRINGFILTER_NODE_HPP
#define STRINGFILTER_NODE_HPP

#include "StringView.hpp"


enum struct NodeType {
  POSITIVE,
  NEGATIVE,
  AND,
  OR,
  NONE
};


class Node {
 public:
  Node() = delete;

  explicit Node(const StringView& value, NodeType type) : M_value(value) {
    M_type = type;
  }

  virtual ~Node();

  NodeType type() const noexcept { return M_type; }

  void setLeft(Node* node) noexcept { M_left = node; }

  void setRight(Node* node) noexcept { M_right = node; }

  Node* getLeft() const noexcept { return M_left; }

  Node* getRight() const noexcept { return M_right; }

  StringView& getValue() noexcept { return M_value; }

  const StringView& getValue() const noexcept { return M_value; }

  void debug_print() const noexcept;

 protected:
  void print_recursive(int level) const noexcept;
  void destroy_recursive();

 private:
  StringView M_value;
  NodeType M_type = NodeType::NONE;
  Node* M_left = nullptr;
  Node* M_right = nullptr;
};

#endif
