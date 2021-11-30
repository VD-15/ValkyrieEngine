cmake_minimum_required(VERSION 3.10)

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

set_target_properties(
	valkyrie_engine PROPERTIES
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
		Threads::Threads)

if (${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
	if (BUILD_TESTING)
		message(STATUS "Building tests for ValkyrieEngine")
		add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
		enable_testing()
	endif()
endif()
