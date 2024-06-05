cmake_minimum_required(VERSION 3.8)

project(LogicFactory VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS ON)

set(HOME ${CMAKE_CURRENT_SOURCE_DIR})

option(LF_BUILD_TEST "build with test" ON)
option(LF_BUILD_APP "build with application" ON)

set(CMAKE_CXX_FLAGS "-Wall -Wno-unknown-pragmas")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -DNDEBUG")

if(CMAKE_BUILD_TYPE AND(CMAKE_BUILD_TYPE STREQUAL "Debug"))
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg -O0 -g")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
    message("Debug mode CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -march=native -DNDEBUG")
    message("Release mode CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
endif()

# add the third party
add_subdirectory(3rd-party)

# add the toolkit projects
add_subdirectory(toolkit)

# add src folder
add_subdirectory(src)

# add test folder
if(LF_BUILD_TEST)
    add_subdirectory(test)
endif()

# add application folder
if(LF_BUILD_APP)
    add_subdirectory(app)
endif()