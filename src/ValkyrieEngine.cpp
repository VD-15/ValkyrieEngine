#include "valkyrie_engine/uuid.hpp"
#include "valkyrie_engine/valkyrie_engine.hpp"

#include <iostream>

using namespace vlk;

int main(int argc, const char** args)
{
	engine_instance engine;

	uuid id = { 0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00 };

	std::cout << static_cast<std::string>(id) << std::endl;
}
