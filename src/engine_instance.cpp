#include "valkyrie_engine/engine_instance.hpp"
#include "valkyrie_engine/resource_repository.hpp"
#include "valkyrie_engine/pipeline.hpp"

#include <memory>

using namespace vlk;

engine_instance::engine_instance(std::unique_ptr<engine_args> t_args)
{
	m_resource_repository = (t_args->m_resource_repository)?
		std::move(t_args->m_resource_repository):
		std::make_unique<resource_repository>();

	m_pipeline = (t_args->m_pipeline)?
		std::move(t_args->m_pipeline) :
		std::make_unique<pipeline>();
}

engine_instance::~engine_instance()
{ }

void engine_instance::start_update_loop()
{ }

void engine_instance::stop_update_loop()
{ }
