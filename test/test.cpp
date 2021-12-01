#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "valkyrie_engine/valkyrie_engine.hpp"

using namespace vlk;

TEST_CASE("Engine instance can be default-constructed")
{
	REQUIRE_NOTHROW(new engine_instance());
}
