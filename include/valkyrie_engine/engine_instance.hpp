#pragma once

#include "valkyrie_engine/basic_resource_repository.hpp"
#include "valkyrie_engine/basic_pipeline.hpp"
#include "valkyrie_engine/util.hpp"

#include <memory>

namespace vlk
{
	struct engine_args
	{
		std::unique_ptr<basic_resource_repository> m_resource_repository;
		std::unique_ptr<basic_pipeline> m_pipeline;
	};

	class engine_instance final
	{
		std::unique_ptr<basic_resource_repository> m_resource_repository;
		std::unique_ptr<basic_pipeline> m_pipeline;

		public:
		engine_instance(std::unique_ptr<engine_args> t_args = std::make_unique<engine_args>());
		~engine_instance();

		VLK_DELETE_COPY_CONSTRUCTORS(engine_instance);
		VLK_DELETE_MOVE_CONSTRUCTORS(engine_instance);

		template <typename T>
		inline void set_resource(std::unique_ptr<basic_resource> t_resource)
		{
			m_resource_repository->set(std::type_index(typeid(T)), std::move(t_resource));
		}

		template <typename T>
		inline void erase_resource()
		{
			m_resource_repository->erase(std::type_index(typeid(T)));
		}

		template <typename T>
		inline T* get_resource()
		{
			return dynamic_cast<T*>(m_resource_repository->get(std::type_index(typeid(T))));
		}

		template <typename T>
		inline const T* get_resource() const
		{
			return dynamic_cast<const T*>(m_resource_repository->get(std::type_index(typeid(T))));
		}

		void start_update_loop();
		void stop_update_loop();
	};
}
