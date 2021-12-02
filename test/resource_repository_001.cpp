#include "resource_repository.hpp"

#include "catch2/catch.hpp"

SCENARIO("multiple basic_resources can be added to resource_repository")
{
	GIVEN("a resource_repository containing a resource")
	{
		vlk::resource_repository repository;
		const auto& c_repository = repository;

		auto* r_ptr = new my_resource();
		repository.set(
			std::type_index(typeid(my_resource)),
			std::unique_ptr<my_resource>(r_ptr)
		);

		REQUIRE(repository.get(std::type_index(typeid(my_resource))) == r_ptr);
		REQUIRE(c_repository.get(std::type_index(typeid(my_resource))) == r_ptr);
		REQUIRE(my_resource::counter == 1);
		REQUIRE(my_other_resource::counter == 0);

		WHEN("another resource is set")
		{
			auto* o_ptr = new my_other_resource();
			repository.set(
				std::type_index(typeid(my_other_resource)),
				std::unique_ptr<my_other_resource>(o_ptr)
			);

			THEN("the repository stores both resources")
			{
				REQUIRE(my_resource::counter == 1);
				REQUIRE(my_other_resource::counter == 1);
				REQUIRE(repository.get(std::type_index(typeid(my_resource))) == r_ptr);
				REQUIRE(repository.get(std::type_index(typeid(my_other_resource))) == o_ptr);
				REQUIRE(c_repository.get(std::type_index(typeid(my_resource))) == r_ptr);
				REQUIRE(c_repository.get(std::type_index(typeid(my_other_resource))) == o_ptr);
			}
		}
	}
}

