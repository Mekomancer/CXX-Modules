cmake_minimum_required(VERSION 4.2) # nice

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_COMPILER_IMPORT_STD 26)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY target)
set(CMAKE_CXX_MODULE_STD ON)

project(cxx_module_exec
  VERSION 0.1.0 # SemVer
  DESCRIPTION "An example excutable"
  LANGUAGES CXX
)


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
     "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

add_executable(cxx_module_exec
  src/main.cpp
)

target_sources(cxx_module_exec
  PRIVATE
  FILE_SET CXX_MODULES
  BASE_DIRS src
  FILES
  src/types.ixx
)

add_custom_target(format 
  COMMAND clang-format -i 
  `find src -name '*.cxx' | -name '*.cpp' | -name '*.ixx'`
  COMMAND_EXPAND_LISTS
  VERBATIM
)

target_compile_definitions(${PROJECT_NAME} 
  PRIVATE 
  VERSION=\"${PROJECT_VERSION}\"
  NAME=\"${PROJECT_NAME}\"
)


target_link_libraries(${PROJECT_NAME})
install(TARGETS ${PROJECT_NAME})
