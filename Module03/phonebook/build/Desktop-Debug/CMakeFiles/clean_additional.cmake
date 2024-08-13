# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/phonebook_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/phonebook_autogen.dir/ParseCache.txt"
  "phonebook_autogen"
  )
endif()
