add_executable(helloworld.wasm ${CMAKE_CURRENT_SOURCE_DIR}/src/helloworld.cpp)
target_include_directories(helloworld.wasm
   PUBLIC 
   ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(helloworld.wasm
   PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

add_custom_target(helloworld.abi ALL)

set(ABI_FILE "${CMAKE_CURRENT_BINARY_DIR}/helloworld.abi")

add_custom_command(
    TARGET helloworld.abi
    COMMAND eosiocpp -g  ${ABI_FILE}   "${CMAKE_CURRENT_SOURCE_DIR}/include/helloworld.hpp"
)

add_custom_command(TARGET helloworld.abi POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${ABI_FILE} "${CMAKE_CURRENT_SOURCE_DIR}/abi/helloworld.abi"
)
