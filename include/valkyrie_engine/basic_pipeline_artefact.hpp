#pragma once

namespace vlk
{
	class basic_pipeline_artefact
	{
		public:
		virtual ~basic_pipeline_artefact() = default;

		virtual bool has_payload() const = 0;
	};
}

