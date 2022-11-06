cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(gtest-demo CXX)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# we use this to get code coverage
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -DGTEST_USE_OWN_TR1_TUPLE=1")

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")

# if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
# endif()

# Compiler config
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED ON)
endif()

add_subdirectory(src)

include(FetchContent)

# 安装 googletest 依赖
set(GOOGLETEST_TARGET_NAME "googletest")
FetchContent_Declare(
  ${GOOGLETEST_TARGET_NAME}
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.10.0
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/${GOOGLETEST_TARGET_NAME}
)
FetchContent_GetProperties(${GOOGLETEST_TARGET_NAME})

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# 激活 gmock
# 它会使 googletest 首先执行 add_subdirectory(googlemock)
# 然后 googlemock 又会 add_subdirectory(googletest)
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)

if(NOT ${GOOGLETEST_TARGET_NAME}_POPULATED)
  FetchContent_Populate(${GOOGLETEST_TARGET_NAME})
  add_subdirectory(${${GOOGLETEST_TARGET_NAME}_SOURCE_DIR} ${${GOOGLETEST_TARGET_NAME}_BINARY_DIR})
endif()

# 安装 FFF 依赖
set(FFF_TARGET_NAME "fff")
FetchContent_Declare(
  ${FFF_TARGET_NAME}
  GIT_REPOSITORY https://github.com/meekrosoft/fff
  GIT_TAG v1.1
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/${FFF_TARGET_NAME}
)
FetchContent_GetProperties(${FFF_TARGET_NAME})

if(NOT ${FFF_TARGET_NAME}_POPULATED)
  FetchContent_Populate(${FFF_TARGET_NAME})
endif()

# 安装 gmock_global 依赖
set(GMOCK_GLOBAL_TARGET_NAME "gmock_global")
FetchContent_Declare(
  ${GMOCK_GLOBAL_TARGET_NAME}
  GIT_REPOSITORY https://github.com/apriorit/gmock-global
  GIT_TAG 1.0.2
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/${GMOCK_GLOBAL_TARGET_NAME}
)
FetchContent_GetProperties(${GMOCK_GLOBAL_TARGET_NAME})

if(NOT ${GMOCK_GLOBAL_TARGET_NAME}_POPULATED)
  FetchContent_Populate(${GMOCK_GLOBAL_TARGET_NAME})
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/${GMOCK_GLOBAL_TARGET_NAME}/include)
endif()

# 安装 c_mock 依赖
set(C_MOCK_TARGET_NAME "c_mock")
FetchContent_Declare(
  ${C_MOCK_TARGET_NAME}
  GIT_REPOSITORY https://github.com/hjagodzinski/C-Mock
  GIT_TAG v0.3.1
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/${C_MOCK_TARGET_NAME}
)
FetchContent_GetProperties(${C_MOCK_TARGET_NAME})

if(NOT ${C_MOCK_TARGET_NAME}_POPULATED)
  FetchContent_Populate(${C_MOCK_TARGET_NAME})
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/${C_MOCK_TARGET_NAME}/include)
endif()

# 安装 cpp_stub 依赖
set(CPP_STUB_TARGET_NAME "cpp_stub")
FetchContent_Declare(
  ${CPP_STUB_TARGET_NAME}
  GIT_REPOSITORY https://github.com/coolxv/cpp-stub
  GIT_TAG bef3fb4c8c329d87d2f5880219653bf8ecaf2548
  GIT_SUBMODULES ""
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/${CPP_STUB_TARGET_NAME}
)
FetchContent_GetProperties(${CPP_STUB_TARGET_NAME})

if(NOT ${CPP_STUB_TARGET_NAME}_POPULATED)
  FetchContent_Populate(${CPP_STUB_TARGET_NAME})
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/${CPP_STUB_TARGET_NAME}/src)
endif()

add_subdirectory(test)
