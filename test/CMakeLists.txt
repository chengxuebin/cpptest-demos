project(unit_tests CXX)

FILE(GLOB MySources *.cpp)
add_executable(
  ${PROJECT_NAME}

  example.cpp
  my_math.cpp

  cmock.cpp

  # gmock_global.cpp
  # fff.cpp
  cpp_stub.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -fno-access-control -fno-inline -Wno-pmf-conversions -Wl,--allow-multiple-definition -no-pie -fno-stack-protector -fprofile-arcs -ftest-coverage)

target_link_libraries(
  ${PROJECT_NAME}
  gtest_main
  gmock_main
  example
)

target_include_directories(
  ${PROJECT_NAME} PUBLIC
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_SOURCE_DIR}/third_party/c_mock/include
)

add_test(
  NAME
  unit
  COMMAND
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/${PROJECT_NAME}
)
