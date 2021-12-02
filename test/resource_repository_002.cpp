#include "resource_repository.hpp"

#include "catch2/catch.hpp"

SCENARIO("basic_resources in a resource_repository can be replaced")
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

		WHEN("the resource is replaced")
		{
			auto* n_ptr = new my_resource();

			REQUIRE(my_resource::counter == 2);

			repository.set(
				std::type_index(typeid(my_resource)),
				std::unique_ptr<my_resource>(n_ptr)
			);

			THEN("the repository stores the newest resource")
			{
				REQUIRE(my_resource::counter == 1);
				REQUIRE(repository.get(std::type_index(typeid(my_resource))) == n_ptr);
				REQUIRE(c_repository.get(std::type_index(typeid(my_resource))) == n_ptr);
			}
		}
	}
}
