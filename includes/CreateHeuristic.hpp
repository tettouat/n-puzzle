#ifndef CREATEHEURISTIC_HPP
# define CREATEHEURISTIC_HPP

# include <string>
# include "IHeuristic.hpp"

class CreateHeuristic {

public:
	static CreateHeuristic &getInstance();
	IHeuristic *createHeuristic(std::string name, unsigned short **finaleMap, size_t size);

private:
	CreateHeuristic();
	CreateHeuristic(CreateHeuristic const &src);
	~CreateHeuristic();

	CreateHeuristic &operator=(CreateHeuristic const &rhs);

	static CreateHeuristic _instance;
};

#endif
