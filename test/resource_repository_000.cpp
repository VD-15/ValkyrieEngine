#include "resource_repository.hpp"

#include "catch2/catch.hpp"
#include <memory>

int my_resource::counter = 0;

SCENARIO("basic_resources can be added to resource_repository")
{
	GIVEN("an empty resource_repository")
	{
		vlk::resource_repository repository;
		const auto& c_repository = repository;

		REQUIRE(repository.get(std::type_index(typeid(my_resource))) == nullptr);
		REQUIRE(c_repository.get(std::type_index(typeid(my_resource))) == nullptr);
		REQUIRE(my_resource::counter == 0);

		WHEN("a resource is set")
		{
			auto* r_ptr= new my_resource();
			repository.set(std::type_index(typeid(my_resource)), std::unique_ptr<my_resource>(r_ptr));

			THEN("the repository stores that resource")
			{
				REQUIRE(my_resource::counter == 1);
				REQUIRE(repository.get(std::type_index(typeid(my_resource))) != nullptr);
				REQUIRE(repository.get(std::type_index(typeid(my_resource))) == r_ptr);
			}

			THEN("the repository stores that resource")
			{
				REQUIRE(my_resource::counter == 1);
				REQUIRE(c_repository.get(std::type_index(typeid(my_resource))) != nullptr);
				REQUIRE(c_repository.get(std::type_index(typeid(my_resource))) == r_ptr);
			}
		}
	}
}
