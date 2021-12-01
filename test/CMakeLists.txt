add_executable(valkyrie_engine_tests
	${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
)

target_link_libraries(valkyrie_engine_tests
	PUBLIC
		valkyrie_engine
		Catch2::Catch2
)

set_target_properties(
	valkyrie_engine_tests PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED TRUE
)

include(CTest)
catch_discover_tests(valkyrie_engine_tests)
