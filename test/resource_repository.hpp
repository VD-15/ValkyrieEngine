#pragma once

#include "valkyrie_engine/basic_resource.hpp"
#include "valkyrie_engine/valkyrie_engine.hpp"

class my_resource : public vlk::basic_resource
{
	public:
	my_resource() { ++counter; }
	~my_resource() { --counter; }

	static int counter;
};

class my_other_resource : public vlk::basic_resource
{
	public:
	
	my_other_resource() { ++counter; }
	~my_other_resource() { --counter; }

	static int counter;
};

