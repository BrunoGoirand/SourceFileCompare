cmake_minimum_required(VERSION 3.0.0)

project(SourceFileCompare_Project VERSION 1.0.0)

find_package(NeatString)

if(NeatString_FOUND)
   message("NeatString library found")
   add_executable(sfc sfc.c)
   target_link_libraries(sfc NeatString)
else()
   message(FATAL_ERROR "NeatString library not found")
endif()
