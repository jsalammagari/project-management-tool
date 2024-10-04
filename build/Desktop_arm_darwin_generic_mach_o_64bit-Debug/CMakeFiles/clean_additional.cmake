# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/PMT_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/PMT_autogen.dir/ParseCache.txt"
  "PMT_autogen"
  )
endif()
