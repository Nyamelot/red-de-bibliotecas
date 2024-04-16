project("red-de-bibliotecas")

set(EXECUTABLE_NAME "red-de-bibliotecas")

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cc")
list(REMOVE_ITEM SOURCES "main.cc")
message(STATUS "Found sources: ${SOURCES}")

add_executable(${EXECUTABLE_NAME})

target_sources(
    ${EXECUTABLE_NAME}
    PRIVATE
        "main.cc"
    PUBLIC
        ${SOURCES}
)

target_include_directories(
    ${EXECUTABLE_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)
