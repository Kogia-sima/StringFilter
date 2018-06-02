/*
 * Expression parser for caption filters
 * copyright: Kogia-sima 2018
 */

#include <stdexcept>
#include "example1/Parser.hpp"

Node* Parser::parse(const char* expr) {
  M_expr = expr;
  Node* pRoot = expression();
  return pRoot;
}

inline Node* Parser::expression() {
  Node* pLeft = factor();

  while (peek() != '\0') {
    Node* op = term();
    if (op->type() == NodeType::AND || op->type() == NodeType::OR) {
      spaces();
      Node* pRight = factor();
      op->setLeft(pLeft);
      op->setRight(pRight);
      pLeft = op;
    } else {
      break;
    }
  }

  return pLeft;
}

inline Node* Parser::factor() {
  Node* pNode;

  if (peek() == '(') {
    next();
    spaces();
    pNode = expression();
    if (peek() != ')') {
      throw std::runtime_error("Parse error1.");
    }
    next();
    spaces();

  } else {
    pNode = term();
  }

  return pNode;
}

inline Node* Parser::term() {
  Node* pNode;
  StringView next_word = word();
  spaces();

  if (next_word == "not") {
    StringView target_word = word();
    pNode = new Node(target_word, NodeType::NEGATIVE);
    spaces();
  } else if (next_word == "and") {
    pNode = new Node(next_word, NodeType::AND);
  } else if (next_word == "or") {
    pNode = new Node(next_word, NodeType::OR);
  } else {
    pNode = new Node(next_word, NodeType::POSITIVE);
  }

  return pNode;
}

inline StringView Parser::word() {
  const int start = M_pos;

  while (peek() != ' ' && peek() != ')' && peek() != '\0') {
    next();
  }

  const int end = M_pos;
  return StringView(&M_expr[start], end - start);
}

inline void Parser::next() {
  ++M_pos;
  if (M_pos > M_expr.size()) {
    throw std::runtime_error("Parse error2.");
  }
}

inline void Parser::spaces() noexcept {
  while (M_expr[M_pos] == ' ') {
    next();
  }
}
