#pragma once

#include "valkyrie_engine/util.hpp"
#include "valkyrie_engine/basic_pipeline_artefact.hpp"

#include <memory>
#include <string_view>
#include <unordered_map>

namespace vlk
{
	class artefact_collection final
	{
		std::unordered_map<std::string_view, std::unique_ptr<basic_pipeline_artefact>> m_data;

		public:
		artefact_collection() = default;
		~artefact_collection() = default;

		VLK_DELETE_COPY_CONSTRUCTORS(artefact_collection);
		VLK_DEFAULT_MOVE_CONSTRUCTORS(artefact_collection);

		void add(std::string_view t_name, std::unique_ptr<basic_pipeline_artefact> t_artefact);
		const basic_pipeline_artefact* get(std::string_view t_name) const;
	};
}

