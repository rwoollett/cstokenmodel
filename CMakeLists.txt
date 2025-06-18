cmake_minimum_required(VERSION 3.16)
project(
  CSTokenModelProject VERSION 1.0
  DESCRIPTION "CSToken model structures."
  LANGUAGES CXX C
)

# set everything up for c++ 20 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(PkgConfig REQUIRED)
# pkg_check_modules(LIBPQ REQUIRED libpq)
# if(LIBPQ_FOUND)
#   message("-- libpq found via pkg-config")
#   message("-- Include dirs: ${LIBPQ_INCLUDE_DIRS}")
#   message("-- Libraries: ${LIBPQ_LIBRARIES}")
#   message("-- CFLAGS: ${LIBPQ_CFLAGS_OTHER}")
#   add_compile_definitions(LIBPQ_FOUND)
# else()
#   message(FATAL_ERROR "libpq not found via pkg-config")
# endif()

add_subdirectory(model)

target_include_directories(
  CSTokenModel PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

