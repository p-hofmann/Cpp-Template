cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)

# Have all executables in the bin folder, so continuous integratian can easily call them
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
# Have all libraries in the libs folder, all submodules will compile their libraries into there
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs)

##########
# Main Project
##########

# Name the project and add a version number
project(DummyMain VERSION 0.0.1 LANGUAGES CXX)

# Find out if the current architecture is 32 or 64 bit and
# This will add the equal of '#define BUILD_ARCH_64BIT' to each file in case of a 64bit architecture
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_definitions(-DBUILD_ARCH_64BIT)
endif ()

# Gather src files that depending on a specific OS
if (UNIX)
    if (APPLE AND ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        set(PLATFORM_DEPENENT_FILES)
    else ()
        set(PLATFORM_DEPENENT_FILES)
    endif ()
elseif (WIN32)
    set(PLATFORM_DEPENENT_FILES)
else ()
    message(SEND_ERROR "Unknown OS")
endif ()

# Make a static library
# As the submodule is not a library of its own, the files will be added
add_library(DummyMain
    src/dummymainclass.cpp include/Cpp-Template/dummymainclass.h
    ${PLATFORM_DEPENENT_FILES}
    )

# This will specify for this project only, /src and /include as the folders to look into for files
target_include_directories(DummyMain
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Cpp-Template
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Cpp-Template-Sub1/include/Cpp-Template-Sub1
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Cpp-Template-Sub1/include/Cpp-Template-Sub1/Cpp-Template-Sub1-Sub/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Cpp-FileSystem-Emulator/include
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
# Add Unittest
enable_testing()
add_subdirectory(tests)

# Add Submodules
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/include/Cpp-Template-Sub1)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/include/Cpp-FileSystem-Emulator)

# Add dependency to submodule libraries
add_dependencies(DummyMain Cpp_FileSystem_Emulator)
add_dependencies(DummyMain CppTemplateSub1)
target_link_libraries(DummyMain Cpp_FileSystem_Emulator)
target_link_libraries(DummyMain CppTemplateSub1)
