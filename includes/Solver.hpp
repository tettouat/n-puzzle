#ifndef SOLVER_HPP
# define SOLVER_HPP

#if __linux__
# include <bsd/stdlib.h>
#endif
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <list>
#include "Node.hpp"
#include "NodeTool.hpp"
#include "IHeuristic.hpp"

typedef std::list<const Node*>	constNodes;

class Solver {

public:

	Solver();
	Solver(unsigned short **map, unsigned short **finalMap, int size, IHeuristic& heuristic);
	Solver(Solver const &src);
	~Solver();

	Solver			&operator=(Solver const &rhs);
	bool				solve(void);
	constNodes			buildPath(void) const;
	const Node&			lastNode(void);
	size_t				getTotalStates();
	size_t				getMaxStates();

	static unsigned short			**genMap(size_t size, size_t swaps);
	static unsigned short			**finalSolution(int size);
	static bool			isSolvable(unsigned short **map, int size);
	static unsigned short			**getSnakeForm(unsigned short **map, int size);

	static constNodes	buildMultiPath(const Solver& a, const Solver& b);

	static bool			eq_node(const Node* a, const Node* b);
	static size_t		hash_node(const Node* node);
	static bool			less_node(const Node* a, const Node* b);

	static bool			collide(const Solver& a, const Solver& b);

private:
	void				createNextNodes(int size, Node* topNode, NodeTool& pool);
	constNodes			buildPath(Node* node) const;

	typedef std::unordered_set<Node*, decltype(&Solver::hash_node), decltype(&Solver::eq_node)>	nodes_set;
	typedef std::priority_queue<Node*, std::vector<Node*>, decltype(&Solver::less_node)> node_queue;

	size_t		_size;
	NodeTool	_pool;
	node_queue	_openlist;
	nodes_set	_closelist;
	Node		_firstNode;
	Node		_finalNode;
	Node*		_lastNode;
	IHeuristic&	_heuristic;
	size_t		_totalStates;
	size_t		_maxStates;
	std::vector<Node*>	_nextNodes;
};

#endif
