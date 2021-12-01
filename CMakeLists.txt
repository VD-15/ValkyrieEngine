cmake_minimum_required(VERSION 3.13)

project(valkyrie_engine VERSION 0.1.0)

add_library(valkyrie_engine
	${CMAKE_CURRENT_SOURCE_DIR}/src/valkyrie_engine.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/engine_instance.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/pipeline.cpp
)
add_library(valkyrie_engine::valkyrie_engine ALIAS valkyrie_engine)

target_include_directories(valkyrie_engine
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(valkyrie_engine
	PROPERTIES
		SOVERSION ${valkyrie_engine_VERSION_MAJOR}
		VERSION ${valkyrie_engine_VERSION}
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED TRUE
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps)

target_link_libraries(valkyrie_engine
	PUBLIC
		Threads::Threads
)

option(CODE_COVERAGE "Enable coverage reporting" OFF)
if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	message(STATUS "Generating code coverage for Valkyrie Engine")
	# Add required coverage flags (GCC & LLVM/Clang only)
	target_compile_options(valkyrie_engine PUBLIC --coverage)
	target_link_options(valkyrie_engine PUBLIC --coverage)
endif(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

if (BUILD_TESTING AND ${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
	message(STATUS "Building tests for ValkyrieEngine")
	enable_testing()
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
endif()
