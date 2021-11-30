#pragma once

#include "valkyrie_engine/util.hpp"

#include <memory>
#include <mutex>
#include <shared_mutex>

namespace vlk
{
	class basic_lockable
	{
		mutable std::shared_mutex m_mtx;

		public:

		basic_lockable() = default;
		~basic_lockable() = default;

		VLK_DELETE_COPY_CONSTRUCTORS(basic_lockable);
		VLK_DELETE_MOVE_CONSTRUCTORS(basic_lockable);

		inline std::unique_lock<std::shared_mutex> lock_write()
		{
			return std::unique_lock<std::shared_mutex>(m_mtx);
		}

		inline std::shared_lock<std::shared_mutex> lock_read() const
		{
			return std::shared_lock<std::shared_mutex>(m_mtx);
		}

		inline std::shared_mutex& mutex() const
		{
			return m_mtx;
		}
	};
}
