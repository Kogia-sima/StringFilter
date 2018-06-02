/*
 * StringView class declaration
 * copyright: Kogia-sima 2018
 */

#ifndef STRINGFILTER_STRINGVIEW_HPP
#define STRINGFILTER_STRINGVIEW_HPP

class StringView {
 public:
  StringView() {
    M_ptr = nullptr;
    M_length = 0;
  }

  explicit StringView(const char* ptr);

  StringView(const char* ptr, int length) {
    M_ptr = ptr;
    M_length = length;
  }

  StringView(const StringView&) = default;

  StringView(StringView&&) = default;

  const char* data() const noexcept { return M_ptr; }

  int size() const noexcept { return M_length; }

  const char& operator[](int idx) const noexcept { return M_ptr[idx]; }

  StringView& operator=(const char* str);

  bool operator==(const char* str) const noexcept;

 private:
  const char* M_ptr;
  int M_length;
};

#endif
