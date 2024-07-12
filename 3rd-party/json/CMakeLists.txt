if (NOT TARGET lf_3rd_json)
  add_library(lf_3rd_json INTERFACE)
  target_include_directories(lf_3rd_json SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/json)
endif()