cmake_minimum_required(VERSION 3.11)

project(dfl-fuzz LANGUAGES C CXX)

find_package(PkgConfig REQUIRED)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

#set(CMAKE_CXX_FLAGS "-g -fsanitize=address -fno-omit-frame-pointer")
#set(CMAKE_C_FLAGS "-g -fsanitize=address -fno-omit-frame-pointer")
#SET (CMAKE_C_COMPILER clang)
#SET (CMAKE_CXX_COMPILER clang++)

if (CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_CXX_FLAGS "-O3 -lpthread")
    set(CMAKE_C_FLAGS "-O3 -lpthread")
elseif (CMAKE_BUILD_TYPE MATCHES "ONLYDebug")
    set(CMAKE_CXX_FLAGS "-O0 -DDEBUG -g")
    set(CMAKE_C_FLAGS "-O0 -DDEBUG -g")
elseif (CMAKE_BUILD_TYPE MATCHES "DebugMEM")
    set(CMAKE_CXX_FLAGS "-O0 -DDEBUG -DDEBUG_MEM -g -fsanitize=address -fno-omit-frame-pointer")
    set(CMAKE_C_FLAGS "-O0 -DDEBUG -DDEBUG_MEM -g -fsanitize=address -fno-omit-frame-pointer")
elseif (CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS "-O0 -DDEBUG -g -fsanitize=address -fno-omit-frame-pointer")
    set(CMAKE_C_FLAGS "-O0 -DDEBUG -g -fsanitize=address -fno-omit-frame-pointer")
endif()

add_subdirectory(src/HIRMutate)

set(DFL_FUZZ_PATH src)

pkg_check_modules(LB_LIBS REQUIRED)

set(SOURCE  src/dfl-fuzz.c
            src/generator.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCE})
add_executable(run_helper src/run_fuzz_helper.c)
add_executable(dumb_fuzz src/generator.cpp src/dumb_fuzz.c)
target_link_options(dumb_fuzz PRIVATE ${LB_LIBS_LDFLAGS})
target_link_libraries(dumb_fuzz PUBLIC HIRMutate)

set(HIRMUTATE_PATH ${DFL_FUZZ_PATH}/HIRMutate/src)

include_directories(${DFL_FUZZ_PATH}/include ${HIRMUTATE_PATH}/include 
                    ${HIRMUTATE_PATH}/include/utils ${HIRMUTATE_PATH}/include/docs 
                    ${HIRMUTATE_PATH}/include/document ${HIRMUTATE_PATH}/include/object 
                    ${HIRMUTATE_PATH}/include/attribute ${HIRMUTATE_PATH}/include/value 
                    ${HIRMUTATE_PATH}/include/css ${HIRMUTATE_PATH}/include/js 
                    ${HIRMUTATE_PATH}/include/js/property ${HIRMUTATE_PATH}/include/js/arg 
                    ${HIRMUTATE_PATH}/include/js/ret ${HIRMUTATE_PATH}/include/js/function
                    ${LB_LIBS_INCLUDE_DIRS})
target_link_options(${PROJECT_NAME} PRIVATE ${LB_LIBS_LDFLAGS})
target_link_libraries(${PROJECT_NAME} PUBLIC HIRMutate)

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 11
        C_STANDARD 99
        )
