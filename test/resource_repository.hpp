#pragma once

#include "valkyrie_engine/valkyrie_engine.hpp"

class my_resource : public vlk::basic_resource
{
	public:

	my_resource()
	{
		++counter;
	}

	~my_resource()
	{
		--counter;
	}

	static int counter;
};

