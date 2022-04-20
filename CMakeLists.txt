cmake_minimum_required(VERSION 3.14)
project(cpp-protocol-stack CXX)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

#include(FetchContent)
# FetchContent_Declare(
#  googletest
#  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
#)
# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)

#enable_testing()

#add_library()
add_library(ip STATIC ip.hpp ip.cpp)
add_library(inet STATIC inet.hpp inet.cpp)


add_executable(
  packetCapture.out
  app/packetCapture.cpp
  )

Target_link_libraries(
  packetCapture.out
  ip
  inet
 )

#include(GoogleTest)
#gtest_discover_tests(hello_test)
