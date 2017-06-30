#include <ctime>
#include <cstdlib>
#include "Solver.hpp"
#include "Parser.hpp"
#include "CreateHeuristic.hpp"
#include "Nothing.hpp"

enum npuzzle_error_t {
	ERR_TOOMANYARGS,
	ERR_BADOPTS,
	ERR_BADHEURISTIC,
	ERR_NOTSOLVABLE,
	ERR_BADMAP
};

void displayError(npuzzle_error_t error, unsigned short **map)
{
	if (error == ERR_TOOMANYARGS)
		std::cout << "Too many args" << std::endl;
	else if (error == ERR_BADOPTS)
		std::cout << "Usage: ./npuzzle [file] -s <size> -h <heuristic>" << std::endl;
	else if (error == ERR_BADHEURISTIC)
		std::cout << "Heuristics: nothing" ", manhattan" ", misplacedtiles"
				  ", linearconflict" << std::endl;
	else if (error == ERR_NOTSOLVABLE)
		std::cout << "This puzzle is not solvable" << std::endl;
	else if (error == ERR_BADMAP)
		std::cout << "Bad map" << std::endl;
	if (map != NULL)
	{
		delete [] map[0];
		delete [] map;
	}
	std::exit(EXIT_FAILURE);
}

void	displayMap(unsigned short **map, size_t size) {
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			if (map[y][x] == 0)
				std::cout << "\033[38;5;124m" << (int)map[y][x] << "\033\1330m ";
			else
				std::cout << "\033[38;5;34m" << (int)map[y][x] << "\033\1330m ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	retracePath(std::list<const Node*> &path, size_t size, std::string name, size_t beginid, size_t endid) {
	Solver			*a;
	CreateHeuristic&	heurfactory = CreateHeuristic::getInstance();
	auto				begin = path.begin();
	auto				end = path.end();

	for (size_t i = 0; i < beginid; i++) {
		begin++;
	}
	for (size_t i = 0; i < endid; i++) {
		end--;
	}
	a = new Solver((*begin)->map, (*end)->map, size,
						  *heurfactory.createHeuristic(name, (*end)->map, size));
	while (a->solve()) ;
	auto	newList = a->buildPath();
	begin = path.erase(begin, end)--;
	path.insert(begin, newList.begin(), --newList.end());
}

void	runSolver(unsigned short **map, std::string heuristicName, int size) {
	Solver				*a;
	IHeuristic				*ha;
	unsigned short					**finalMap;
	std::list<const Node*>	path;
	size_t					totalStates;
	size_t					maxStates;

	finalMap = Solver::finalSolution(size);
	ha = CreateHeuristic::getInstance().createHeuristic(heuristicName, finalMap, size);
	if (ha == NULL)
		displayError(ERR_BADHEURISTIC, map);
	a = new Solver(map, finalMap, size, *ha);
	if (!Solver::isSolvable(map, size))
		displayError(ERR_NOTSOLVABLE, map);
	else {
		while (a->solve()) ;
		path = a->buildPath();
		totalStates = a->getTotalStates();
		maxStates = a->getMaxStates();
	} 
	for (auto atom : path)
		atom->dump();
	std::cout << "Number of move : " << path.size() - 1 << std::endl;
	std::cout << "Complexity in time : " << totalStates << std::endl;
	std::cout << "Complexity in size : " << maxStates << std::endl;
}

int main(int ac, char **av)
{
	int size = 0;
	unsigned short **map = NULL;
	std::string heuristic;
	Parser b;

	if (ac > 7)
		displayError(ERR_TOOMANYARGS, map);
	map = b.get_map(av[1]);
	if (map != NULL)
	{
		if (!b.get_options(ac, av))
			displayError(ERR_BADOPTS, map);
		if (b.getOptionSize() > 2 && b.getOptionSize() <= 17)
			size = b.getOptionSize();
		else
			displayError(ERR_BADOPTS, map);
		if (map[0][0] == 'O')
			map = Solver::genMap(size, 0);
		else
			size = b.getSize();
		displayMap(map, size);
		std::cout << "----->" << std::endl;
		runSolver(map, b.getHeuristic(), size);
	}
	else
		displayError(ERR_BADMAP, map);

	return (0);
}
