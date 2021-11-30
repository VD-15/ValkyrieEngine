#pragma once

#include "valkyrie_engine/basic_resource.hpp"

#include <memory>
#include <typeindex>

namespace vlk
{
	class basic_resource_repository
	{
		public:
		virtual ~basic_resource_repository() = default;

		virtual void set(std::type_index t_type, std::unique_ptr<basic_resource> t_resource) = 0;
		virtual void erase(std::type_index t_type) = 0;

		virtual basic_resource* get(std::type_index t_type) = 0;
		virtual const basic_resource* get(std::type_index t_type) const = 0;
	};
}
