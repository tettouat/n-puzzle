#ifndef IHEURISTIC_HPP
# define IHEURISTIC_HPP

class IHeuristic {
public:
	virtual int		distance(const unsigned short * const *map) const = 0;
};

#endif
