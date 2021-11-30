#pragma once

#include "valkyrie_engine/basic_pipeline.hpp"
#include <string_view>

namespace vlk
{
	class pipeline :
		public basic_pipeline
	{
		std::unordered_map<std::string_view, std::unique_ptr<basic_pipeline_stage>> m_stages;

		public:

		void add_stage(std::string_view t_name, std::unique_ptr<basic_pipeline_stage> t_stage) override;
		void remove_stage(std::string_view t_name) override;
		void run() override;
	};
}
