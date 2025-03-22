cmake_minimum_required(VERSION 3.30)

project(TinyApplication VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set default build type to Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Add minimum compiler version check
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 16)
        message(FATAL_ERROR "Clang version must be at least 16!")
    endif()
endif()

# Add more build type validation
set(ALLOWED_BUILD_TYPES Debug Release RelWithDebInfo MinSizeRel)
if(NOT CMAKE_BUILD_TYPE IN_LIST ALLOWED_BUILD_TYPES)
    message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
endif()

# Useful for IDE integration and static analysis tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

# Add version checks for system requirements
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++23" COMPILER_SUPPORTS_CXX23)
if(NOT COMPILER_SUPPORTS_CXX23)
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++23 support.")
endif()

# Define source and include directories
set(SRC_DIR "src")
set(INCLUDE_DIR "include")
set(BIN_DIR "build")

# 
# build spdlog
set(CPM_DOWNLOAD_VERSION 0.27.2)
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

# Find required packages
CPMAddPackage(
    NAME spdlog
    GITHUB_REPOSITORY gabime/spdlog
    VERSION 1.15.0)

find_package(spdlog 1.15.0 REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(Catch2 3 REQUIRED)

# MacOS universal binary setup
if(APPLE)
    execute_process(
            COMMAND uname -m
            OUTPUT_VARIABLE HOST_ARCHITECTURE
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    if(HOST_ARCHITECTURE STREQUAL "arm64")
        set(CMAKE_OSX_ARCHITECTURES "arm64")
    else()
        set(CMAKE_OSX_ARCHITECTURES "x86_64")
    endif()
    list(APPEND DEPENDENT_LIBRARIES
            "-framework CoreFoundation"
            "-framework Security"
    )
    message(STATUS "osx arch: ${CMAKE_OSX_ARCHITECTURES}")
elseif(UNIX AND NOT APPLE)
    set(PLATFORM_SPECIFIC_LIBS
        # Ubuntu-specific libraries if needed
    )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
    message(STATUS "linux")
endif()

set(DEPENDENT_LIBRARIES
    spdlog::spdlog
    Catch2::Catch2WithMain
    pthread
    nlohmann_json::nlohmann_json
)

# add the executables
add_executable(tiny-app 
    ${SRC_DIR}/main.cpp
)

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

# turn off optimization to speed compile times
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(OPTIM_COMPILE_FLAGS "-O0")
else()
    set(OPTIM_COMPILE_FLAGS "-O0")
endif()

# Configure all targets
# Create a function for setting up common target properties
function(setup_target_properties target)
    target_include_directories(${target} PRIVATE
            ${CMAKE_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/include/vendor
    )
    target_link_libraries(${target} PRIVATE ${DEPENDENT_LIBRARIES})

    target_compile_options(${target} PRIVATE ${OPTIM_COMPILE_FLAGS} -Wall -Wpedantic -Wextra -Werror)
#
# for larger builds...
#
    # set_target_properties(${target} PROPERTIES UNITY_BUILD ON)
    # Add precompiled header support
    # target_precompile_headers(${target} PRIVATE ${CMAKE_SOURCE_DIR}/include/precompiled.hpp)
endfunction()

# Use the function for each target
foreach(target tiny-app)
    setup_target_properties(${target})
endforeach()

