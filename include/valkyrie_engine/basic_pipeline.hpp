#pragma once

#include "valkyrie_engine/basic_lockable.hpp"
#include "valkyrie_engine/basic_pipeline_stage.hpp"

namespace vlk
{
	class basic_pipeline :
		public basic_lockable
	{
		virtual void add_stage(std::string_view t_name, std::unique_ptr<basic_pipeline_stage> t_stage) = 0;
		virtual void remove_stage(std::string_view t_name) = 0;

		virtual void run() = 0;
	};

}
