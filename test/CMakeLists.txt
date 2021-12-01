add_executable(valkyrie_engine_tests
	${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
)

target_link_libraries(valkyrie_engine_tests
	PUBLIC
		valkyrie_engine
		Catch2::Catch2
)

enable_testing()
include(CTest)
catch_discover_tests(valkyrie_engine_tests)
