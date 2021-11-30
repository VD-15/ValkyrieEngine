#pragma once

#include "valkyrie_engine/artefact_collection.hpp"

#include <unordered_set>

namespace vlk
{
	class basic_pipeline_stage
	{
		protected:
		const std::unordered_set<std::string_view> m_input_names;
		const std::unordered_set<std::string_view> m_output_names;

		public:
		virtual ~basic_pipeline_stage() = default;

		virtual artefact_collection run(const artefact_collection& t_inputs) = 0;

		inline const std::unordered_set<std::string_view> inputs() const { return m_input_names; }
		inline const std::unordered_set<std::string_view> outputs() const { return m_output_names; }
	};
}
