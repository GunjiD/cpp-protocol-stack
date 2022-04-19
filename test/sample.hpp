#ifndef SAMPLE_H_
#define SAMPLE_H_

#include <exception>
#include <string>

class sample {
public:
  int add(int a, int b) { return a + b; }
  void throw_exception() throw(std::exception) { throw std::exception(); }
  void no_throw_exception() { ; }
  std::string get_str_foo() throw() { return std::string("foo"); }
  bool is_true() { return true; }
  bool is_false() { return false; }
};

#endif // SAMPLE_H
