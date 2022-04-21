### test を実行する場合は CLI で ctest を実行する

cmake_minimum_required(VERSION 3.14)
project(cpp-protocol-stack C CXX)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)

include(FetchContent)
 FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

enable_testing()

#add_library(hoge(生成する実行可能ファイルの名前) STATIC|SHARED(静的か共有か) hoge.hpp hoge.cpp)
add_library(ip STATIC ip.hpp ip.cpp)
add_library(inet STATIC inet.hpp inet.cpp)
add_library(socket STATIC socket.hpp socket.cpp)
add_library(ethernet STATIC ethernet.hpp ethernet.cpp)

### app/packetCaptute

add_executable(
  packetCapture
  app/packetCapture.cpp
  )

Target_link_libraries(packetCapture socket inet ip ethernet)

### test/sample

add_executable(
  sampleTest
  test/sample.hpp
  test/sample.cpp
  )

Target_link_libraries(sampleTest gtest gtest_main pthread)

include(GoogleTest)
gtest_discover_tests(sampleTest)
