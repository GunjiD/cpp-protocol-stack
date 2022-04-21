#include <exception>
#include <gtest/gtest.h>

#include "sample.hpp"

TEST(sample, add) {
  sample s;
  ASSERT_EQ(3, s.add(1, 2));
  ASSERT_EQ(4, s.add(2, 2));
}

TEST(sample, get_str_foo) {
  sample s;
  ASSERT_EQ("foo", s.get_str_foo());
}

TEST(sample, is) {
  sample s;
  ASSERT_TRUE(s.is_true());
}

TEST(sample, exception) {
  sample s;
  ASSERT_THROW(s.throw_exception(), std::exception);
  ASSERT_NO_THROW(s.no_throw_exception());
}
