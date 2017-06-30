#ifndef MANHATTAN_HPP
# define MANHATTAN_HPP

# include "IHeuristic.hpp"
# include "Node.hpp"

class Manhattan : public IHeuristic {

public:
	Manhattan();
	Manhattan(Manhattan const &src);
	Manhattan(unsigned short **map_final, size_t size);
	~Manhattan();

	Manhattan &operator=(Manhattan const &rhs);
	virtual int	distance(const unsigned short * const *map) const;

protected:
	Node::Square	*map_pos;
	int				size;
};

#endif
