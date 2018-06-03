/*
 * StringView class definition
 * copyright: Kogia-sima 2018
 */

#include <cstring>
#include "StringFilter/StringView.hpp"

StringView::StringView(const char* ptr) {
  M_ptr = ptr;
  M_length = strlen(ptr);
}

int StringView::find(const StringView& key) const noexcept {
  const char* it1 = M_ptr;
  const char* it2 = key.M_ptr;
  const char* it3;
  int i_max = M_length - key.M_length + 1;
  int j;

  for (int i = 0; i < i_max; ++i, ++it1) {
    if (*it1 == *it2) {
      it3 = it1;
      for (j = 0; j < key.M_length; ++j) {
        if (*it3 == *it2) {
          ++it3;
          ++it2;
        } else {
          break;
        }
      }
      if (j == key.M_length) {
        return i;
      }
      it2 = key.M_ptr;
    }
  }

  return -1;
}

StringView& StringView::operator=(const char* str) {
  M_ptr = str;
  M_length = strlen(str);
}

bool StringView::operator==(const char* str) const noexcept {
  const char* it1 = M_ptr;
  const char* it2 = str;

  for (int i = 0; i < M_length; ++i, ++it1, ++it2) {
    if (*it1 == '\0') {
      break;
    }
    if (*it1 != *it2) {
      return false;
    }
  }

  if (*it2 == '\0') {
    return true;
  } else {
    return false;
  }
}
