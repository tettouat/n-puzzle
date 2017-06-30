#include "CreateHeuristic.hpp"
#include "Manhattan.hpp"
#include "LinearConflict.hpp"
#include "MisplacedTiles.hpp"
#include "Nothing.hpp"

CreateHeuristic::CreateHeuristic() {}

CreateHeuristic::~CreateHeuristic() {}

CreateHeuristic CreateHeuristic::_instance;

CreateHeuristic &CreateHeuristic::getInstance() {
	return CreateHeuristic::_instance;
}

IHeuristic *CreateHeuristic::createHeuristic(std::string name, unsigned short **finalMap, size_t size)
{
	IHeuristic *ret = NULL;

	if (name == "manhattan" || name == "")
		ret = new Manhattan(finalMap, size);
	else if (name == "linearconflict")
		ret = new LinearConflict(finalMap, size);
	else if (name == "misplacedtiles")
		ret = new MisplacedTiles(finalMap, size);
	else if (name == "nothing")
		ret = new Nothing();
	return ret;
}
