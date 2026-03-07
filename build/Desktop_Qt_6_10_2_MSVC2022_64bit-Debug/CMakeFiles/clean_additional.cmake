# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Basic_Project_autogen"
  "CMakeFiles\\Basic_Project_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Basic_Project_autogen.dir\\ParseCache.txt"
  )
endif()
