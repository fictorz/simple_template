project(example_module)

# Compiler setup (Do not change)
cmake_minimum_required(VERSION 3.16)

set(PROJ_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_C_STANDARD                11)
set(CMAKE_C_STANDARD_REQUIRED       ON)
set(CMAKE_C_EXTENSIONS              ON)
set(CMAKE_CXX_STANDARD              17)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            ON)
message("Build type: "              ${CMAKE_BUILD_TYPE})

enable_language(C CXX ASM)


set(EXAMPLE_MODULE_INCLUDE_DIRS
    # TODO: Include directory in which the .h files will be
    ${PROJ_PATH} # Includes root folder (i.e. /src)
)

set(EXAMPLE_MODULE_SOURCE_FILES
    # TODO: Include .cc or .c source file for compilation
    ${PROJ_PATH}/example_class.cc
)

# Export library
add_library(${PROJECT_NAME} STATIC ${EXAMPLE_MODULE_SOURCE_FILES}) # TODO: add internal dependencies if necessary
target_include_directories(${PROJECT_NAME} PUBLIC ${EXAMPLE_MODULE_INCLUDE_DIRS})

target_link_options(${PROJECT_NAME} PRIVATE
    -T${linker_script_SRC}
    ${CPU_PARAMETERS}
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map
    --specs=nosys.specs
    -u _printf_float
    -Wl,--start-group
    -lc
    -lm
    -lstdc++
    -lsupc++
    -Wl,--end-group
    -Wl,--print-memory-usage
)