cmake_minimum_required(VERSION 3.11)

project(HIRMutate CXX)

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
    set(CMAKE_CXX_FLAGS "-O3")
    set(CMAKE_C_FLAGS "-O3")
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

set(HIRMUTATE_PATH src)

pkg_check_modules(LB_LIBS REQUIRED)

set(SOURCE  src/utils/random.cpp
            src/utils/DomValue.cpp
            src/utils/serializestream.cpp
            src/utils/unserializestream.cpp
            src/docs/docs.cpp
            src/document/Context.cpp
            src/document/document_css.cpp
            src/document/dom_tree.cpp
            src/document/document_html.cpp
            src/value/Value.cpp
            src/value/common_val.cpp
            src/value/html_val.cpp
            src/value/svg_val.cpp
            src/value/css_val.cpp
            src/docs/html_symbols.cpp
            src/docs/svg_symbols.cpp
            src/docs/css_symbols.cpp
            src/docs/hierarchy.cpp
            src/config.cpp
            src/attribute/attribute.cpp
            src/attribute/html_attr.cpp
            src/attribute/svg_attr.cpp
            src/css/css_declaration.cpp
            src/css/css_properties.cpp
            src/css/css_selector.cpp
            src/css/css_rule.cpp
            src/css/css_var.cpp
            src/object/object.cpp
            src/object/html_obj.cpp
            src/object/svg_obj.cpp
            src/object/function.cpp
            src/object/factory.cpp
            src/js/api.cpp
            src/js/arg/arg.cpp
            src/js/arg/html_arg.cpp
            src/js/arg/svg_arg.cpp
            src/js/ret/ret.cpp
            src/js/property/js_property.cpp
            src/js/property/svg_property.cpp
            src/js/property/html_property.cpp
            src/js/function/js_function.cpp
            src/js/function/html_function.cpp
            src/js/function/svg_function.cpp
            src/serialize_variables.cpp
            src/init.cpp
    )

set(HEADERS src/include/utils/random.h
)

add_executable(HIRGenerator ${SOURCE} src/main.cpp ${HEADERS})
add_library(${PROJECT_NAME} ${SOURCE} ${HEADERS})

include_directories(${HIRMUTATE_PATH}/include ${HIRMUTATE_PATH}/include/utils
                    ${HIRMUTATE_PATH}/include/docs ${HIRMUTATE_PATH}/include/document
                    ${HIRMUTATE_PATH}/include/object ${HIRMUTATE_PATH}/include/attribute 
                    ${HIRMUTATE_PATH}/include/value ${HIRMUTATE_PATH}/include/css
                    ${HIRMUTATE_PATH}/include/js ${HIRMUTATE_PATH}/include/js/property
                    ${HIRMUTATE_PATH}/include/js/arg ${HIRMUTATE_PATH}/include/js/ret
                    ${HIRMUTATE_PATH}/include/js/function
                    ${GUMBO_PATH}/include ${LB_LIBS_INCLUDE_DIRS})
target_link_options(${PROJECT_NAME} PRIVATE ${LB_LIBS_LDFLAGS})
target_link_libraries(${PROJECT_NAME} ${LB_LIBS_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 11
        C_STANDARD 99
        )
