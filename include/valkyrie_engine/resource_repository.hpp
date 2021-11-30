#pragma once

#include "valkyrie_engine/basic_resource_repository.hpp"
#include "valkyrie_engine/basic_lockable.hpp"

#include <memory>
#include <typeindex>
#include <shared_mutex>
#include <unordered_map>

namespace vlk
{
	class resource_repository :
		public basic_resource_repository,
		public basic_lockable
	{
		std::unordered_map<std::type_index, std::unique_ptr<basic_resource>> m_data;
		public:

		resource_repository() = default;
		~resource_repository() = default;

		VLK_DELETE_MOVE_CONSTRUCTORS(resource_repository);
		VLK_DELETE_COPY_CONSTRUCTORS(resource_repository);

		inline void set(std::type_index t_type, std::unique_ptr<basic_resource> t_resource) final
		{
			m_data.insert_or_assign(t_type, std::move(t_resource));
		}

		inline void erase(std::type_index t_type) final
		{
			m_data.erase(t_type);
		}

		inline basic_resource* get(std::type_index t_type) final
		{
			auto search = m_data.find(t_type);

			if (search != m_data.end())
			{
				return search->second.get();
			}

			return nullptr;
		}

		inline const basic_resource* get(std::type_index t_type) const final
		{
			auto search = m_data.find(t_type);

			if (search != m_data.cend())
			{
				return search->second.get();
			}

			return nullptr;
		}
	};
}
